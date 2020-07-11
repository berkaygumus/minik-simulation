#include "camera_calibration/camera_calibration.h"
#include <opencv2/core/utility.hpp>

using namespace cv;
using namespace std;


#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>


extern std::string getCurrentWorkingDir();

//std::string getCurrentWorkingDir() {
//    char buff[FILENAME_MAX];
//    GetCurrentDir( buff, FILENAME_MAX );
//    std::string current_working_dir(buff);
//    return current_working_dir;
//}

static inline void read(const FileNode& node, Settings& x, const Settings&  default_value = Settings())
{
    if(node.empty())
        x = default_value;
    else
        x.read(node);
}


int Camera_Calibration::print_help()
{
    cout <<
            " Given a list of chessboard images, the number of corners (nx, ny)\n"
            " on the chessboards, and a flag: useCalibrated for \n"
            "   calibrated (0) or\n"
            "   uncalibrated \n"
            "     (1: use stereoCalibrate(), 2: compute fundamental\n"
            "         matrix separately) stereo. \n"
            " Calibrate the cameras and display the\n"
            " rectified results along with the computed disparity images.   \n" << endl;
    cout << "Usage:\n ./stereo_calib -w=<board_width default=9> -h=<board_height default=6> -s=<square_size default=1.0> <image list XML/YML file default=stereo_calib.xml>\n" << endl;
    return 0;
}


void  Camera_Calibration::StereoCalib(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners = false, bool useCalibrated=true, bool showRectified=true)
{
    if( imagelist.size() % 2 != 0 )
    {
        cout << "Error: the image list contains odd (non-even) number of elements\n";
        return;
    }

    const int maxScale = 2;
    // ARRAY AND VECTOR STORAGE:

    vector<vector<Point2f> > imagePoints[2];
    vector<vector<Point3f> > objectPoints;
    Size imageSize;

    int i, j, k, nimages = (int)imagelist.size()/2;

    imagePoints[0].resize(nimages);
    imagePoints[1].resize(nimages);
    vector<string> goodImageList;

    for( i = j = 0; i < nimages; i++ )
    {
        for( k = 0; k < 2; k++ )
        {
            //const string& filename = imagelist[i*2+k];
            string filename = imagelist[i*2+k];

            filename = getCurrentWorkingDir()+ CalibrationInputImageFilesFolderPath+filename;
            Mat img = imread(filename, 0);
            if(img.empty())
                break;
            if( imageSize == Size() )
                imageSize = img.size();
            else if( img.size() != imageSize )
            {
                cout << "The image " << filename << " has the size different from the first image size. Skipping the pair\n";
                break;
            }
            bool found = false;
            vector<Point2f>& corners = imagePoints[k][j];
            for( int scale = 1; scale <= maxScale; scale++ )
            {
                Mat timg;
                if( scale == 1 )
                    timg = img;
                else
                    resize(img, timg, Size(), scale, scale, INTER_LINEAR_EXACT);
                found = findChessboardCorners(timg, boardSize, corners,
                    CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);
                if( found )
                {
                    if( scale > 1 )
                    {
                        Mat cornersMat(corners);
                        cornersMat *= 1./scale;
                    }
                    break;
                }
            }
            if( displayCorners )
            {
                cout << filename << endl;
                Mat cimg, cimg1;
                cvtColor(img, cimg, COLOR_GRAY2BGR);
                drawChessboardCorners(cimg, boardSize, corners, found);
                double sf = 640./MAX(img.rows, img.cols);
                resize(cimg, cimg1, Size(), sf, sf, INTER_LINEAR_EXACT);
                imshow("corners", cimg1);
                char c = (char)waitKey(500);
                if( c == 27 || c == 'q' || c == 'Q' ) //Allow ESC to quit
                    exit(-1);
            }
            else
                putchar('.');
            if( !found )
                break;
            cornerSubPix(img, corners, Size(11,11), Size(-1,-1),
                         TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                                      30, 0.01));
        }
        if( k == 2 )
        {
            goodImageList.push_back(imagelist[i*2]);
            goodImageList.push_back(imagelist[i*2+1]);
            j++;
        }
    }
    cout << j << " pairs have been successfully detected.\n";
    nimages = j;
    if( nimages < 2 )
    {
        cout << "Error: too little pairs to run the calibration\n";
        return;
    }

    imagePoints[0].resize(nimages);
    imagePoints[1].resize(nimages);
    objectPoints.resize(nimages);

    for( i = 0; i < nimages; i++ )
    {
        for( j = 0; j < boardSize.height; j++ )
            for( k = 0; k < boardSize.width; k++ )
                objectPoints[i].push_back(Point3f(k*squareSize, j*squareSize, 0));
    }

    cout << "Running stereo calibration ...\n";

    Mat cameraMatrix[2], distCoeffs[2];
    cameraMatrix[0] = initCameraMatrix2D(objectPoints,imagePoints[0],imageSize,0);
    cameraMatrix[1] = initCameraMatrix2D(objectPoints,imagePoints[1],imageSize,0);
    Mat R, T, E, F;

    double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
                    cameraMatrix[0], distCoeffs[0],
                    cameraMatrix[1], distCoeffs[1],
                    imageSize, R, T, E, F,
                    CALIB_FIX_ASPECT_RATIO +
                    CALIB_ZERO_TANGENT_DIST +
                    CALIB_USE_INTRINSIC_GUESS +
                    CALIB_SAME_FOCAL_LENGTH +
                    CALIB_RATIONAL_MODEL +
                    CALIB_FIX_K3 + CALIB_FIX_K4 + CALIB_FIX_K5,
                    TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, 1e-5) );
    cout << "done with RMS error=" << rms << endl;

// CALIBRATION QUALITY CHECK
// because the output fundamental matrix implicitly
// includes all the output information,
// we can check the quality of calibration using the
// epipolar geometry constraint: m2^t*F*m1=0
    double err = 0;
    int npoints = 0;
    vector<Vec3f> lines[2];
    for( i = 0; i < nimages; i++ )
    {
        int npt = (int)imagePoints[0][i].size();
        Mat imgpt[2];
        for( k = 0; k < 2; k++ )
        {
            imgpt[k] = Mat(imagePoints[k][i]);
            undistortPoints(imgpt[k], imgpt[k], cameraMatrix[k], distCoeffs[k], Mat(), cameraMatrix[k]);
            computeCorrespondEpilines(imgpt[k], k+1, F, lines[k]);
        }
        for( j = 0; j < npt; j++ )
        {
            double errij = fabs(imagePoints[0][i][j].x*lines[1][j][0] +
                                imagePoints[0][i][j].y*lines[1][j][1] + lines[1][j][2]) +
                           fabs(imagePoints[1][i][j].x*lines[0][j][0] +
                                imagePoints[1][i][j].y*lines[0][j][1] + lines[0][j][2]);
            err += errij;
        }
        npoints += npt;
    }
    cout << "average epipolar err = " <<  err/npoints << endl;

    // save intrinsic parameters

    string path = getCurrentWorkingDir()+CalibrationFilesFolderPath;
    FileStorage fs(path+"intrinsics.yml", FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "M1" << cameraMatrix[0] << "D1" << distCoeffs[0] <<
              "M2" << cameraMatrix[1] << "D2" << distCoeffs[1];
        fs.release();
    }
    else
        cout << "Error: can not save the intrinsic parameters\n";

    Mat R1, R2, P1, P2, Q;
    Rect validRoi[2];

    stereoRectify(cameraMatrix[0], distCoeffs[0],
                  cameraMatrix[1], distCoeffs[1],
                  imageSize, R, T, R1, R2, P1, P2, Q,
                  0, 1, imageSize, &validRoi[0], &validRoi[1]);
    cout<< "ROI:";
    cout << validRoi[0]<< endl;

    fs.open(path+"extrinsics.yml", FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
        fs.release();
    }
    else
        cout << "Error: can not save the extrinsic parameters\n";

    // OpenCV can handle left-right
    // or up-down camera arrangements
    isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));

// COMPUTE AND DISPLAY RECTIFICATION
    if( !showRectified )
        return;


    initUndistortRectifyMap(cameraMatrix[0],distCoeffs[0],R1,P1,imageSize,CV_32FC1, map1x,map1y);
    initUndistortRectifyMap(cameraMatrix[1],distCoeffs[1],R2,P2,imageSize,CV_32FC1, map2x,map2y);

    Mat rmap[2][2];

    rmap[0][0] = map1x;  rmap[0][1] = map1y;
    rmap[1][0] = map2x;  rmap[1][1] = map2y;


// IF BY CALIBRATED (BOUGUET'S METHOD)
//    if( useCalibrated )
//    {
//        // we already computed everything
//    }
//  // OR ELSE HARTLEY'S METHOD
//    else
// // use intrinsic parameters of each camera, but
// // compute the rectification transformation directly
// // from the fundamental matrix
//    {
//        vector<Point2f> allimgpt[2];
//        for( k = 0; k < 2; k++ )
//        {
//            for( i = 0; i < nimages; i++ )
//                std::copy(imagePoints[k][i].begin(), imagePoints[k][i].end(), back_inserter(allimgpt[k]));
//        }
//        F = findFundamentalMat(Mat(allimgpt[0]), Mat(allimgpt[1]), FM_8POINT, 0, 0);
//        Mat H1, H2;
//        stereoRectifyUncalibrated(Mat(allimgpt[0]), Mat(allimgpt[1]), F, imageSize, H1, H2, 3);

//        R1 = cameraMatrix[0].inv()*H1*cameraMatrix[0];
//        R2 = cameraMatrix[1].inv()*H2*cameraMatrix[1];
//        P1 = cameraMatrix[0];
//        P2 = cameraMatrix[1];
//    }


    Mat canvas;
    double sf;
    int w, h;
    if( !isVerticalStereo )
    {
        sf = 600./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h, w*2, CV_8UC3);
    }
    else
    {
        sf = 300./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h*2, w, CV_8UC3);
    }

    for( i = 0; i < nimages; i++ )
    {
        for( k = 0; k < 2; k++ )
        {
            string imagefile = getCurrentWorkingDir()+  CalibrationInputImageFilesFolderPath + goodImageList[i*2+k];
            Mat img = imread(imagefile, 0), rimg, cimg;
            remap(img, rimg, rmap[k][0], rmap[k][1], INTER_LINEAR);
            cvtColor(rimg, cimg, COLOR_GRAY2BGR);
            Mat canvasPart = !isVerticalStereo ? canvas(Rect(w*k, 0, w, h)) : canvas(Rect(0, h*k, w, h));
            resize(cimg, canvasPart, canvasPart.size(), 0, 0, INTER_AREA);
            if( useCalibrated )
            {
                Rect vroi(cvRound(validRoi[k].x*sf), cvRound(validRoi[k].y*sf),
                          cvRound(validRoi[k].width*sf), cvRound(validRoi[k].height*sf));
                rectangle(canvasPart, vroi, Scalar(0,0,255), 3, 8);
            }
        }

        if( !isVerticalStereo )
            for( j = 0; j < canvas.rows; j += 16 )
                line(canvas, Point(0, j), Point(canvas.cols, j), Scalar(0, 255, 0), 1, 8);
        else
            for( j = 0; j < canvas.cols; j += 16 )
                line(canvas, Point(j, 0), Point(j, canvas.rows), Scalar(0, 255, 0), 1, 8);
        imshow("rectified", canvas);
        char c = (char)waitKey();
        if( c == 27 || c == 'q' || c == 'Q' )
            break;
    }
}

//////////////////////////////fisheye

void  Camera_Calibration::StereoCalib2(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners = true, bool useCalibrated=true, bool showRectified=true)
{
    if( imagelist.size() % 2 != 0 )
    {
        cout << "Error: the image list contains odd (non-even) number of elements\n";
        return;
    }

    const int maxScale = 2;
    // ARRAY AND VECTOR STORAGE:

    vector<vector<Point2f> > floatImagePoints[2]; //float image points
    vector< vector< Point2d > > doubleImagePoints[2]; //double image points
    vector<vector<Point3d> > doubleObjectPoints; //double object points
    vector<vector<Point3f> > floatObjectPoints; //float object points
    Size imageSize;

    int i, j, k, nimages = (int)imagelist.size()/2;

    floatImagePoints[0].resize(nimages);
    floatImagePoints[1].resize(nimages);


    vector<string> goodImageList;

    for( i = j = 0; i < nimages; i++ ){
        for( k = 0; k < 2; k++ ){

            string filename = imagelist[i*2+k];

            filename = getCurrentWorkingDir()+ CalibrationInputImageFilesFolderPath+filename;
            Mat img = imread(filename, 0);
            if(img.empty())
                break;
            if( imageSize == Size() )
                imageSize = img.size();
            else if( img.size() != imageSize )
            {
                cout << "The image " << filename << " has the size different from the first image size. Skipping the pair\n";
                break;
            }
            bool found = false;
            vector<Point2f>& corners = floatImagePoints[k][j];

            for( int scale = 1; scale <= maxScale; scale++ ){

                Mat timg;
                if( scale == 1 )
                    timg = img;
                else
                    resize(img, timg, Size(), scale, scale, INTER_LINEAR_EXACT);
                found = findChessboardCorners(timg, boardSize, corners,
                    CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);
                if( found ){
                    if( scale > 1 ){

                        Mat cornersMat(corners);
                        cornersMat *= 1./scale;
                    }
                    break;
                }
            }

        if( displayCorners ){

                cout << filename << endl;
                Mat cimg, cimg1;
                cvtColor(img, cimg, COLOR_GRAY2BGR);
                drawChessboardCorners(cimg, boardSize, corners, found);
                double sf = 640./MAX(img.rows, img.cols);
                resize(cimg, cimg1, Size(), sf, sf, INTER_LINEAR_EXACT);
                imshow("corners", cimg1);
                char c = (char)waitKey(500);
                if( c == 27 || c == 'q' || c == 'Q' ) //Allow ESC to quit
                    exit(-1);
            }
            else
                putchar('.');
            if( !found )
                break;
            cornerSubPix(img, corners, Size(11,11), Size(-1,-1),
                         TermCriteria(TermCriteria::COUNT+TermCriteria::EPS,
                                      30, 0.01));
        }
        if( k == 2 )
        {
            goodImageList.push_back(imagelist[i*2]);
            goodImageList.push_back(imagelist[i*2+1]);
            j++;

        }
    }


    for (int i = 0; i < floatImagePoints[0].size(); i++) {
      vector< Point2d > v1, v2;
      for (int h = 0; h < floatImagePoints[0][0].size();h++) {
        v1.push_back(Point2d((double)floatImagePoints[0][i][h].x, (double)floatImagePoints[0][i][h].y));
        v2.push_back(Point2d((double)floatImagePoints[1][i][h].x, (double)floatImagePoints[1][i][h].y));

      }
            doubleImagePoints[0].push_back(v1);
            doubleImagePoints[1].push_back(v2);
    }

    cout << j << " pairs have been successfully detected.\n";
    nimages = j;
    if( nimages < 2 )
    {
        cout << "Error: too little pairs to run the calibration\n";
        return;
    }

    floatImagePoints[0].resize(nimages);
    floatImagePoints[1].resize(nimages);
    doubleObjectPoints.resize(nimages);
    floatObjectPoints.resize(nimages);


    for( i = 0; i < nimages; i++ ){
        for( j = 0; j < boardSize.height; j++ ){
            for( k = 0; k < boardSize.width; k++ ){

              doubleObjectPoints[i].push_back(Point3d(double((float)k*squareSize), double((float)j*squareSize), 0));
              floatObjectPoints[i].push_back(Point3f(k*squareSize, j*squareSize, 0));

            }
        }
   }

cout << nimages << endl;
    cout << "Running stereo calibration ...\n";

////////////////////////////////////////////////////////////////////////////////////////

Mat cameraMatrix[2], distCoeffs[2];
Mat _rvecs, _tvecs,R, T;

double rms2 = fisheye::stereoCalibrate(doubleObjectPoints, doubleImagePoints[0], doubleImagePoints[1],
                                        cameraMatrix[0], distCoeffs[0],
                                        cameraMatrix[1], distCoeffs[1],
                                        imageSize, R, T,
                                        cv::fisheye::CALIB_RECOMPUTE_EXTRINSIC+
                                        //fisheye::CALIB_USE_INTRINSIC_GUESS+
                                        cv::fisheye::CALIB_CHECK_COND+
                                        cv::fisheye::CALIB_FIX_SKEW+
                                        fisheye::CALIB_FIX_K4+
                                        fisheye::CALIB_FIX_K3+
                                        fisheye::CALIB_FIX_K2+
                                        fisheye::CALIB_FIX_K1,
                                        TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, DBL_EPSILON));


    // save intrinsic parameters

    string path = getCurrentWorkingDir()+CalibrationFilesFolderPath;
    FileStorage fs(path+"intrinsics.yml", FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "M1" << cameraMatrix[0] << "D1" << distCoeffs[0] <<
              "M2" << cameraMatrix[1] << "D2" << distCoeffs[1];
        fs.release();
    }
    else
        cout << "Error: can not save the intrinsic parameters\n";

    Mat R1, R2, P1, P2, Q;
    Rect validRoi[2];

    fisheye::stereoRectify(cameraMatrix[0], distCoeffs[0],
                  cameraMatrix[1], distCoeffs[1],
                  imageSize, R, T, R1, R2, P1, P2, Q,
                   CV_CALIB_ZERO_DISPARITY,imageSize,0,1.0);

    fs.open(path+"extrinsics.yml", FileStorage::WRITE);
    if( fs.isOpened() )
    {
        fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
        fs.release();
    }
    else
        cout << "Error: can not save the extrinsic parameters\n";

    // OpenCV can handle left-right
    // or up-down camera arrangements
    isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));

// COMPUTE AND DISPLAY RECTIFICATION
    if( !showRectified )
        return;




    fisheye::initUndistortRectifyMap(cameraMatrix[0],distCoeffs[0],R1,P1,imageSize,CV_32FC1, map1x,map1y);
    fisheye::initUndistortRectifyMap(cameraMatrix[1],distCoeffs[1],R2,P2,imageSize,CV_32FC1, map2x,map2y);

    Mat rmap[2][2];

    rmap[0][0] = map1x;  rmap[0][1] = map1y;
    rmap[1][0] = map2x;  rmap[1][1] = map2y;
/*

        string imagefilel = getCurrentWorkingDir()+  CalibrationInputImageFilesFolderPath + goodImageList[0];
        Mat imgl = imread(imagefilel, 0), rimgl, cimgl;
        remap(imgl, rimgl, rmap[0][0], rmap[0][1], INTER_LINEAR);
        imshow("rimgl", rimgl);

        string imagefiler = getCurrentWorkingDir()+  CalibrationInputImageFilesFolderPath + goodImageList[1];
        Mat imgr = imread(imagefiler, 0), rimgr, cimgr;
        remap(imgr, rimgr, rmap[1][0], rmap[1][1], INTER_LINEAR);
        imshow("rimgr", rimgr);
*/

    Mat canvas;
    double sf;
    int w, h;
    if( !isVerticalStereo )
    {
        sf = 600./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h, w*2, CV_8UC3);
    }
    else
    {
        sf = 300./MAX(imageSize.width, imageSize.height);
        w = cvRound(imageSize.width*sf);
        h = cvRound(imageSize.height*sf);
        canvas.create(h*2, w, CV_8UC3);
    }





    for( i = 0; i < nimages; i++ )
    {
        for( k = 0; k < 2; k++ )
        {
            string imagefile = getCurrentWorkingDir()+  CalibrationInputImageFilesFolderPath + goodImageList[i*2+k];
            Mat img = imread(imagefile, 0), rimg, cimg;
            remap(img, rimg, rmap[k][0], rmap[k][1], INTER_LINEAR);
            cvtColor(rimg, cimg, COLOR_GRAY2BGR);
            Mat canvasPart = !isVerticalStereo ? canvas(Rect(w*k, 0, w, h)) : canvas(Rect(0, h*k, w, h));
            resize(cimg, canvasPart, canvasPart.size(), 0, 0, INTER_AREA);
            /*if( useCalibrated )
            {
                Rect vroi(cvRound(validRoi[k].x*sf), cvRound(validRoi[k].y*sf),
                          cvRound(validRoi[k].width*sf), cvRound(validRoi[k].height*sf));
                rectangle(canvasPart, vroi, Scalar(0,0,255), 3, 8);
            }*/
        }

        if( !isVerticalStereo )
            for( j = 0; j < canvas.rows; j += 16 )
                line(canvas, Point(0, j), Point(canvas.cols, j), Scalar(0, 255, 0), 1, 8);
        else
            for( j = 0; j < canvas.cols; j += 16 )
                line(canvas, Point(j, 0), Point(j, canvas.rows), Scalar(0, 255, 0), 1, 8);
        imshow("rectified fisheye", canvas);
        char c = (char)waitKey();
        if( c == 27 || c == 'q' || c == 'Q' )
            break;
    }
}



bool Camera_Calibration::readStringList( const string& filename, vector<string>& l )
{
    l.resize(0);
    FileStorage fs(filename, FileStorage::READ);
    if( !fs.isOpened() )
        return false;
    FileNode n = fs.getFirstTopLevelNode();
    if( n.type() != FileNode::SEQ )
        return false;
    FileNodeIterator it = n.begin(), it_end = n.end();
    for( ; it != it_end; ++it )
        l.push_back((string)*it);
    return true;
}



int Camera_Calibration::stereoCalibrateMain(int argc, char** argv)
{/*
    Size boardSize;
    string imagelistfn;
    bool showRectified;
    cv::CommandLineParser parser(argc, argv, "{w|9|}{h|6|}{s|1.0|}{nr||}{help||}{@input|stereo_calib.xml|}");
    if (parser.has("help"))
        return print_help();
    showRectified = !parser.has("nr");
    imagelistfn = samples::findFile(parser.get<string>("@input"));
    boardSize.width = parser.get<int>("w");
    boardSize.height = parser.get<int>("h");
    float squareSize = parser.get<float>("s");
    if (!parser.check())
    {
        parser.printErrors();
        return 1;
    }
    vector<string> imagelist;
    bool ok = readStringList(imagelistfn, imagelist);
    if(!ok || imagelist.empty())
    {
        cout << "can not open " << imagelistfn << " or the string list is empty" << endl;
        return print_help();
    }

    StereoCalib(imagelist, boardSize, squareSize, false, true, showRectified);*/
    return 0;
}

int Camera_Calibration::runStereoCalibrationAndSave()
{

    Settings s;

    const string inputSettingsFile = getCurrentWorkingDir()+DefaultCalibConfFileName;
    FileStorage fs(inputSettingsFile, FileStorage::READ); // Read the settings
    if (!fs.isOpened())
    {
        cout << "Could not open the configuration file: \"" << inputSettingsFile << "\"" << endl;
        return -1;
    }
    fs["Settings"] >> s;
    fs.release();  // close Settings file
    s.validate(getCurrentWorkingDir()+ CalibrationFilesFolderPath);
    //! [file_read]

    //FileStorage fout("settings.yml", FileStorage::WRITE); // write config as YAML
    //fout << "Settings" << s;

    Size boardSize = s.boardSize;
    float squareSize = s.squareSize;

    string imagelistfn = getCurrentWorkingDir()+ StereoCalibInputImagesConfFile;
    bool showRectified = s.showUndistorsed;

    vector<string> imagelist = s.imageList;
    bool ok = readStringList(imagelistfn, imagelist);
    if(!ok || imagelist.empty())
    {
        cout << "can not open " << imagelistfn << " or the string list is empty" << endl;
        return print_help();
    }

    StereoCalib2(imagelist, boardSize, squareSize, true, true, showRectified);
    return 0;
}

/*
 *   This method loads the stereo calibration parameters
 *
 *
 */

void Camera_Calibration::loadStereoCalibrationParams(Size imgsize)
{

    string path = getCurrentWorkingDir()+ CalibrationFilesFolderPath;
    FileStorage fsi(path+"intrinsics.yml", FileStorage::READ);// Read the settings
    if (!fsi.isOpened())
    {
        cout << "Could not open the configuration file: \"" << path+"intrinsics.yml" << "\"" << endl;
        return;

    }


    Mat M1, D1, M2, D2;
    fsi["M1"] >> M1;
    fsi["M2"] >> M2;
    fsi["D1"] >> D1;
    fsi["D2"] >> D2;
    fsi.release();


    FileStorage fse(path+"extrinsics.yml", FileStorage::READ);// Read the settings
    if (!fse.isOpened())
    {
        cout << "Could not open the configuration file: \"" << path+"extrinsics.yml" << "\"" << endl;
        return;

    }

    Mat R, T, E, F;
    Mat P1, R1, P2, R2;

    fse["R"] >> R;
    fse["T"] >> T;
  //  fse["E"] >> E;
    //fse["F"] >> F;
    fse["P1"] >> P1;
    fse["P2"] >> P2;
    fse["R1"] >> R1;
    fse["R2"] >> R2;

    cout << "R1 load " << R1 <<  endl;
    cout << "M1 load " << M1 <<  endl;
    cout << "R1 load " << R1 <<  endl;
    cout << "M1 load " << M1 <<  endl;
    cout << "R1 load " << R1 <<  endl;
    cout << "M1 load " << M1 <<  endl;
    baselineVector = T ;
    cameraMatrix = P1;

    fse.release(); // close  file
    //! [file_read]

    //FileStorage fout("settings.yml", FileStorage::WRITE); // write config as YAML
    //fout << "Settings" << s;


    //! [show_results]
    fisheye::initUndistortRectifyMap(M1,D1,R1,P1,imgsize,CV_32FC1, map1x,map1y);
    fisheye::initUndistortRectifyMap(M2,D2,R2,P2,imgsize,CV_32FC1, map2x,map2y);

}


/*
 *   This method applies stereo calibration to the given pair of images.
 *   It assumes that the calibration matrices have been loaded.
 *
 */


void Camera_Calibration::applyStereoCalibration(Mat imgl, Mat imgr, Mat &imgU1, Mat &imgU2){


    remap(imgl,imgU1,map1x,map1y, INTER_LINEAR);//, BORDER_CONSTANT, Scalar());
    remap(imgr,imgU2,map2x,map2y, INTER_LINEAR);//, BORDER_CONSTANT, Scalar());



}




Mat Camera_Calibration::getCameraFocalLength(){
  return cameraMatrix;


}



Mat Camera_Calibration::getStereoCameraBaseline(){

    return baselineVector;

}
