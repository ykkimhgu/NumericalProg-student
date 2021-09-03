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

#include "myMatrix.h"

// New function for assignment
void tempFunction(int m);

// Function mdified


// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);

// Apply back-substitution
extern	Matrix	backSub(Matrix _A, Matrix _b);

// Return the dy/dx results for the input data. (truncation error: O(h^2))
Matrix	gradient(Matrix _x, Matrix _y);

// Return the dy/dx results for the target equation. (truncation error: O(h^2))
Matrix	gradientFunc(double func(const double x), Matrix xin);

#endif
