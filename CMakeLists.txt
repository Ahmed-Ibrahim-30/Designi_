cmake_minimum_required(VERSION 3.26)

project(Designi2)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories("E:/Library/vcpkg/installed/x64-windows/include")

# Add executable
add_executable(Designi2 main.cpp)