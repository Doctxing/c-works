# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /mnt/d/coder/Works/c-extra/extra-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/extra2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/extra2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/extra2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/extra2.dir/flags.make

CMakeFiles/extra2.dir/main.c.o: CMakeFiles/extra2.dir/flags.make
CMakeFiles/extra2.dir/main.c.o: /mnt/d/coder/Works/c-extra/extra-2/main.c
CMakeFiles/extra2.dir/main.c.o: CMakeFiles/extra2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/extra2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/extra2.dir/main.c.o -MF CMakeFiles/extra2.dir/main.c.o.d -o CMakeFiles/extra2.dir/main.c.o -c /mnt/d/coder/Works/c-extra/extra-2/main.c

CMakeFiles/extra2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extra2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/coder/Works/c-extra/extra-2/main.c > CMakeFiles/extra2.dir/main.c.i

CMakeFiles/extra2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extra2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/coder/Works/c-extra/extra-2/main.c -o CMakeFiles/extra2.dir/main.c.s

CMakeFiles/extra2.dir/cv.c.o: CMakeFiles/extra2.dir/flags.make
CMakeFiles/extra2.dir/cv.c.o: /mnt/d/coder/Works/c-extra/extra-2/cv.c
CMakeFiles/extra2.dir/cv.c.o: CMakeFiles/extra2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/extra2.dir/cv.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/extra2.dir/cv.c.o -MF CMakeFiles/extra2.dir/cv.c.o.d -o CMakeFiles/extra2.dir/cv.c.o -c /mnt/d/coder/Works/c-extra/extra-2/cv.c

CMakeFiles/extra2.dir/cv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extra2.dir/cv.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/coder/Works/c-extra/extra-2/cv.c > CMakeFiles/extra2.dir/cv.c.i

CMakeFiles/extra2.dir/cv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extra2.dir/cv.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/coder/Works/c-extra/extra-2/cv.c -o CMakeFiles/extra2.dir/cv.c.s

# Object files for target extra2
extra2_OBJECTS = \
"CMakeFiles/extra2.dir/main.c.o" \
"CMakeFiles/extra2.dir/cv.c.o"

# External object files for target extra2
extra2_EXTERNAL_OBJECTS =

extra2: CMakeFiles/extra2.dir/main.c.o
extra2: CMakeFiles/extra2.dir/cv.c.o
extra2: CMakeFiles/extra2.dir/build.make
extra2: CMakeFiles/extra2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable extra2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extra2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/extra2.dir/build: extra2
.PHONY : CMakeFiles/extra2.dir/build

CMakeFiles/extra2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/extra2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/extra2.dir/clean

CMakeFiles/extra2.dir/depend:
	cd /mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/coder/Works/c-extra/extra-2 /mnt/d/coder/Works/c-extra/extra-2 /mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl /mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl /mnt/d/coder/Works/c-extra/extra-2/cmake-build-debug-wsl/CMakeFiles/extra2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/extra2.dir/depend

