# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build

# Include any dependencies generated for this target.
include TP_template/CMakeFiles/TP_template_Jeu.dir/depend.make

# Include the progress variables for this target.
include TP_template/CMakeFiles/TP_template_Jeu.dir/progress.make

# Include the compile flags for this target's objects.
include TP_template/CMakeFiles/TP_template_Jeu.dir/flags.make

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o: TP_template/CMakeFiles/TP_template_Jeu.dir/flags.make
TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o: /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu/TP_template/Jeu.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o"
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o -c /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu/TP_template/Jeu.cpp

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.i"
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu/TP_template/Jeu.cpp > CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.i

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.s"
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu/TP_template/Jeu.cpp -o CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.s

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.requires:
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.requires

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.provides: TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.requires
	$(MAKE) -f TP_template/CMakeFiles/TP_template_Jeu.dir/build.make TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.provides.build
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.provides

TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.provides.build: TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o

# Object files for target TP_template_Jeu
TP_template_Jeu_OBJECTS = \
"CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o"

# External object files for target TP_template_Jeu
TP_template_Jeu_EXTERNAL_OBJECTS =

TP_template/TP_template_Jeu: TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o
TP_template/TP_template_Jeu: TP_template/CMakeFiles/TP_template_Jeu.dir/build.make
TP_template/TP_template_Jeu: glimac/libglimac.a
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libSDL.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libGLU.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libGL.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libSM.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libICE.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libX11.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libXext.so
TP_template/TP_template_Jeu: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP_template/TP_template_Jeu: TP_template/CMakeFiles/TP_template_Jeu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TP_template_Jeu"
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_template_Jeu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP_template/CMakeFiles/TP_template_Jeu.dir/build: TP_template/TP_template_Jeu
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/build

TP_template/CMakeFiles/TP_template_Jeu.dir/requires: TP_template/CMakeFiles/TP_template_Jeu.dir/Jeu.cpp.o.requires
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/requires

TP_template/CMakeFiles/TP_template_Jeu.dir/clean:
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template && $(CMAKE_COMMAND) -P CMakeFiles/TP_template_Jeu.dir/cmake_clean.cmake
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/clean

TP_template/CMakeFiles/TP_template_Jeu.dir/depend:
	cd /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu/TP_template /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template /home/julie/Desktop/openGL/projetOpenGL_IMAC2/joliJeu-build/TP_template/CMakeFiles/TP_template_Jeu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP_template/CMakeFiles/TP_template_Jeu.dir/depend

