project(SuperEZLibCore)

include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*.cpp
)

add_library(super-ez-lib-core ${SRC})
target_link_libraries(super-ez-lib-core ez-lib)

find_package(Boost 1.64.0 REQUIRED COMPONENTS locale serialization unit_test_framework)

IF (Boost_FOUND)
  include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
  target_link_libraries(super-ez-lib-core ${Boost_LIBRARIES})
  message(${Boost_LIBRARIES})

  enable_testing()
  add_definitions(-DBOOST_TEST_DYN_LINK)
  add_custom_target(check-core COMMAND ${CMAKE_CTEST_COMMAND})
  file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)
  foreach(testSrc ${TEST_SRCS})
          get_filename_component(testName ${testSrc} NAME_WE)
          add_executable(${testName} ${testSrc} ${SRC})
          target_link_libraries(${testName} super-ez-lib-core)
          set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/testBin)
          add_test(NAME ${testName}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${testName})
          add_dependencies(check-core ${testName})
  endforeach(testSrc)
endif()
