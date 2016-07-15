cmake_minimum_required(VERSION 3.0.2)
project(test-empty-template CXX)

# Travis Option ###############################################################
option(TRAVISCI "Run at Travis CI" OFF)
if (TRAVISCI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTRAVIS_CI")
endif()

# GTest package ###############################################################
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Libraries ###################################################################
find_library(POCO_FOUNDATION PocoFoundation)
find_library(POCO_UTIL PocoUtil)
find_library(POCO_JSON PocoJSON)
find_library(POCO_XML PocoXML)
find_library(POCO_DATA PocoData)
find_library(POCO_NET PocoNet)
set(Poco_LIBRARIES ${POCO_UTIL} ${POCO_JSON} ${POCO_XML} ${POCO_FOUNDATION})

# Applicaion files ############################################################
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Create Application ##########################################################
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} ${Poco_LIBRARIES} pthread)

# Create Test #################################################################
enable_testing()
add_custom_target(utest ${CMAKE_CTEST_COMMAND} -V)
add_test(NAME TestAll
        COMMAND ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_dependencies(utest ${PROJECT_NAME} ${PROJECT_DAEMON_NAME})
