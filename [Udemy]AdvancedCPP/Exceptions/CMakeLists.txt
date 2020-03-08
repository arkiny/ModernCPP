# CMakeList.txt : CMake project for Exceptions, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Exceptions")

# Add source to this project's executable.
add_executable (Exceptions "ExceptionMain.cpp" "BasicException.cpp")

# TODO: Add tests and install targets if needed.
