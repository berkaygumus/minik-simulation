# Install script for directory: /home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/berkay/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/minik_ros_wrapper/msg" TYPE FILE FILES
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetPositionMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetVelocityMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetPIDPositionMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetPIDVelocityMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetLedMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetPositionMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetVelocityMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetPIDPositionMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetPIDVelocityMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetDistSensorMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetLineFollowerSensorMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetLedMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikGetButtonMsg.msg"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/msg/minikSetConfigMsg.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/minik_ros_wrapper/cmake" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/minik_ros_wrapper/catkin_generated/installspace/minik_ros_wrapper-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/include/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/roseus/ros/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/common-lisp/ros/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/gennodejs/ros/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/minik_ros_wrapper")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/minik_ros_wrapper/catkin_generated/installspace/minik_ros_wrapper.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/minik_ros_wrapper/cmake" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/minik_ros_wrapper/catkin_generated/installspace/minik_ros_wrapper-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/minik_ros_wrapper/cmake" TYPE FILE FILES
    "/home/berkay/catkin_ws/build/minik_realization/minik_packages/minik_ros_wrapper/catkin_generated/installspace/minik_ros_wrapperConfig.cmake"
    "/home/berkay/catkin_ws/build/minik_realization/minik_packages/minik_ros_wrapper/catkin_generated/installspace/minik_ros_wrapperConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/minik_ros_wrapper" TYPE FILE FILES "/home/berkay/catkin_ws/src/minik_realization/minik_packages/minik_ros_wrapper/package.xml")
endif()

