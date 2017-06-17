project(EZLib)

add_library(ez-lib ez-draw++.cpp)

if (UNIX)
  find_package(X11 REQUIRED)
  if (X11_FOUND)
    include_directories(${X11_INCLUDE_DIRS})
    target_link_libraries(ez-lib ${X11_LIBRARIES})
  endif (X11_FOUND)
endif (UNIX)

if (WIN32)
  target_link_libraries(ez-lib gdi32 msimg32)
endif (WIN32)
