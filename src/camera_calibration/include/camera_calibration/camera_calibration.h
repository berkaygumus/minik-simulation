
/*
 ************************************************** */

#ifndef CAMERA_CALIBRATION
#define CAMERA_CALIBRATION


#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>


#include <camera_calibration/globaldefs.h>
#include <camera_calibration/settings.h>

using namespace cv;
using namespace std;

// Used in calibration
const cv::Scalar RED(0,0,255), GREEN(0,255,0);
const char ESC_KEY = 27;





class Camera_Calibration
{
public:

    enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };

    void help();



    bool runCalibrationAndSave(Settings& s, Size imageSize, Mat&  cameraMatrix, Mat& distCoeffs,
                               vector<vector<Point2f> > imagePoints, float grid_width, bool release_object);

    // Original main method
    int calibrateMain(int argc, char* argv[]);

    // Only the calibration part
    int calibrate();


    //
    void applyCalibration(Mat img);


    static double computeReprojectionErrors( const vector<vector<Point3f> >& objectPoints,
                                             const vector<vector<Point2f> >& imagePoints,
                                             const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                                             const Mat& cameraMatrix , const Mat& distCoeffs,
                                             vector<float>& perViewErrors, bool fisheye);


    static void calcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners,
                                         Settings::Pattern patternType /*= Settings::CHESSBOARD*/);

    static bool runCalibration( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
                                                    vector<vector<Point2f> > imagePoints, vector<Mat>& rvecs, vector<Mat>& tvecs,
                                                    vector<float>& reprojErrs,  double& totalAvgErr);

    static bool runCalibrationAndSave(Settings& s, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs,
                               vector<vector<Point2f> > imagePoints);

    // Print camera parameters to the output file
    static void saveCameraParams( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
                                  const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                                  const vector<float>& reprojErrs, const vector<vector<Point2f> >& imagePoints,
                                  double totalAvgErr );

    // Load settings from file
    Settings loadCameraSettingsFromFile(string inputSettingsFile);
    // Camera calibration parameters from the output file as specified in the settings
   Size loadCameraCalibrationParams();

    // Stereo calibration

    static int print_help();

    //static void  StereoCalib(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners = false, bool useCalibrated=true, bool showRectified=true);
    void  StereoCalib(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners, bool useCalibrated, bool showRectified);

    void  StereoCalib2(const vector<string>& imagelist, Size boardSize, float squareSize, bool displayCorners, bool useCalibrated, bool showRectified);


    static bool readStringList( const string& filename, vector<string>& l );

    int stereoCalibrateMain(int argc, char** argv);

    int runStereoCalibrationAndSave();

    void applyStereoCalibration(Mat imgl, Mat imgr, Mat &imgU1, Mat &imgU2);

    void loadStereoCalibrationParams(Size imgsize);

    Mat getCameraFocalLength();
    Mat getStereoCameraBaseline();

public:

     // Single camera coefficients;
    cv::Mat map1, map2;
    // Stereo calibration matrices
    cv::Mat map1x, map1y, map2x, map2y;

private:
    bool isVerticalStereo;
    Mat baselineVector;
    Mat cameraMatrix;

};
#endif // CAMERA_CALIBRATION
