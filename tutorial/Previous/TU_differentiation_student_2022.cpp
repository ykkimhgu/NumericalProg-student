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
	double y = myFunc(xin);
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



// Return the dy/dx results for the input data. 
	// Problem 1) (truncation error: O(h) on end points)
	// Problem 2) (truncation error: O(h^2) on end points)
void gradient1D(double x[], double y[], double dydx[], int m) {	
// Check if length x and y are equal	
	if (sizeof(x) != sizeof(y)) {
		printf("ERROR: length of x and y must be equal\n");
		return;
	}

// Calculate h
	double h = x[1] - x[0];

///* Problem  1    */
// For starting point	
	// 1) Two-Point FWD  O(h) 
	dydx[0] = 0; // [TO-DO] YOUR CODE GOES HERE
	

// For mid points	
	// Two-Point Central  O(h^2)
	for (int i = 1; i < m - 1; i++) {
		dydx[i] = 0; // [TO-DO] YOUR CODE GOES HERE
	}

// For end point	
	// 1) Two-Point Backward  O(h)
	dydx[m - 1] = 0; // [TO-DO] YOUR CODE GOES HERE
	


/* Problem  2    */
// For starting point	
	// Three-Point FWD  O(h^2). Need to use first 2 points
// For mid points	
	// Two-Point Central  O(h^2)
// For end point	
	// Three-Point BWD  O(h^2). Need to use last 2 points


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
