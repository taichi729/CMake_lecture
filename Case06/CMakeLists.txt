cmake_minimum_required(VERSION 3.22)
project(case05)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC_FILES src/*.cpp)

find_package(OpenMP REQUIRED)

file(GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp)
 # foreach loop (sourcefile:APP_SOURCES)
 foreach(sourcefile ${APP_SOURCES})
    #take the sourcefile and find the last slash in the string
     string(FIND "${sourcefile}" "/" slash_index REVERSE)
     string(SUBSTRING "${sourcefile}" "${slash_index}" -1 appname)
     string(REPLACE "/" "" appname ${appname})
     string(REPLACE ".cpp" "" appname ${appname})

     add_executable(${appname} ${sourcefile} ${SRC_FILES})
     target_include_directories(${appname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
     target_link_libraries( ${appname} PRIVATE OpenMP::OpenMP_CXX)
 endforeach(sourcefile ${APP_SOURCES} )