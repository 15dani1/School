# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/rahul/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/rahul/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project_1___Magic_Square.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_1___Magic_Square.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_1___Magic_Square.dir/flags.make

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o: CMakeFiles/Project_1___Magic_Square.dir/flags.make
CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o"
	C:/cygwin64/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o -c "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/main.cpp"

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1___Magic_Square.dir/main.cpp.i"
	C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/main.cpp" > CMakeFiles/Project_1___Magic_Square.dir/main.cpp.i

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1___Magic_Square.dir/main.cpp.s"
	C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/main.cpp" -o CMakeFiles/Project_1___Magic_Square.dir/main.cpp.s

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.requires

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.provides: CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Project_1___Magic_Square.dir/build.make CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.provides

CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.provides.build: CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o


# Object files for target Project_1___Magic_Square
Project_1___Magic_Square_OBJECTS = \
"CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o"

# External object files for target Project_1___Magic_Square
Project_1___Magic_Square_EXTERNAL_OBJECTS =

Project_1___Magic_Square.exe: CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o
Project_1___Magic_Square.exe: CMakeFiles/Project_1___Magic_Square.dir/build.make
Project_1___Magic_Square.exe: CMakeFiles/Project_1___Magic_Square.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_1___Magic_Square.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_1___Magic_Square.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_1___Magic_Square.dir/build: Project_1___Magic_Square.exe

.PHONY : CMakeFiles/Project_1___Magic_Square.dir/build

CMakeFiles/Project_1___Magic_Square.dir/requires: CMakeFiles/Project_1___Magic_Square.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Project_1___Magic_Square.dir/requires

CMakeFiles/Project_1___Magic_Square.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_1___Magic_Square.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_1___Magic_Square.dir/clean

CMakeFiles/Project_1___Magic_Square.dir/depend:
	cd "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square" "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square" "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug" "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug" "/cygdrive/c/Users/rahul/Desktop/COP Projects/Project 1 - Magic Square/cmake-build-debug/CMakeFiles/Project_1___Magic_Square.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project_1___Magic_Square.dir/depend

