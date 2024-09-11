/*------------------------------------------------------------------------------------------\
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
#include <math.h>

//#include "../../include/myNP_myID.h"


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
	

	system("pause");
	return 0;
}
