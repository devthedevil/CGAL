# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pritampatel/Desktop/cgal_q4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pritampatel/Desktop/cgal_q4

# Include any dependencies generated for this target.
include CMakeFiles/cgal_q4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cgal_q4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cgal_q4.dir/flags.make

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o: CMakeFiles/cgal_q4.dir/flags.make
CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o: cgal_q4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pritampatel/Desktop/cgal_q4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o -c /home/pritampatel/Desktop/cgal_q4/cgal_q4.cpp

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgal_q4.dir/cgal_q4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pritampatel/Desktop/cgal_q4/cgal_q4.cpp > CMakeFiles/cgal_q4.dir/cgal_q4.cpp.i

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgal_q4.dir/cgal_q4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pritampatel/Desktop/cgal_q4/cgal_q4.cpp -o CMakeFiles/cgal_q4.dir/cgal_q4.cpp.s

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.requires:

.PHONY : CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.requires

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.provides: CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.requires
	$(MAKE) -f CMakeFiles/cgal_q4.dir/build.make CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.provides.build
.PHONY : CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.provides

CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.provides.build: CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o


# Object files for target cgal_q4
cgal_q4_OBJECTS = \
"CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o"

# External object files for target cgal_q4
cgal_q4_EXTERNAL_OBJECTS =

cgal_q4: CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o
cgal_q4: CMakeFiles/cgal_q4.dir/build.make
cgal_q4: /usr/lib/x86_64-linux-gnu/libmpfr.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libgmpxx.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libgmp.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libCGAL_Qt5.so.13.0.1
cgal_q4: /usr/lib/x86_64-linux-gnu/libCGAL.so.13.0.1
cgal_q4: /usr/lib/x86_64-linux-gnu/libGLU.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libGL.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Script.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libCGAL_Qt5.so.13.0.1
cgal_q4: /usr/lib/x86_64-linux-gnu/libCGAL.so.13.0.1
cgal_q4: /usr/lib/x86_64-linux-gnu/libGLU.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libGL.so
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
cgal_q4: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
cgal_q4: CMakeFiles/cgal_q4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pritampatel/Desktop/cgal_q4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cgal_q4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cgal_q4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cgal_q4.dir/build: cgal_q4

.PHONY : CMakeFiles/cgal_q4.dir/build

CMakeFiles/cgal_q4.dir/requires: CMakeFiles/cgal_q4.dir/cgal_q4.cpp.o.requires

.PHONY : CMakeFiles/cgal_q4.dir/requires

CMakeFiles/cgal_q4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cgal_q4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cgal_q4.dir/clean

CMakeFiles/cgal_q4.dir/depend:
	cd /home/pritampatel/Desktop/cgal_q4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pritampatel/Desktop/cgal_q4 /home/pritampatel/Desktop/cgal_q4 /home/pritampatel/Desktop/cgal_q4 /home/pritampatel/Desktop/cgal_q4 /home/pritampatel/Desktop/cgal_q4/CMakeFiles/cgal_q4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cgal_q4.dir/depend

