cmake_minimum_required(VERSION 3.22)
project(case02)

set(CMAKE_CXX_STANDARD 20)

add_executable(case02 src/main.cpp src/case02.cpp)
include_directories(src)
# OR 
# target_include_directories(case02 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)