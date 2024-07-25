cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(LearnCPP VERSION 1.0
                  DESCRIPTION "Learning CPP"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(ch0)
add_subdirectory(ch1)
add_subdirectory(ch2)
add_subdirectory(ch3)
add_subdirectory(ch4)
add_subdirectory(ch5)