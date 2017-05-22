cmake_minimum_required(VERSION 2.8.7)

project(SuperProjetCPP)

add_definitions(-std=c++11)
add_subdirectory(ez-lib)

#include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*
        include/*
)

add_executable(app ${SRC})
target_link_libraries(app ez-lib)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentatio with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
