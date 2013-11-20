cmake_minimum_required (VERSION 2.6)
project (MB_Framework)

#enable c++11
ADD_DEFINITIONS(
    -std=c++0x # Or -std=c++11
#    # Other flags
)

#default includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_library(${PROJECT_NAME} SHARED  ${SOURCE})