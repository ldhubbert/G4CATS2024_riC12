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
CMAKE_SOURCE_DIR = /home/laura/G4CATS2024_riC12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/laura/G4CATS2024_riC12/build

# Include any dependencies generated for this target.
include CMakeFiles/exampleB4c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exampleB4c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exampleB4c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exampleB4c.dir/flags.make

CMakeFiles/exampleB4c.dir/exampleB4c.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/exampleB4c.cc.o: /home/laura/G4CATS2024_riC12/exampleB4c.cc
CMakeFiles/exampleB4c.dir/exampleB4c.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exampleB4c.dir/exampleB4c.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/exampleB4c.cc.o -MF CMakeFiles/exampleB4c.dir/exampleB4c.cc.o.d -o CMakeFiles/exampleB4c.dir/exampleB4c.cc.o -c /home/laura/G4CATS2024_riC12/exampleB4c.cc

CMakeFiles/exampleB4c.dir/exampleB4c.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/exampleB4c.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/exampleB4c.cc > CMakeFiles/exampleB4c.dir/exampleB4c.cc.i

CMakeFiles/exampleB4c.dir/exampleB4c.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/exampleB4c.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/exampleB4c.cc -o CMakeFiles/exampleB4c.dir/exampleB4c.cc.s

CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o: /home/laura/G4CATS2024_riC12/src/B4PrimaryGeneratorAction.cc
CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o -c /home/laura/G4CATS2024_riC12/src/B4PrimaryGeneratorAction.cc

CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4PrimaryGeneratorAction.cc > CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.i

CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4PrimaryGeneratorAction.cc -o CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.s

CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o: /home/laura/G4CATS2024_riC12/src/B4RunAction.cc
CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o -c /home/laura/G4CATS2024_riC12/src/B4RunAction.cc

CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4RunAction.cc > CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.i

CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4RunAction.cc -o CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.s

CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o: /home/laura/G4CATS2024_riC12/src/B4cActionInitialization.cc
CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o -c /home/laura/G4CATS2024_riC12/src/B4cActionInitialization.cc

CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4cActionInitialization.cc > CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.i

CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4cActionInitialization.cc -o CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.s

CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o: /home/laura/G4CATS2024_riC12/src/B4cCalorHit.cc
CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o -c /home/laura/G4CATS2024_riC12/src/B4cCalorHit.cc

CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4cCalorHit.cc > CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.i

CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4cCalorHit.cc -o CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.s

CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o: /home/laura/G4CATS2024_riC12/src/B4cCalorimeterSD.cc
CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o -c /home/laura/G4CATS2024_riC12/src/B4cCalorimeterSD.cc

CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4cCalorimeterSD.cc > CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.i

CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4cCalorimeterSD.cc -o CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.s

CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o: /home/laura/G4CATS2024_riC12/src/B4cDetectorConstruction.cc
CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o -c /home/laura/G4CATS2024_riC12/src/B4cDetectorConstruction.cc

CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4cDetectorConstruction.cc > CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.i

CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4cDetectorConstruction.cc -o CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.s

CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o: CMakeFiles/exampleB4c.dir/flags.make
CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o: /home/laura/G4CATS2024_riC12/src/B4cEventAction.cc
CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o: CMakeFiles/exampleB4c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o -MF CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o.d -o CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o -c /home/laura/G4CATS2024_riC12/src/B4cEventAction.cc

CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/laura/G4CATS2024_riC12/src/B4cEventAction.cc > CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.i

CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/laura/G4CATS2024_riC12/src/B4cEventAction.cc -o CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.s

# Object files for target exampleB4c
exampleB4c_OBJECTS = \
"CMakeFiles/exampleB4c.dir/exampleB4c.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o" \
"CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o"

# External object files for target exampleB4c
exampleB4c_EXTERNAL_OBJECTS =

exampleB4c: CMakeFiles/exampleB4c.dir/exampleB4c.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4PrimaryGeneratorAction.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4RunAction.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4cActionInitialization.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4cCalorHit.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4cCalorimeterSD.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4cDetectorConstruction.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/src/B4cEventAction.cc.o
exampleB4c: CMakeFiles/exampleB4c.dir/build.make
exampleB4c: /opt/g4/lib64/libG4Tree.so
exampleB4c: /opt/g4/lib64/libG4FR.so
exampleB4c: /opt/g4/lib64/libG4GMocren.so
exampleB4c: /opt/g4/lib64/libG4visHepRep.so
exampleB4c: /opt/g4/lib64/libG4RayTracer.so
exampleB4c: /opt/g4/lib64/libG4VRML.so
exampleB4c: /opt/g4/lib64/libG4ToolsSG.so
exampleB4c: /opt/g4/lib64/libG4OpenGL.so
exampleB4c: /opt/g4/lib64/libG4vis_management.so
exampleB4c: /opt/g4/lib64/libG4modeling.so
exampleB4c: /opt/g4/lib64/libG4interfaces.so
exampleB4c: /opt/g4/lib64/libG4mctruth.so
exampleB4c: /opt/g4/lib64/libG4geomtext.so
exampleB4c: /opt/g4/lib64/libG4gdml.so
exampleB4c: /opt/g4/lib64/libG4error_propagation.so
exampleB4c: /opt/g4/lib64/libG4readout.so
exampleB4c: /opt/g4/lib64/libG4physicslists.so
exampleB4c: /opt/g4/lib64/libG4run.so
exampleB4c: /opt/g4/lib64/libG4event.so
exampleB4c: /opt/g4/lib64/libG4tracking.so
exampleB4c: /opt/g4/lib64/libG4parmodels.so
exampleB4c: /opt/g4/lib64/libG4processes.so
exampleB4c: /opt/g4/lib64/libG4digits_hits.so
exampleB4c: /opt/g4/lib64/libG4track.so
exampleB4c: /opt/g4/lib64/libG4particles.so
exampleB4c: /opt/g4/lib64/libG4geometry.so
exampleB4c: /opt/g4/lib64/libG4materials.so
exampleB4c: /opt/g4/lib64/libG4graphics_reps.so
exampleB4c: /opt/root/lib/libCore.so
exampleB4c: /opt/root/lib/libImt.so
exampleB4c: /opt/root/lib/libRIO.so
exampleB4c: /opt/root/lib/libNet.so
exampleB4c: /opt/root/lib/libHist.so
exampleB4c: /opt/root/lib/libGraf.so
exampleB4c: /opt/root/lib/libGraf3d.so
exampleB4c: /opt/root/lib/libGpad.so
exampleB4c: /opt/root/lib/libROOTDataFrame.so
exampleB4c: /opt/root/lib/libTree.so
exampleB4c: /opt/root/lib/libTreePlayer.so
exampleB4c: /opt/root/lib/libRint.so
exampleB4c: /opt/root/lib/libPostscript.so
exampleB4c: /opt/root/lib/libMatrix.so
exampleB4c: /opt/root/lib/libPhysics.so
exampleB4c: /opt/root/lib/libMathCore.so
exampleB4c: /opt/root/lib/libThread.so
exampleB4c: /opt/root/lib/libMultiProc.so
exampleB4c: /opt/root/lib/libROOTVecOps.so
exampleB4c: /usr/lib64/libGL.so
exampleB4c: /usr/lib64/libXmu.so
exampleB4c: /usr/lib64/libXext.so
exampleB4c: /usr/lib64/libXt.so
exampleB4c: /usr/lib64/libICE.so
exampleB4c: /usr/lib64/libSM.so
exampleB4c: /usr/lib64/libX11.so
exampleB4c: /usr/lib64/libxerces-c.so
exampleB4c: /opt/g4/lib64/libG4analysis.so
exampleB4c: /usr/lib64/libexpat.so
exampleB4c: /opt/g4/lib64/libG4zlib.so
exampleB4c: /opt/g4/lib64/libG4intercoms.so
exampleB4c: /opt/g4/lib64/libG4global.so
exampleB4c: /opt/g4/lib64/libG4clhep.so
exampleB4c: /opt/g4/lib64/libG4ptl.so.2.3.3
exampleB4c: CMakeFiles/exampleB4c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/laura/G4CATS2024_riC12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable exampleB4c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exampleB4c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exampleB4c.dir/build: exampleB4c
.PHONY : CMakeFiles/exampleB4c.dir/build

CMakeFiles/exampleB4c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exampleB4c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exampleB4c.dir/clean

CMakeFiles/exampleB4c.dir/depend:
	cd /home/laura/G4CATS2024_riC12/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/laura/G4CATS2024_riC12 /home/laura/G4CATS2024_riC12 /home/laura/G4CATS2024_riC12/build /home/laura/G4CATS2024_riC12/build /home/laura/G4CATS2024_riC12/build/CMakeFiles/exampleB4c.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/exampleB4c.dir/depend

