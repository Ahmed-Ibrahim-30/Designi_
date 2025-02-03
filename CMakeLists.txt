cmake_minimum_required(VERSION 3.26)

project(Designi2)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories("${CMAKE_SOURCE_DIR}/Lib/include")

add_executable(Designi2 main.cpp)


find_package(Threads REQUIRED)
target_link_libraries(Designi2 PRIVATE Threads::Threads)

# Add executable
