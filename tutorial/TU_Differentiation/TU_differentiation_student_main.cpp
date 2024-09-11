/*------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 11-27-2023
Language/ver	: C in MSVS2017
Course		: Numerical Programming 

Description      : [Tutorial]Differentiation.cpp
-------------------------------------------------------------------------------*/

#include "stdio.h"
#include "stdlib.h"

#include "../../include/myNP.h"
//#include "../../include/myNP_myID.h"

double myFunc(const double x);


int main(int argc, char* argv[])
{

	/*==========================================================================*/
	/*   Part 1 -     Differentiation from discrete dataset points              */
	/*==========================================================================*/
	
	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");

	/************      Variables declaration & initialization      ************/
	int m = 21;
	double t[21] = { 0 };
	for (int i = 0; i < m; i++) t[i] = 0.2 * i;

	double x[] = { -5.87, -4.23, -2.55, -0.89, 0.67, 2.09, 3.31, 4.31, 5.06, 5.55, 5.78, 5.77, 5.52, 5.08, 4.46, 3.72, 2.88, 2.00, 1.10, 0.23, -0.59 };
	double  dxdt[21] = { 0 };

	/************      Solve  &	Show Output	   ************/
	// Differentiation from discrete dataset points
	gradient1D(t, x, dxdt, m);
	printVec(dxdt, m);

/*

	/*==========================================================================*/
	/*   Part 2 -     Differentiation from a function                           */
	/*==========================================================================*/
	
	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");

	/************      Variables declaration & initialization      ************/
	double xin = 2.5;
	double dydx[21];  // m=21 points
	
	// User defined function F(x)
	double y=myFunc(xin);
	printf("\n y=myFun(xin) = %f \n\n", y);	
	
		
	/************      Solve  &	Show Output	   ************/
	// Estimate differentation from the user defined function 
	gradientFunc(myFunc, t, dydx, m);
	printVec(dydx, m);
			
*/
	system("pause");
	return 0;
}


// User defined function:  example  y=x*x
// Modify to User Function
double myFunc(const double x) {
	return  x * x;
}
