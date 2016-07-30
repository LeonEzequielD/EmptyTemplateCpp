cmake_minimum_required(VERSION 3.0.2)
project(${PROJECT_DAEMON_NAME} CXX C)

# Boost Package ###############################################################
find_package(Boost REQUIRED regex log log_setup filesystem system thread)
include_directories(${Boost_INCLUDE_DIRS})

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
target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES} pthread)

# Config File #################################################################
set (CONFIG_FILES "${PROJECT_NAME}.json")

# Install #####################################################################
install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_SOURCE_DIR}/_output
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_EXECUTE WORLD_READ)

install(FILES config.json
        DESTINATION ${CMAKE_SOURCE_DIR}/_output/
        RENAME ${PROJECT_NAME}.json
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ)
