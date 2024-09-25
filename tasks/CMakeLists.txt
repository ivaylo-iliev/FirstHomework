# Add include directory for Menu
include_directories(${CMAKE_SOURCE_DIR}/objects)
include_directories(${CMAKE_SOURCE_DIR}/helpers)

# Create the Task library and link it against the Menu library
add_library(Task Task.cpp)
target_link_libraries(Task Menu)
target_link_libraries(Task Util)
target_include_directories(Task PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create libraries for the specific task implementations and link them against the Task library
add_library(Task1 Task1.cpp)
target_link_libraries(Task1 Task)
target_include_directories(Task1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task2 Task2.cpp)
target_link_libraries(Task2 Task)
target_include_directories(Task2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task3 Task3.cpp)
target_link_libraries(Task3 Task Matrix)
target_include_directories(Task3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task4 Task4.cpp)
target_link_libraries(Task4 Task LineByPointAndAngle)
target_include_directories(Task4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task5 Task5.cpp)
target_link_libraries(Task5 Task SimpleFraction)
target_include_directories(Task5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task6 Task6.cpp)
target_link_libraries(Task6 Task PointInSpace)
target_include_directories(Task6 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task7 Task7.cpp)
target_link_libraries(Task7 Task Point)
target_include_directories(Task7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Task8 Task8.cpp)
target_link_libraries(Task8 Task Force)
target_include_directories(Task8 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})