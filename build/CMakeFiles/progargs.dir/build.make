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
CMAKE_BINARY_DIR = /home/nora/Projects/waterBoxSimulator/build

# Include any dependencies generated for this target.
include CMakeFiles/progargs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/progargs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/progargs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progargs.dir/flags.make

CMakeFiles/progargs.dir/progargs.cpp.o: CMakeFiles/progargs.dir/flags.make
CMakeFiles/progargs.dir/progargs.cpp.o: /home/nora/Projects/waterBoxSimulator/progargs.cpp
CMakeFiles/progargs.dir/progargs.cpp.o: CMakeFiles/progargs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nora/Projects/waterBoxSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progargs.dir/progargs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/progargs.dir/progargs.cpp.o -MF CMakeFiles/progargs.dir/progargs.cpp.o.d -o CMakeFiles/progargs.dir/progargs.cpp.o -c /home/nora/Projects/waterBoxSimulator/progargs.cpp

CMakeFiles/progargs.dir/progargs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/progargs.dir/progargs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nora/Projects/waterBoxSimulator/progargs.cpp > CMakeFiles/progargs.dir/progargs.cpp.i

CMakeFiles/progargs.dir/progargs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/progargs.dir/progargs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nora/Projects/waterBoxSimulator/progargs.cpp -o CMakeFiles/progargs.dir/progargs.cpp.s

# Object files for target progargs
progargs_OBJECTS = \
"CMakeFiles/progargs.dir/progargs.cpp.o"

# External object files for target progargs
progargs_EXTERNAL_OBJECTS =

libprogargs.a: CMakeFiles/progargs.dir/progargs.cpp.o
libprogargs.a: CMakeFiles/progargs.dir/build.make
libprogargs.a: CMakeFiles/progargs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nora/Projects/waterBoxSimulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libprogargs.a"
	$(CMAKE_COMMAND) -P CMakeFiles/progargs.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progargs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progargs.dir/build: libprogargs.a
.PHONY : CMakeFiles/progargs.dir/build

CMakeFiles/progargs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progargs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progargs.dir/clean

CMakeFiles/progargs.dir/depend:
	cd /home/nora/Projects/waterBoxSimulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nora/Projects/waterBoxSimulator /home/nora/Projects/waterBoxSimulator /home/nora/Projects/waterBoxSimulator/build /home/nora/Projects/waterBoxSimulator/build /home/nora/Projects/waterBoxSimulator/build/CMakeFiles/progargs.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/progargs.dir/depend

