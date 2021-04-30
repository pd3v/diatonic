cmake_minimum_required(VERSION 3.19.2)

set (CMAKE_CXX_STANDARD 17)

project(diatonic_demo VERSION 0.1)

set(LIBRARY_OUTPUT_NAME diatonic)

add_library(
  ${LIBRARY_OUTPUT_NAME}
  chords.h
  chords.cpp
  scales.h
  scales.cpp
  intervals.h
  intervals.cpp
)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_OUTPUT_NAME})
