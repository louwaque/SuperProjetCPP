cmake_minimum_required(VERSION 3.0)

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
