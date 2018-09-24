cmake_minimum_required(VERSION 3.12.1)
set(CMAKE_BUILD_TYPE Debug)

# Project information
project(my_project)
set(VERION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Environment Information
include_directories(${PROJECT_SOURCE_DIR}/inc)
#link_directories(${PROJECT_SOURCE_DIR}/external/lib)
add_executable(my_project ${PROJECT_SOURCE_DIR}/src/main.cpp)
