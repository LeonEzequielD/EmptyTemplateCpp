cmake_minimum_required(VERSION 3.0.8)
project(EmptyTemplateCpp CXX)

include_directories(${CMAKE_SOURCE_DIR})

# Create Install #############################################################
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/_output)

# Include Conan.io ###########################################################
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Compiler flags ##############################################################
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -std=c++11 -pedantic -Wall -Wextra -Winit-self -Woverloaded-virtual -Werror -Wnon-virtual-dtor -Wcast-align -Wconversion -Wsign-conversion")

set(PROJECT_DAEMON_NAME empty_templated)

# Add sub directories #########################################################
add_subdirectory(src)

option(TESTS "Generate tests" ON)
if(TESTS)
    add_subdirectory(test)
endif()

