cmake_minimum_required(VERSION 2.8.7)

project(SuperProjetCPP)

add_definitions(-std=c++11)
add_subdirectory(ez-lib)
add_subdirectory(boost)

include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*.cpp
)
list(REMOVE_ITEM SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(app src/main.cpp ${SRC})
target_link_libraries(app ez-lib)

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)
foreach(testSrc ${TEST_SRCS})
        get_filename_component(testName ${testSrc} NAME_WE)
        add_executable(${testName} ${testSrc} ${SRC})
        target_link_libraries(${testName} boost_test_framework ez-lib)
        set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/testBin)
        add_test(NAME ${testName}
                 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
                 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${testName})
        add_dependencies(check ${testName})
endforeach(testSrc)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentatio with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
