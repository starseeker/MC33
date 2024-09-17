/*
File: libMC33++.cpp
Programmed by: David Vega
August 2019
August 2020
April 2021
December 2021
Only this file must be included in a project to compile the MC33 library
*/

#define compiling_libMC33

#include "../include/MC33.h"
extern void (*multAbf)(const double (*)[3], MC33_real *, MC33_real *, int);
extern void (*multAb)(const double (*)[3], double *, double *, int);
extern void (*mult_Abf)(const double (*)[3], MC33_real *, MC33_real *, int);
extern void (*mult_TSAbf)(const double (*)[3], MC33_real *, MC33_real *, int);
#include "grid3d.cpp"
#include "surface.cpp"
#include "MC33.cpp"


// Local Variables:
// tab-width: 8
// mode: C++
// c-basic-offset: 4
// indent-tabs-mode: t
// c-file-style: "stroustrup"
// End:
// ex: shiftwidth=4 tabstop=8

