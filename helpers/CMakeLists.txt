# Create a library for Util
include_directories(${CMAKE_SOURCE_DIR}/objects)

add_library(Util Util.cpp)

# Make the Util library include directory available
target_include_directories(Util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Util Circle Point)

