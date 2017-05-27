cmake_minimum_required(VERSION 2.8.7)

project(SuperProjetCPP)

add_definitions(-std=c++11)

include_directories(SYSTEM .)
include_directories(SYSTEM super-ez-lib/core/include)
include_directories(SYSTEM super-ez-lib/graphics/include)
include_directories(SYSTEM super-ez-lib/widget/include)
add_subdirectory(ez-lib)
add_subdirectory(super-ez-lib)

include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*.cpp
)

add_executable(app ${SRC})
target_link_libraries(app super-ez-lib-widget)

find_package(Boost 1.64.0 COMPONENTS unit_test_framework)
if(Boost_FOUND)
  include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

  enable_testing()
  add_definitions(-DBOOST_TEST_DYN_LINK)
  add_custom_target(check-app COMMAND ${CMAKE_CTEST_COMMAND})
  file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)
  foreach(testSrc ${TEST_SRCS})
          get_filename_component(testName ${testSrc} NAME_WE)
          add_executable(${testName} ${testSrc} ${SRC})
          target_link_libraries(${testName} ${Boost_LIBRARIES} super-ez-lib-widget)
          set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/testBin)
          add_test(NAME ${testName}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${testName})
          add_dependencies(check-app ${testName})
  endforeach(testSrc)
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE @ONLY)
  add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/DOXYFILE WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentatio with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
