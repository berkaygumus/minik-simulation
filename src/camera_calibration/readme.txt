---------------------------------------camera_calibration package------------------------------------------
This package can be used at other packages as the calibration library.
>>#include "camera_calibration/camera_calibration.h"

-----------------------Camera_Calibration class---------------------------

At this class, there are mono camera and stereo camera calibration functions.

>>settings.h
    Settings class and its varibales are defined here.

>>globaldefs.h
    File names such as input folder, calibration folder and some global parameters are defined here.

>>default.xml
    Configuration file is default.xml.
    boardSize and Square_Size are related to chessboard used at the calibration process.
    Input is the file name where there are calibration image files.
    Calibrate_NrOfFrameToUse is the number of image pairs.
    There are flag parameters for the calibrations.

>>VID5.XML
    The image file names for the mono camera calibration.

>>stereo_calib.xml
    The image file names for the stereo camera calibration.

>>out_camera_data.xml
    the output file of mono camera calibration

>>intrinsic.yml and extrinsic.yml
    the output file of stereo camera calibration

Important functions of the class:

1)calibrate() //for mono camera
    It takes images from the folder, calibrates the camera and saves calibration parameters to the output file.

2)runStereoCalibrationAndSave() //for stereo camera
    It takes image pairs from the folder, calibrates the stereo camera and saves calibration parameters to the output file.

3)loadStereoCalibrationParams(Size imgsize) //for stereo camera
    It loads calibration parameters from the output file to be able to use at the stereo calibration.

4)applyStereoCalibration(Mat imgl, Mat imgr, Mat &imgU1, Mat &imgU2) //for stereo camera
    After loading calibration parameters, it makes stereo images undistorted.

    ---------------------executables-------------------------------------
    1) main.cpp >>  camera_calibration_node
      This is for function examples.
