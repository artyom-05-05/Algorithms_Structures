# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\user\CLionProjects\Algorithms&Structures\C"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\C.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\C.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\C.dir\flags.make

CMakeFiles\C.dir\Configure_file.cpp.obj: CMakeFiles\C.dir\flags.make
CMakeFiles\C.dir\Configure_file.cpp.obj: ..\Configure_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C.dir/Configure_file.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\C.dir\Configure_file.cpp.obj /FdCMakeFiles\C.dir\ /FS -c "C:\Users\user\CLionProjects\Algorithms&Structures\C\Configure_file.cpp"
<<

CMakeFiles\C.dir\Configure_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C.dir/Configure_file.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\C.dir\Configure_file.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\CLionProjects\Algorithms&Structures\C\Configure_file.cpp"
<<

CMakeFiles\C.dir\Configure_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C.dir/Configure_file.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\C.dir\Configure_file.cpp.s /c "C:\Users\user\CLionProjects\Algorithms&Structures\C\Configure_file.cpp"
<<

# Object files for target C
C_OBJECTS = \
"CMakeFiles\C.dir\Configure_file.cpp.obj"

# External object files for target C
C_EXTERNAL_OBJECTS =

C.exe: CMakeFiles\C.dir\Configure_file.cpp.obj
C.exe: CMakeFiles\C.dir\build.make
C.exe: CMakeFiles\C.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C.exe"
	"C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\C.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\C.dir\objects1.rsp @<<
 /out:C.exe /implib:C.lib /pdb:"C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug\C.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\C.dir\build: C.exe

.PHONY : CMakeFiles\C.dir\build

CMakeFiles\C.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C.dir\cmake_clean.cmake
.PHONY : CMakeFiles\C.dir\clean

CMakeFiles\C.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\user\CLionProjects\Algorithms&Structures\C" "C:\Users\user\CLionProjects\Algorithms&Structures\C" "C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug" "C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug" "C:\Users\user\CLionProjects\Algorithms&Structures\C\cmake-build-debug\CMakeFiles\C.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\C.dir\depend

