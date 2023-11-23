/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 18-03-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include <iostream>
#include <string>
#include <fstream>

// Return the dy/dx results for the input data. (truncation error: O(h^2))
void gradient1D(double x[], double y[], double dydx[], int m);

void gradient1D_Oh1(double _x[], double _y[], double dydx[], int m);

void func_call(double func(const double x), double xin);

// Return the dy/dx results for the target equation. (truncation error: O(h^2))
void gradientFunc(double func(const double x), double x[], double dydx[], int m);

void printVec(double* _vec, int _row);

#endif
