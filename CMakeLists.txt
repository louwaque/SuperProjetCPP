cmake_minimum_required(VERSION 3.8.2)

project(SuperProjetCPP)

set (CMAKE_CXX_STANDARD 17)

include_directories(SYSTEM .)
include_directories(SYSTEM super-ez-lib/core/include)
include_directories(SYSTEM super-ez-lib/graphics/include)
include_directories(SYSTEM super-ez-lib/widget/include)

add_subdirectory(ez-lib)
add_subdirectory(super-ez-lib)
add_subdirectory(doc)

include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*.cpp
)

add_executable(app ${SRC})
target_link_libraries(app super-ez-lib-widget)
