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
include tasks/CMakeFiles/Task2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/CMakeFiles/Task2.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/CMakeFiles/Task2.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/CMakeFiles/Task2.dir/flags.make

tasks/CMakeFiles/Task2.dir/Task2.cpp.o: tasks/CMakeFiles/Task2.dir/flags.make
tasks/CMakeFiles/Task2.dir/Task2.cpp.o: tasks/Task2.cpp
tasks/CMakeFiles/Task2.dir/Task2.cpp.o: tasks/CMakeFiles/Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ilievi/Projects/FirstHomework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/CMakeFiles/Task2.dir/Task2.cpp.o"
	cd /home/ilievi/Projects/FirstHomework/tasks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/CMakeFiles/Task2.dir/Task2.cpp.o -MF CMakeFiles/Task2.dir/Task2.cpp.o.d -o CMakeFiles/Task2.dir/Task2.cpp.o -c /home/ilievi/Projects/FirstHomework/tasks/Task2.cpp

tasks/CMakeFiles/Task2.dir/Task2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Task2.dir/Task2.cpp.i"
	cd /home/ilievi/Projects/FirstHomework/tasks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilievi/Projects/FirstHomework/tasks/Task2.cpp > CMakeFiles/Task2.dir/Task2.cpp.i

tasks/CMakeFiles/Task2.dir/Task2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Task2.dir/Task2.cpp.s"
	cd /home/ilievi/Projects/FirstHomework/tasks && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilievi/Projects/FirstHomework/tasks/Task2.cpp -o CMakeFiles/Task2.dir/Task2.cpp.s

# Object files for target Task2
Task2_OBJECTS = \
"CMakeFiles/Task2.dir/Task2.cpp.o"

# External object files for target Task2
Task2_EXTERNAL_OBJECTS =

tasks/libTask2.a: tasks/CMakeFiles/Task2.dir/Task2.cpp.o
tasks/libTask2.a: tasks/CMakeFiles/Task2.dir/build.make
tasks/libTask2.a: tasks/CMakeFiles/Task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ilievi/Projects/FirstHomework/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTask2.a"
	cd /home/ilievi/Projects/FirstHomework/tasks && $(CMAKE_COMMAND) -P CMakeFiles/Task2.dir/cmake_clean_target.cmake
	cd /home/ilievi/Projects/FirstHomework/tasks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/CMakeFiles/Task2.dir/build: tasks/libTask2.a
.PHONY : tasks/CMakeFiles/Task2.dir/build

tasks/CMakeFiles/Task2.dir/clean:
	cd /home/ilievi/Projects/FirstHomework/tasks && $(CMAKE_COMMAND) -P CMakeFiles/Task2.dir/cmake_clean.cmake
.PHONY : tasks/CMakeFiles/Task2.dir/clean

tasks/CMakeFiles/Task2.dir/depend:
	cd /home/ilievi/Projects/FirstHomework && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilievi/Projects/FirstHomework /home/ilievi/Projects/FirstHomework/tasks /home/ilievi/Projects/FirstHomework /home/ilievi/Projects/FirstHomework/tasks /home/ilievi/Projects/FirstHomework/tasks/CMakeFiles/Task2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tasks/CMakeFiles/Task2.dir/depend

