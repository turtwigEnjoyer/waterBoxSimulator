# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/nora/Projects/waterBoxSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nora/Projects/waterBoxSimulator/out/build

# Include any dependencies generated for this target.
include CMakeFiles/fluid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fluid.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fluid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fluid.dir/flags.make

CMakeFiles/fluid.dir/fluid.cpp.o: CMakeFiles/fluid.dir/flags.make
CMakeFiles/fluid.dir/fluid.cpp.o: /home/nora/Projects/waterBoxSimulator/fluid.cpp
CMakeFiles/fluid.dir/fluid.cpp.o: CMakeFiles/fluid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nora/Projects/waterBoxSimulator/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fluid.dir/fluid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fluid.dir/fluid.cpp.o -MF CMakeFiles/fluid.dir/fluid.cpp.o.d -o CMakeFiles/fluid.dir/fluid.cpp.o -c /home/nora/Projects/waterBoxSimulator/fluid.cpp

CMakeFiles/fluid.dir/fluid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fluid.dir/fluid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nora/Projects/waterBoxSimulator/fluid.cpp > CMakeFiles/fluid.dir/fluid.cpp.i

CMakeFiles/fluid.dir/fluid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fluid.dir/fluid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nora/Projects/waterBoxSimulator/fluid.cpp -o CMakeFiles/fluid.dir/fluid.cpp.s

# Object files for target fluid
fluid_OBJECTS = \
"CMakeFiles/fluid.dir/fluid.cpp.o"

# External object files for target fluid
fluid_EXTERNAL_OBJECTS =

fluid: CMakeFiles/fluid.dir/fluid.cpp.o
fluid: CMakeFiles/fluid.dir/build.make
fluid: CMakeFiles/fluid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nora/Projects/waterBoxSimulator/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fluid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fluid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fluid.dir/build: fluid
.PHONY : CMakeFiles/fluid.dir/build

CMakeFiles/fluid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fluid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fluid.dir/clean

CMakeFiles/fluid.dir/depend:
	cd /home/nora/Projects/waterBoxSimulator/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nora/Projects/waterBoxSimulator /home/nora/Projects/waterBoxSimulator /home/nora/Projects/waterBoxSimulator/out/build /home/nora/Projects/waterBoxSimulator/out/build /home/nora/Projects/waterBoxSimulator/out/build/CMakeFiles/fluid.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/fluid.dir/depend

