# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/laptop/school/BK/PCL_TUTORIAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laptop/school/BK/PCL_TUTORIAL/build22

# Include any dependencies generated for this target.
include CMakeFiles/cylinder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cylinder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cylinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cylinder.dir/flags.make

CMakeFiles/cylinder.dir/cylinder.cpp.o: CMakeFiles/cylinder.dir/flags.make
CMakeFiles/cylinder.dir/cylinder.cpp.o: ../cylinder.cpp
CMakeFiles/cylinder.dir/cylinder.cpp.o: CMakeFiles/cylinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laptop/school/BK/PCL_TUTORIAL/build22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cylinder.dir/cylinder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cylinder.dir/cylinder.cpp.o -MF CMakeFiles/cylinder.dir/cylinder.cpp.o.d -o CMakeFiles/cylinder.dir/cylinder.cpp.o -c /home/laptop/school/BK/PCL_TUTORIAL/cylinder.cpp

CMakeFiles/cylinder.dir/cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cylinder.dir/cylinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laptop/school/BK/PCL_TUTORIAL/cylinder.cpp > CMakeFiles/cylinder.dir/cylinder.cpp.i

CMakeFiles/cylinder.dir/cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cylinder.dir/cylinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laptop/school/BK/PCL_TUTORIAL/cylinder.cpp -o CMakeFiles/cylinder.dir/cylinder.cpp.s

# Object files for target cylinder
cylinder_OBJECTS = \
"CMakeFiles/cylinder.dir/cylinder.cpp.o"

# External object files for target cylinder
cylinder_EXTERNAL_OBJECTS =

cylinder: CMakeFiles/cylinder.dir/cylinder.cpp.o
cylinder: CMakeFiles/cylinder.dir/build.make
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_apps.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_outofcore.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_people.so
cylinder: /usr/lib/libOpenNI.so
cylinder: /usr/lib/x86_64-linux-gnu/libusb-1.0.so
cylinder: /usr/lib/x86_64-linux-gnu/libOpenNI2.so
cylinder: /usr/lib/x86_64-linux-gnu/libusb-1.0.so
cylinder: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
cylinder: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_surface.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_keypoints.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_tracking.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_recognition.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_registration.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_stereo.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_segmentation.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_features.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_filters.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_sample_consensus.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_ml.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_visualization.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_search.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_kdtree.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_io.so
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_octree.so
cylinder: /usr/lib/x86_64-linux-gnu/libpng.so
cylinder: /usr/lib/x86_64-linux-gnu/libz.so
cylinder: /usr/lib/libOpenNI.so
cylinder: /usr/lib/x86_64-linux-gnu/libusb-1.0.so
cylinder: /usr/lib/x86_64-linux-gnu/libOpenNI2.so
cylinder: /usr/lib/x86_64-linux-gnu/libvtkChartsCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkInteractionImage-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkIOGeometry-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libjsoncpp.so
cylinder: /usr/lib/x86_64-linux-gnu/libvtkIOPLY-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingLOD-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkViewsContext2D-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkViewsCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkGUISupportQt-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkInteractionWidgets-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersModeling-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkIOLegacy-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkIOCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingAnnotation-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingContext2D-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libfreetype.so
cylinder: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkIOImage-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingUI-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libvtkkissfft-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libGLEW.so
cylinder: /usr/lib/x86_64-linux-gnu/libX11.so
cylinder: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
cylinder: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
cylinder: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
cylinder: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
cylinder: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libtbb.so.12.5
cylinder: /usr/lib/x86_64-linux-gnu/libvtksys-9.1.so.9.1.0
cylinder: /usr/lib/x86_64-linux-gnu/libpcl_common.so
cylinder: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.74.0
cylinder: /usr/lib/x86_64-linux-gnu/libqhull_r.so.8.0.2
cylinder: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
cylinder: CMakeFiles/cylinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laptop/school/BK/PCL_TUTORIAL/build22/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cylinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cylinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cylinder.dir/build: cylinder
.PHONY : CMakeFiles/cylinder.dir/build

CMakeFiles/cylinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cylinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cylinder.dir/clean

CMakeFiles/cylinder.dir/depend:
	cd /home/laptop/school/BK/PCL_TUTORIAL/build22 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laptop/school/BK/PCL_TUTORIAL /home/laptop/school/BK/PCL_TUTORIAL /home/laptop/school/BK/PCL_TUTORIAL/build22 /home/laptop/school/BK/PCL_TUTORIAL/build22 /home/laptop/school/BK/PCL_TUTORIAL/build22/CMakeFiles/cylinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cylinder.dir/depend

