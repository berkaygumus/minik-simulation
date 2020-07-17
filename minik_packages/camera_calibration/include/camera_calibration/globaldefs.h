#ifndef GLOBALDEFS
#define GLOBALDEFS


// Not clear what these parameters are
#define LOOP_RATE 30
#define LOOP_RATE2 5


#define  ZTHRESHOLD 0.03
#define  XTHRESHOLD 0.07
#define  YTHRESHOLD 0.07
#define PI_DEG 180

// Path where calibration files are located
const std::string CalibrationFilesFolderPath  = "/src/camera_calibration/src/calib/";
const std::string CalibrationInputImageFilesFolderPath  = "/src/camera_calibration/src/calib/images/";
const std::string  DefaultCalibConfFileName =  "/src/camera_calibration/src/calib/default.xml";
const std::string  CameraCalibConfFileName =  "/src/camera_calibration/src/calib/out_camera_data.xml";
const std::string  StereoCalibInputImagesConfFile =  "/src/camera_calibration/src/calib/stereo_calib.xml";

// HLOW,SLOW,VLOW, HHIGH, SHIGH, VHIGH
// Robot colors
/*const int HSVCOLOR1_RANGE[6] ={7,69,86,28,255,255};//yellow //{30,72,78,68,189,255};//{20,46,81,70,189,255};//{32,59,37,82,254,255};//green {42,22,55,84,189,255};
const int HSVCOLOR2_RANGE[6] ={30,72,78,68,189,255};//green //{100,45,56,139,149,247};//{99,0,40,179,114,255};//{16,115,0,33,235,255};//yellow {93,41,167,146,158,255};//HSVCOLOR1_RANGE[6] ={0,22,55,8,189,255};
const int HSVCOLOR3_RANGE[6] = {103,0,108,140,110,183}; //{99,0,108,140,201,255};// {103,0,108,140,110,183}; //purple //{7,69,86,64,255,255};//{93,41,167,146,158,255};//blue {90,22,55,115,189,255};
const int HSVCOLOR4_RANGE[6] ={14,22,55,24,189,255};
const int HSVCOLOR5_RANGE[6] ={158,22,55,172,189,255};
*/


//float b=0.1;
//float f=2500; //320x240
//float f=400; //640x480

const float WEBCAM_PAN_FOV =  98;
const float WEBCAM_TILT_FOV = 40;
const int WEBCAM_FOV_WIDTH_PIXELS  = 640;
const int WEBCAM_FOV_HEIGHT_PIXELS = 480;
const float SAMPLING_FACTOR = 1;// 0.5;

const int MIN_COMPONENT_AREA_THRESHOLD = 60;



#endif // GLOBALDEFS
