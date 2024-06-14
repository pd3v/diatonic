cmake_minimum_required(VERSION 3.19.2)

# Default as c++17 but also possible c++14
set (CMAKE_CXX_STANDARD 17)

project(diatonic)

set(LIBRARY_OUTPUT_NAME ${PROJECT_NAME})

add_library(
	${LIBRARY_OUTPUT_NAME} SHARED
  src/intervals.h
  src/intervals.cpp
  src/constexprArray.hpp
  src/scales.h
  src/scales.cpp
  src/chords.h
  src/chords.cpp
  src/tones.hpp
  src/phrases.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include/)

add_executable("${PROJECT_NAME}_demo" examples/main.cpp)
target_link_libraries("${PROJECT_NAME}_demo" PUBLIC ${LIBRARY_OUTPUT_NAME})

install(TARGETS ${PROJECT_NAME})
