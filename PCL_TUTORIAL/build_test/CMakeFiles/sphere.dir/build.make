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
CMAKE_SOURCE_DIR = /home/laptop/BakalarskaPraca/PCL_TUTORIAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test

# Include any dependencies generated for this target.
include CMakeFiles/sphere.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sphere.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sphere.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sphere.dir/flags.make

CMakeFiles/sphere.dir/sphere.cpp.o: CMakeFiles/sphere.dir/flags.make
CMakeFiles/sphere.dir/sphere.cpp.o: ../sphere.cpp
CMakeFiles/sphere.dir/sphere.cpp.o: CMakeFiles/sphere.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sphere.dir/sphere.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sphere.dir/sphere.cpp.o -MF CMakeFiles/sphere.dir/sphere.cpp.o.d -o CMakeFiles/sphere.dir/sphere.cpp.o -c /home/laptop/BakalarskaPraca/PCL_TUTORIAL/sphere.cpp

CMakeFiles/sphere.dir/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sphere.dir/sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laptop/BakalarskaPraca/PCL_TUTORIAL/sphere.cpp > CMakeFiles/sphere.dir/sphere.cpp.i

CMakeFiles/sphere.dir/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sphere.dir/sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laptop/BakalarskaPraca/PCL_TUTORIAL/sphere.cpp -o CMakeFiles/sphere.dir/sphere.cpp.s

# Object files for target sphere
sphere_OBJECTS = \
"CMakeFiles/sphere.dir/sphere.cpp.o"

# External object files for target sphere
sphere_EXTERNAL_OBJECTS =

sphere: CMakeFiles/sphere.dir/sphere.cpp.o
sphere: CMakeFiles/sphere.dir/build.make
sphere: /usr/local/lib/libpcl_surface.so
sphere: /usr/local/lib/libpcl_keypoints.so
sphere: /usr/local/lib/libpcl_tracking.so
sphere: /usr/local/lib/libpcl_recognition.so
sphere: /usr/local/lib/libpcl_stereo.so
sphere: /usr/local/lib/libpcl_outofcore.so
sphere: /usr/local/lib/libpcl_people.so
sphere: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
sphere: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
sphere: /usr/local/lib/libpcl_registration.so
sphere: /usr/local/lib/libpcl_segmentation.so
sphere: /usr/local/lib/libpcl_features.so
sphere: /usr/local/lib/libpcl_filters.so
sphere: /usr/local/lib/libpcl_sample_consensus.so
sphere: /usr/local/lib/libpcl_ml.so
sphere: /usr/local/lib/libpcl_visualization.so
sphere: /usr/local/lib/libpcl_search.so
sphere: /usr/local/lib/libpcl_kdtree.so
sphere: /usr/local/lib/libpcl_io.so
sphere: /usr/local/lib/libpcl_octree.so
sphere: /usr/lib/x86_64-linux-gnu/libpng.so
sphere: /usr/lib/x86_64-linux-gnu/libz.so
sphere: /usr/local/lib/libvtkChartsCore-8.1.so.1
sphere: /usr/local/lib/libvtkInfovisCore-8.1.so.1
sphere: /usr/local/lib/libvtkInteractionImage-8.1.so.1
sphere: /usr/local/lib/libvtkIOGeometry-8.1.so.1
sphere: /usr/local/lib/libvtkIOLegacy-8.1.so.1
sphere: /usr/local/lib/libvtkIOPLY-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingLOD-8.1.so.1
sphere: /usr/local/lib/libvtkViewsContext2D-8.1.so.1
sphere: /usr/local/lib/libvtkViewsCore-8.1.so.1
sphere: /usr/local/lib/libvtkInteractionWidgets-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersModeling-8.1.so.1
sphere: /usr/local/lib/libvtkInteractionStyle-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersExtraction-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersStatistics-8.1.so.1
sphere: /usr/local/lib/libvtkImagingFourier-8.1.so.1
sphere: /usr/local/lib/libvtkalglib-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersHybrid-8.1.so.1
sphere: /usr/local/lib/libvtkImagingGeneral-8.1.so.1
sphere: /usr/local/lib/libvtkImagingSources-8.1.so.1
sphere: /usr/local/lib/libvtkImagingHybrid-8.1.so.1
sphere: /usr/local/lib/libvtkIOImage-8.1.so.1
sphere: /usr/local/lib/libvtkDICOMParser-8.1.so.1
sphere: /usr/local/lib/libvtkmetaio-8.1.so.1
sphere: /usr/local/lib/libvtkpng-8.1.so.1
sphere: /usr/local/lib/libvtktiff-8.1.so.1
sphere: /usr/local/lib/libvtkjpeg-8.1.so.1
sphere: /usr/lib/x86_64-linux-gnu/libm.so
sphere: /usr/local/lib/libvtkRenderingAnnotation-8.1.so.1
sphere: /usr/local/lib/libvtkImagingColor-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingVolume-8.1.so.1
sphere: /usr/local/lib/libvtkIOXML-8.1.so.1
sphere: /usr/local/lib/libvtkIOXMLParser-8.1.so.1
sphere: /usr/local/lib/libvtkIOCore-8.1.so.1
sphere: /usr/local/lib/libvtklz4-8.1.so.1
sphere: /usr/local/lib/libvtkexpat-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingContextOpenGL2-8.1.so.1
sphere: /usr/local/lib/libvtkImagingCore-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingContext2D-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingFreeType-8.1.so.1
sphere: /usr/local/lib/libvtkfreetype-8.1.so.1
sphere: /usr/local/lib/libvtkzlib-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingOpenGL2-8.1.so.1
sphere: /usr/local/lib/libvtkRenderingCore-8.1.so.1
sphere: /usr/local/lib/libvtkCommonColor-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersGeometry-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersSources-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersGeneral-8.1.so.1
sphere: /usr/local/lib/libvtkCommonComputationalGeometry-8.1.so.1
sphere: /usr/local/lib/libvtkFiltersCore-8.1.so.1
sphere: /usr/local/lib/libvtkCommonExecutionModel-8.1.so.1
sphere: /usr/local/lib/libvtkCommonDataModel-8.1.so.1
sphere: /usr/local/lib/libvtkCommonTransforms-8.1.so.1
sphere: /usr/local/lib/libvtkCommonMisc-8.1.so.1
sphere: /usr/local/lib/libvtkCommonMath-8.1.so.1
sphere: /usr/local/lib/libvtkCommonSystem-8.1.so.1
sphere: /usr/local/lib/libvtkCommonCore-8.1.so.1
sphere: /usr/local/lib/libvtksys-8.1.so.1
sphere: /usr/lib/x86_64-linux-gnu/libSM.so
sphere: /usr/lib/x86_64-linux-gnu/libICE.so
sphere: /usr/lib/x86_64-linux-gnu/libX11.so
sphere: /usr/lib/x86_64-linux-gnu/libXext.so
sphere: /usr/lib/x86_64-linux-gnu/libXt.so
sphere: /usr/local/lib/libvtkglew-8.1.so.1
sphere: /usr/local/lib/libpcl_common.so
sphere: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
sphere: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
sphere: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.74.0
sphere: /usr/lib/x86_64-linux-gnu/libqhull_r.so.8.0.2
sphere: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
sphere: CMakeFiles/sphere.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sphere"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sphere.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sphere.dir/build: sphere
.PHONY : CMakeFiles/sphere.dir/build

CMakeFiles/sphere.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sphere.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sphere.dir/clean

CMakeFiles/sphere.dir/depend:
	cd /home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laptop/BakalarskaPraca/PCL_TUTORIAL /home/laptop/BakalarskaPraca/PCL_TUTORIAL /home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test /home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test /home/laptop/BakalarskaPraca/PCL_TUTORIAL/build_test/CMakeFiles/sphere.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sphere.dir/depend

