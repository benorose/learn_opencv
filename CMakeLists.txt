cmake_minimum_required(VERSION 3.10)
project(learn_opencv)

find_package(OpenCV REQUIRED)
add_executable(learn_opencv test/read.cpp)
target_link_libraries(learn_opencv ${OpenCV_LIBS})