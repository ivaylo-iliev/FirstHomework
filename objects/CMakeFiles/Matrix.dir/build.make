# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilievi/Projects/FirstHomework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilievi/Projects/FirstHomework

# Include any dependencies generated for this target.
include objects/CMakeFiles/Matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include objects/CMakeFiles/Matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include objects/CMakeFiles/Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include objects/CMakeFiles/Matrix.dir/flags.make

objects/CMakeFiles/Matrix.dir/Matrix.cpp.o: objects/CMakeFiles/Matrix.dir/flags.make
objects/CMakeFiles/Matrix.dir/Matrix.cpp.o: objects/Matrix.cpp
objects/CMakeFiles/Matrix.dir/Matrix.cpp.o: objects/CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ilievi/Projects/FirstHomework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object objects/CMakeFiles/Matrix.dir/Matrix.cpp.o"
	cd /home/ilievi/Projects/FirstHomework/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT objects/CMakeFiles/Matrix.dir/Matrix.cpp.o -MF CMakeFiles/Matrix.dir/Matrix.cpp.o.d -o CMakeFiles/Matrix.dir/Matrix.cpp.o -c /home/ilievi/Projects/FirstHomework/objects/Matrix.cpp

objects/CMakeFiles/Matrix.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/Matrix.cpp.i"
	cd /home/ilievi/Projects/FirstHomework/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilievi/Projects/FirstHomework/objects/Matrix.cpp > CMakeFiles/Matrix.dir/Matrix.cpp.i

objects/CMakeFiles/Matrix.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/Matrix.cpp.s"
	cd /home/ilievi/Projects/FirstHomework/objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilievi/Projects/FirstHomework/objects/Matrix.cpp -o CMakeFiles/Matrix.dir/Matrix.cpp.s

# Object files for target Matrix
Matrix_OBJECTS = \
"CMakeFiles/Matrix.dir/Matrix.cpp.o"

# External object files for target Matrix
Matrix_EXTERNAL_OBJECTS =

objects/libMatrix.a: objects/CMakeFiles/Matrix.dir/Matrix.cpp.o
objects/libMatrix.a: objects/CMakeFiles/Matrix.dir/build.make
objects/libMatrix.a: objects/CMakeFiles/Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ilievi/Projects/FirstHomework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMatrix.a"
	cd /home/ilievi/Projects/FirstHomework/objects && $(CMAKE_COMMAND) -P CMakeFiles/Matrix.dir/cmake_clean_target.cmake
	cd /home/ilievi/Projects/FirstHomework/objects && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
objects/CMakeFiles/Matrix.dir/build: objects/libMatrix.a
.PHONY : objects/CMakeFiles/Matrix.dir/build

objects/CMakeFiles/Matrix.dir/clean:
	cd /home/ilievi/Projects/FirstHomework/objects && $(CMAKE_COMMAND) -P CMakeFiles/Matrix.dir/cmake_clean.cmake
.PHONY : objects/CMakeFiles/Matrix.dir/clean

objects/CMakeFiles/Matrix.dir/depend:
	cd /home/ilievi/Projects/FirstHomework && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilievi/Projects/FirstHomework /home/ilievi/Projects/FirstHomework/objects /home/ilievi/Projects/FirstHomework /home/ilievi/Projects/FirstHomework/objects /home/ilievi/Projects/FirstHomework/objects/CMakeFiles/Matrix.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : objects/CMakeFiles/Matrix.dir/depend
