# Minimum required version of CMake
cmake_minimum_required(VERSION 3.18)

# Set CMake project name
project(MC33)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BT)
if (NOT DEFINED BUILD_SHARED_LIBS OR BUILD_SHARED_LIBS)
  add_library(MC33 SHARED source/libMC33++.cpp)
  set_property(TARGET MC33 APPEND PROPERTY COMPILE_DEFINITIONS "MC33_DLL_EXPORTS")
  set_property(TARGET MC33 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS "MC33_DLL_IMPORTS")
  set(BT ${BT} MC33)
endif()

if (NOT DEFINED BUILD_STATIC_LIBS OR BUILD_STATIC_LIBS)
  add_library(MC33static STATIC source/libMC33++.cpp)
  set(BT ${BT} MC33static)
endif ()

if (NOT MSVC)
  include(CheckCXXCompilerFlag)
  set(CHKFLAGS -Ofast -m64 -Wall -Wextra -funroll-loops)

  function(apply_flag tname cf)
    string(REPLACE "-" "_" cfname "${cf}")
    string(TOUPPER "${cfname}" cfuname)
    check_cxx_compiler_flag(${cf} ${cfuname}_COMPILER_FLAG)
    if (${cfuname}_COMPILER_FLAG)
      target_compile_options(${tname} PRIVATE "${cf}")
    endif ()
  endfunction()

  foreach(tgt ${BT})
    foreach(cf ${CHKFLAGS})
      apply_flag(${tgt} ${cf})
    endforeach()
  endforeach(tgt ${BT})
else()
  # MSVC has its own flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GL /W3 /Gy /O2 /Zc:inline /fp:fast /Gd /Oi /MD /EHsc /nologo /Ot")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /LTCG /NOLOGO")
endif(NOT MSVC)

add_subdirectory(examples)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8

