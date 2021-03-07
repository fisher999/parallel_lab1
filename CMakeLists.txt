cmake_minimum_required(VERSION 3.12)
project(openmptest CXX)

add_executable(sample main.cpp)

find_package(OpenMP REQUIRED)
target_link_libraries(sample PRIVATE OpenMP::OpenMP_CXX)