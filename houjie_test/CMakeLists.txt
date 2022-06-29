cmake_minimum_required(VERSION 3.0)
 
project(test)


set(OpenCV_DIR /home/guo/opencv-4.5.5/install/lib/cmake/opencv4)

find_package(OpenCV REQUIRED)
include_directories("${PROJECT_SOURCE_DIR}/test.h")
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(test test.cpp)

target_link_libraries(test ${OpenCV_LIBS})