cmake_minimum_required (VERSION 3.9)

set(PROJECT_NAME sparse)
set(SOURCE_FILES ./src/sparse.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

project (${PROJECT_NAME})

include_directories("./src/formats")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
