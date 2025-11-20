cmake_minimum_required(VERSION 3.10)

project(StoreTUI VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the src directory to the include path
include_directories(src)

# Gather all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(StoreTUI ${SOURCES})
