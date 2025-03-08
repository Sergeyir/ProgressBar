cmake_minimum_required(VERSION 3.0...3.31.6 FATAL_ERROR)

project(CppTools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -pipe -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(PBar src/PBar.cpp)

# compiling examples only if the current project is not a subproject
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
   add_executable(test examples/test.cpp)
   add_executable(style examples/style.cpp)
   add_executable(possibilities examples/possibilities.cpp)
   add_executable(speed examples/speed.cpp)
   add_executable(handle_output examples/handle_output.cpp)
   add_executable(mt examples/mt.cpp)
   target_link_libraries(test PBar)
   target_link_libraries(style PBar)
   target_link_libraries(possibilities PBar)
   target_link_libraries(speed PBar)
   target_link_libraries(handle_output PBar)
   target_link_libraries(mt PBar)
endif()

