# Minimum required version of CMake
cmake_minimum_required(VERSION 3.18)

# Set CMake project name
project(MC33)

add_library(MC33++ SHARED source/libMC33++.cpp)
set_property(TARGET MC33++ APPEND PROPERTY COMPILE_DEFINITIONS "MC33_DLL_EXPORTS")
set_property(TARGET MC33++ APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS "MC33_DLL_IMPORTS")

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

