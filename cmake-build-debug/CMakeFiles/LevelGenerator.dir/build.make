# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/CLionProjects/LevelGenerator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/CLionProjects/LevelGenerator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LevelGenerator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LevelGenerator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LevelGenerator.dir/flags.make

CMakeFiles/LevelGenerator.dir/main.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LevelGenerator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/main.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/main.cpp

CMakeFiles/LevelGenerator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/main.cpp > CMakeFiles/LevelGenerator.dir/main.cpp.i

CMakeFiles/LevelGenerator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/main.cpp -o CMakeFiles/LevelGenerator.dir/main.cpp.s

CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o: ../GeomObjects/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Button.cpp

CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Button.cpp > CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.i

CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Button.cpp -o CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.s

CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o: ../Managers/MouseStatus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/Managers/MouseStatus.cpp

CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/Managers/MouseStatus.cpp > CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.i

CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/Managers/MouseStatus.cpp -o CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.s

CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o: ../GeomObjects/TileMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/GeomObjects/TileMap.cpp

CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/GeomObjects/TileMap.cpp > CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.i

CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/GeomObjects/TileMap.cpp -o CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.s

CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o: ../WindowObjects/LevelGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/WindowObjects/LevelGenerator.cpp

CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/WindowObjects/LevelGenerator.cpp > CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.i

CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/WindowObjects/LevelGenerator.cpp -o CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.s

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o: ../WindowObjects/DialogWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogWindow.cpp

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogWindow.cpp > CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.i

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogWindow.cpp -o CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.s

CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o: ../Managers/EventManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/Managers/EventManager.cpp

CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/Managers/EventManager.cpp > CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.i

CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/Managers/EventManager.cpp -o CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.s

CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o: ../GeomObjects/InputBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/GeomObjects/InputBox.cpp

CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/GeomObjects/InputBox.cpp > CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.i

CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/GeomObjects/InputBox.cpp -o CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.s

CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o: ../GeomObjects/Minimap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Minimap.cpp

CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Minimap.cpp > CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.i

CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Minimap.cpp -o CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.s

CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o: ../GeomObjects/Palette.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Palette.cpp

CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Palette.cpp > CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.i

CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/GeomObjects/Palette.cpp -o CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.s

CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o: ../Managers/LayoutManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/Managers/LayoutManager.cpp

CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/Managers/LayoutManager.cpp > CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.i

CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/Managers/LayoutManager.cpp -o CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.s

CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o: ../Managers/TextureManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/Managers/TextureManager.cpp

CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/Managers/TextureManager.cpp > CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.i

CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/Managers/TextureManager.cpp -o CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.s

CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o: ../WindowObjects/NotificationWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/WindowObjects/NotificationWindow.cpp

CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/WindowObjects/NotificationWindow.cpp > CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.i

CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/WindowObjects/NotificationWindow.cpp -o CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.s

CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o: ../Managers/DialogLayoutForm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/Managers/DialogLayoutForm.cpp

CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/Managers/DialogLayoutForm.cpp > CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.i

CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/Managers/DialogLayoutForm.cpp -o CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.s

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o: CMakeFiles/LevelGenerator.dir/flags.make
CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o: ../WindowObjects/DialogForm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o -c /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogForm.cpp

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogForm.cpp > CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.i

CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/LevelGenerator/WindowObjects/DialogForm.cpp -o CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.s

# Object files for target LevelGenerator
LevelGenerator_OBJECTS = \
"CMakeFiles/LevelGenerator.dir/main.cpp.o" \
"CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o" \
"CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o" \
"CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o" \
"CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o" \
"CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o" \
"CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o" \
"CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o" \
"CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o" \
"CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o" \
"CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o" \
"CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o" \
"CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o" \
"CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o" \
"CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o"

# External object files for target LevelGenerator
LevelGenerator_EXTERNAL_OBJECTS =

LevelGenerator: CMakeFiles/LevelGenerator.dir/main.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/GeomObjects/Button.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/Managers/MouseStatus.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/GeomObjects/TileMap.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/WindowObjects/LevelGenerator.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/WindowObjects/DialogWindow.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/Managers/EventManager.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/GeomObjects/InputBox.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/GeomObjects/Minimap.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/GeomObjects/Palette.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/Managers/LayoutManager.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/Managers/TextureManager.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/WindowObjects/NotificationWindow.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/Managers/DialogLayoutForm.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/WindowObjects/DialogForm.cpp.o
LevelGenerator: CMakeFiles/LevelGenerator.dir/build.make
LevelGenerator: CMakeFiles/LevelGenerator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable LevelGenerator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LevelGenerator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LevelGenerator.dir/build: LevelGenerator

.PHONY : CMakeFiles/LevelGenerator.dir/build

CMakeFiles/LevelGenerator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LevelGenerator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LevelGenerator.dir/clean

CMakeFiles/LevelGenerator.dir/depend:
	cd /home/ilya/CLionProjects/LevelGenerator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/CLionProjects/LevelGenerator /home/ilya/CLionProjects/LevelGenerator /home/ilya/CLionProjects/LevelGenerator/cmake-build-debug /home/ilya/CLionProjects/LevelGenerator/cmake-build-debug /home/ilya/CLionProjects/LevelGenerator/cmake-build-debug/CMakeFiles/LevelGenerator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LevelGenerator.dir/depend

