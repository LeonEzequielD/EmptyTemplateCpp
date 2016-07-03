cmake_minimum_required(VERSION 3.0.8)
project(EmptyTemplateCpp CXX)

# Include Conan.io ###########################################################
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Compiler flags ##############################################################
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -std=c++11 -pedantic -Wall -Wshadow -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Werror")

add_executable(${PROJECT_NAME} main.cxx)

# Install #####################################################################
install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_SOURCE_DIR}/_output
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_EXECUTE WORLD_READ)

