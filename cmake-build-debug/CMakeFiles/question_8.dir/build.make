# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\NewFile\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\NewFile\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Data_Structure_Codes\Bilibili_lanqiao_codes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/question_8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/question_8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/question_8.dir/flags.make

CMakeFiles/question_8.dir/question_8.cpp.obj: CMakeFiles/question_8.dir/flags.make
CMakeFiles/question_8.dir/question_8.cpp.obj: ../question_8.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/question_8.dir/question_8.cpp.obj"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\question_8.dir\question_8.cpp.obj -c D:\Data_Structure_Codes\Bilibili_lanqiao_codes\question_8.cpp

CMakeFiles/question_8.dir/question_8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question_8.dir/question_8.cpp.i"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Data_Structure_Codes\Bilibili_lanqiao_codes\question_8.cpp > CMakeFiles\question_8.dir\question_8.cpp.i

CMakeFiles/question_8.dir/question_8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question_8.dir/question_8.cpp.s"
	D:\Dev-cpp5.4.0\Dev-Cpp\MinGW32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Data_Structure_Codes\Bilibili_lanqiao_codes\question_8.cpp -o CMakeFiles\question_8.dir\question_8.cpp.s

# Object files for target question_8
question_8_OBJECTS = \
"CMakeFiles/question_8.dir/question_8.cpp.obj"

# External object files for target question_8
question_8_EXTERNAL_OBJECTS =

question_8.exe: CMakeFiles/question_8.dir/question_8.cpp.obj
question_8.exe: CMakeFiles/question_8.dir/build.make
question_8.exe: CMakeFiles/question_8.dir/linklibs.rsp
question_8.exe: CMakeFiles/question_8.dir/objects1.rsp
question_8.exe: CMakeFiles/question_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable question_8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\question_8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/question_8.dir/build: question_8.exe

.PHONY : CMakeFiles/question_8.dir/build

CMakeFiles/question_8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\question_8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/question_8.dir/clean

CMakeFiles/question_8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Data_Structure_Codes\Bilibili_lanqiao_codes D:\Data_Structure_Codes\Bilibili_lanqiao_codes D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug D:\Data_Structure_Codes\Bilibili_lanqiao_codes\cmake-build-debug\CMakeFiles\question_8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/question_8.dir/depend

