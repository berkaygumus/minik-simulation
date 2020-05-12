execute_process(COMMAND "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
