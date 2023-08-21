cmake_minimum_required(VERSION 3.22)
project(case07)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SOURCES src/*.cpp src/*.cc src/*.c)
file(GLOB HEADERS include/*.hpp)

 #lib作成
add_library(mylib SHARED ${SOURCES} ${HEADERS})
#外部のlibを使っている場合　link
# target_link_libraries(mylib PRIVATE <link>)
#Headerのinclude
target_include_directories(mylib PUBLIC include)

file(GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp)
 # foreach loop (sourcefile:APP_SOURCES)
 foreach(sourcefile ${APP_SOURCES})
    #take the sourcefile and find the last slash in the string
     string(FIND "${sourcefile}" "/" slash_index REVERSE)
     string(SUBSTRING "${sourcefile}" "${slash_index}" -1 appname)
     string(REPLACE "/" "" appname ${appname})
     string(REPLACE ".cpp" "" appname ${appname})

     add_executable(${appname} ${sourcefile} )
     target_include_directories(${appname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
     target_link_libraries( ${appname} PRIVATE mylib)
 endforeach(sourcefile ${APP_SOURCES} )