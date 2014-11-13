cmake_minimum_required (VERSION 2.6)
project (MB_Framework)


if(C++11 AND USE_C++11_SUPPORT)

else()
    SET(ICKE2063_MBFRAMEWORK_NO_CPP11 1)
endif()

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/MB_Framework_config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config/MB_Framework_config.h
)

#default includes
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/config"
    )