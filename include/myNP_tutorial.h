/*----------------------------------------------------------------\
@ C-Tutorial by Young-Keun Kim - Handong Global University
Author           : YOUR NAME
Created          : 09-01-2022
Modified         : 09-01-2022
Language/ver     : C in MSVS2022
Description      : myNP_tutorial.h
/----------------------------------------------------------------*/

#ifndef		_MY_NP_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NP_H
#define		PI		3.14159265358979323846264338327950288419716939937510582

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Factorial function
extern double factorial(double _x);

//  Taylor series approximation for sin(x) using pre-defined functions (input unit: [rad])
extern double sinTaylor(double _x);

// Taylor series approximation for sin(x) using pre-defined functions (input unit: [deg])
extern double sindTaylor(double _x);

// power fuction
extern double power(double _x, int N);

// Taylor series approximation for sin(x) without using pre-defined functions (input unit: [rad])
extern double sinTaylor2(double _x);



#endif