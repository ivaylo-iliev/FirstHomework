cmake_minimum_required(VERSION 3.10)

# Project name
project(FirstHomework)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(objects)
add_subdirectory(tasks)
add_subdirectory(helpers)

# Add the executable
add_executable(FirstHomework FirstHomework.cpp)

# Link the libraries
target_link_libraries(FirstHomework Menu Circle Task Task1 Task2 Task3 Task4 Task5 Task6 Task7 Task8 Util)
configure_file(${CMAKE_SOURCE_DIR}/TaskDefinitions.txt ${CMAKE_BINARY_DIR}/TaskDefinitions.txt COPYONLY)
