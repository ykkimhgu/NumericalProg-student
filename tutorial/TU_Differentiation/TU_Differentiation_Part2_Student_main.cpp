/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : SSS LAB
Created          : 10-05-2021
Modified         : 8-05-2022
Language/ver     : C++ in MSVS2019

Description      : [Tutorial]Differentiation.cpp
-------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include "../Include/myNM.h"



double myFunc(const double x);

int main(int argc, char* argv[])
{

	// PART 1
	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");
	
	int m = 21;
	double t[21] = { 0 };
	for (int i = 0; i < m; i++) t[i] = 0.2 * i;

	double x[] = { -5.87, -4.23, -2.55, -0.89, 0.67, 2.09, 3.31, 4.31, 5.06, 5.55, 5.78, 5.77, 5.52, 5.08, 4.46, 3.72, 2.88, 2.00, 1.10, 0.23, -0.59 };
	double  dxdt[21] = { 0 };
	
	// Estimate differentation from discrete dataset points
	gradient1D(t, x, dxdt, m);
	printVec(dxdt, m);

	
	// PART 2
	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");
	
	double xin = 2.5;
	double y=myFunc(xin);
	printf("\n y=myFun(xin) = %f \n\n", y);	
	func_call(myFunc, xin);
	printf("\n**************************************************\n\n");
	
	
	// Estimate differentation from the user defined function 
	double dydx[21];
	gradientFunc(myFunc, t, dydx, m);
	printVec(dydx, m);
			

	system("pause");
	return 0;
}


// User defined function:  example  y=x*x
double myFunc(const double x) {
	return  x * x;
}