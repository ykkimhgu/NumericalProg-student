/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : SSS LAB
Created          : May-05-2021
Modified         : Sept-20-2022
Language/ver     : C++ in MSVS2019

Description      : Tutorial for Differentiation
-------------------------------------------------------------------------------*/


/*==========================================================================*/
/*               Tutorial -    Differentiation	                            */
/*==========================================================================*/



#include "stdio.h"
#include "stdlib.h"
// #include "../../../myNP.h"


double myFunc(const double x);

// Move to myNM.h
void printVec(double* _vec, int _row);
void gradient1D(double _x[], double _y[], double dydx[], int m);
void gradientFunc(double func(const double x), double x[], double dydx[], int m);




int main(int argc, char* argv[])
{

	/************			PART 1						     ************/	
	// Estimate differentation from data points

	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");
	
	int m = 21;
	double t[21] = { 0 };
	for (int i = 0; i < m; i++) t[i] = 0.2 * i;

	double x[] = { -5.87, -4.23, -2.55, -0.89, 0.67, 2.09, 3.31, 4.31, 5.06, 5.55, 5.78, 5.77, 5.52, 5.08, 4.46, 3.72, 2.88, 2.00, 1.10, 0.23, -0.59 };
	double  dxdt[21] = { 0 };
	
	// use two-points central difference
	gradient1D(t, x, dxdt, m);
	printVec(dxdt, m);

	

	/************			PART 2						     ************/	
	// Estimate differentation from the user-defined mathematic function 

	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");
	
	double xin = 2.5;
	double y=myFunc(xin);
	printf("\n y=myFun(xin) = %f \n\n", y);	
	printf("\n**************************************************\n\n");
	
		
	double dydx[21];
	gradientFunc(myFunc, t, dydx, m);
	printVec(dydx, m);
			

	system("pause");
	return 0;
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


// 
// User defined function:  example  y=x*x
double myFunc(const double x) {
	return  x * x;
}


// Move function definitions to  `myNM.c`
void printVec(double* _vec, int _row)
{
	for (int i = 0; i < _row; i++)
		printf("Vector[%d] = %.1f \n", i, _vec[i]);
	printf("\n");
}


// Truncation error should be O(h^2) 
void gradient1D(double _x[], double _y[], double dydx[], int m) {
	// For starting and end points	
	// Use 3-points forward and backwards 
	// For other points
	// Use 2-points central dfference
	
	// [TO-DO] YOUR CODE GOES HERE
	// [TO-DO] YOUR CODE GOES HERE
}


// Truncation error should be O(h^2) 
void gradientFunc(double func(const double x), double x[], double dydx[], int m) {
	double* y;

	y = (double*)malloc(sizeof(double) * m);
	for (int i = 0; i < m; i++) {
		y[i] = func(x[i]);
	}

	// [TO-DO] YOUR CODE GOES HERE
	// [TO-DO] YOUR CODE GOES HERE

	free(y);
}
