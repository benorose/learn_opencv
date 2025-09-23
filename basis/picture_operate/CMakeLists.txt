cmake_minimum_required(VERSION 3.10)

project(picture_operate)
find_package(OpenCV REQUIRED)
add_executable(picture_operate src/read&&write.cpp)
target_link_libraries(picture_operate ${OpenCV_LIBS})