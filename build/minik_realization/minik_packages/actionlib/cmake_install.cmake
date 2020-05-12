# Install script for directory: /home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib

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
  include("/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/safe_execute_install.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/action" TYPE FILE FILES
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib/action/Test.action"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib/action/TestRequest.action"
    "/home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib/action/TwoInts.action"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/msg" TYPE FILE FILES
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestAction.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestActionGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestActionResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestActionFeedback.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/msg" TYPE FILE FILES
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestAction.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestActionGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestActionResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestActionFeedback.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TestRequestFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/msg" TYPE FILE FILES
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsAction.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsActionGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsActionResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsActionFeedback.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsGoal.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsResult.msg"
    "/home/berkay/catkin_ws/devel/share/actionlib/msg/TwoIntsFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/cmake" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/actionlib-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/include/actionlib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/roseus/ros/actionlib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/common-lisp/ros/actionlib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/share/gennodejs/ros/actionlib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/actionlib")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/actionlib" REGEX "/\\_\\_init\\_\\_\\.py$" EXCLUDE REGEX "/\\_\\_init\\_\\_\\.pyc$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/actionlib" FILES_MATCHING REGEX "/home/berkay/catkin_ws/devel/lib/python2.7/dist-packages/actionlib/.+/__init__.pyc?$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/actionlib.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/cmake" TYPE FILE FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/actionlib-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib/cmake" TYPE FILE FILES
    "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/actionlibConfig.cmake"
    "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/actionlibConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/actionlib" TYPE FILE FILES "/home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/actionlib" TYPE PROGRAM FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/axclient.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/actionlib" TYPE PROGRAM FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/axserver.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/actionlib" TYPE PROGRAM FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/dynamic_action.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/actionlib" TYPE PROGRAM FILES "/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/catkin_generated/installspace/library.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/berkay/catkin_ws/devel/lib/libactionlib.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so"
         OLD_RPATH "/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libactionlib.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/actionlib" TYPE DIRECTORY FILES "/home/berkay/catkin_ws/src/minik_realization/minik_packages/actionlib/include/actionlib/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/berkay/catkin_ws/build/minik_realization/minik_packages/actionlib/test/cmake_install.cmake")

endif()

