cmake_minimum_required(VERSION 3.11)
project(function-interceptor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(demo)
add_subdirectory(hook)
