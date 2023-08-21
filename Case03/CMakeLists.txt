cmake_minimum_required(VERSION 3.22)
project(case03)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC_FILES src/*.cpp)
include_directories(include)
# OR 
# target_include_directories(case03 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(case03 app/main.cpp ${SRC_FILES})

