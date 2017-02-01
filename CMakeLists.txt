cmake_minimum_required(VERSION 3.2)
project (wnutils)

add_definitions(-std=c++11)
add_definitions(-Wall)

set(SOURCES
  main.cpp
)

set(HEADERS
  WNUtils.h
)

add_executable(
  wnutils
  ${SOURCES}
  ${HEADERS}
)

target_include_directories(
  wnutils SYSTEM
  PUBLIC /usr/local/include
)

target_link_libraries(
  wnutils
  /usr/local/lib/libglog.a
  /usr/local/lib/libgflags.a
)

