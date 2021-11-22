cmake_minimum_required(VERSION 3.12)
project(container)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -D_GLIBCXX_DEBUG)

add_executable(container main.cpp Resource.cpp)

