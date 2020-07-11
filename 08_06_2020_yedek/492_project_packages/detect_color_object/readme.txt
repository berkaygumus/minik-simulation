---------------------------------------detect_color_object package------------------------------------------

At this package, there are methods which calculates robot or object positions using their color properties.
Also, this package uses camera_calibration package as the library.

>>select_hsv_range.cpp
    The methods below use hsv ranges defined at detect_color_object/hsv_range.h. However, proper ranges may change depending the light or other factors.
    The ranges can be updated using this node.

>>color_object
    It detects objects with specific color such as green, yellow, purple defined at detect_color_object/hsv_range.h,
    calculates object positions and publishes them ("robot1, robot2", new robots can be added.)

>>color_id_object
    It detects objects with specific color combinations (color ID: top color and bottom color) defined at detect_color_object/robot_IDs.h,
    calculates object positions and publishes them ("robot_list") as a list. If the object is not at field of view, the result is -1 at the message published.
    Color ranges are defined at detect_color_object/hsv_range.h.
    The color IDs and the number of robot can be changed at detect_color_object/robot_IDs.h.

>>disparity
    It generates disparity image using stereo images and shows this image.

>> capture_images
    It takes 1 or 2 images from the camera and writes them the folder.
    The number of images(1 or 2) and file names to write must be defined properly at the code.

These nodes takes images from the camera or jpg files.
When "ısCamera" variable is 1, it takes image from the camera,
when it is 0, it takes from the jpg file defined with "input_img_name" variable.
These variables are at main function at cpp file.

---------------------executables-------------------------------------
1) select_hsv_range.cpp >> select_hsv_range_node
2) color_object.cpp >>  color_object_node
3) color_id_object.cpp >>  color_id_object_node
4) disparity.cpp >>  disparity_node
5) capture_images.cpp >> capture_images_node
