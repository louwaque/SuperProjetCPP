project(SuperEZLibWidget)

include_directories(include)
file(
        GLOB_RECURSE
        SRC
        src/*.cpp
)

add_library(super-ez-lib-widget ${SRC})
target_link_libraries(super-ez-lib-widget super-ez-lib-graphics)

find_package(Boost 1.64.0 COMPONENTS signals unit_test_framework)
if(Boost_FOUND)
  include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

  enable_testing()
  add_definitions(-DBOOST_TEST_DYN_LINK)
  add_custom_target(check-widget COMMAND ${CMAKE_CTEST_COMMAND})
  file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)
  foreach(testSrc ${TEST_SRCS})
          get_filename_component(testName ${testSrc} NAME_WE)
          add_executable(${testName} ${testSrc} ${SRC})
          target_link_libraries(${testName} ${Boost_LIBRARIES} super-ez-lib-widget)
          set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/testBin)
          add_test(NAME ${testName}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${testName})
          add_dependencies(check-widget ${testName})
  endforeach(testSrc)
endif()
