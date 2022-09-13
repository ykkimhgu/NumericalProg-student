/*----------------------------------------------------------------\
@ C-Tutorial by Young-Keun Kim - Handong Global University
Author           : YOUR NAME
Created          : 09-01-2022
Modified         : 09-01-2022
Language/ver     : C in MSVS2022
Description      : myNP_tutorial.c
/----------------------------------------------------------------*/

#include "myNP_tutorial.h"

// factorial function
double factorial(int N)
{
	int y = 1;
	for (int k = 2; k <= N; k++)
		y = y * k;

	return y;
}

//  Taylor series approximation for sin(x) using pre-defined functions (input unit: [rad])
double sinTaylor(double _x)
{
	int N_max = 10;
	double S_N = 0;

	for (int k = 0; k < N_max; k++)
		S_N = S_N + pow(-1, k) * pow(_x, 2 * k + 1) / factorial(2 * k + 1);

	return S_N;
}

// Taylor series approximation for sin(x) using pre-defined functions (input unit: [deg])
double sindTaylor(double _x)
{
	return sinTaylor(_x * PI / 180);
}

// power fuction
double power(double _x, int N)
{
	double y = 1;

	for (int k = 1; k <= N; k++)
		y = y * _x;

	return y;
}

// Taylor series approximation for sin(x) without using pre-defined functions (input unit: [rad])
double sinTaylor2(double _x)
{
	int N_max = 10;
	double S_N = 0;

	for (int k = 0; k < N_max; k++)
		S_N = S_N + power(-1, k) * power(_x, 2 * k + 1) / factorial(2 * k + 1);

	return S_N;
}