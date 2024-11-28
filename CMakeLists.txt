cmake_minimum_required(VERSION 3.30.0)
project(FirstHomework VERSION 0.1.0 LANGUAGES C CXX)

#if (MSVC)
#    set(CMAKE_REQUIRED_FLAGS /std:c++20)
#else()
#    set(CMAKE_REQUIRED_FLAGS -std=c++20)
#endif()

set (CMAKE_CXX_STANDARD 20)

# Project name
project(FirstHomework)

set(BUILD_TESTING OFF)

include(FetchContent)

# Faker is used to generate real looking test data
FetchContent_Declare(faker
	GIT_REPOSITORY https://github.com/cieslarmichal/faker-cxx.git
	GIT_TAG main
)

FetchContent_MakeAvailable(faker)

# Add subdirectories
add_subdirectory(objects)
add_subdirectory(tasks)
add_subdirectory(helpers)

# Add the executable
add_executable(FirstHomework FirstHomework.cpp)

# Link the libraries
target_link_libraries(FirstHomework faker-cxx Menu Circle Task Task1 Task2 Task3 Task4 Task5 Task6 Task7 Task8 Task9 Task10 Util)

# Copy the task definitions to the build folder
add_custom_command(
    TARGET FirstHomework  
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/TaskDefinitions.txt
        $<TARGET_FILE_DIR:FirstHomework>/TaskDefinitions.txt
)
