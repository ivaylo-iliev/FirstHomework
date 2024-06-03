# Add include directory for Util
include_directories(${CMAKE_SOURCE_DIR}/helpers)

add_library(Menu Menu.cpp)
add_library(Circle Circle.cpp)
add_library(Point Point.cpp)
add_library(LineByPointAndAngle LineByPointAndAngle.cpp)
add_library(Matrix Matrix.cpp)
add_library(MenuEntry MenuEntry.cpp)

target_include_directories(Menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Circle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Point PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(LineByPointAndAngle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(MenuEntry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Menu MenuEntry)
