/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 18-03-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"


/*----------------------------------------------------------------\
	Vector   NP Library
----------------------------------------------------------------*/

void printVec(double* vec, int row)
{
	for (int i = 0; i < row; i++)
		printf("Vector[%d] = %.1f \n", i, vec[i]);
	printf("\n");
}



/*----------------------------------------------------------------\
	Differentiation  NP Library
----------------------------------------------------------------*/

// Return the dy/dx results for the input data. (truncation error: O(h^2))
void gradient1D(double x[], double y[], double dydx[], int m) {
	double h = x[1] - x[0];

	if (sizeof(x) != sizeof(y)) {
		printf("ERROR: length of x and y must be equal\n");
		return;
	}
		
	// Two-Point FWD  O(h)
	// Modify to Three-Point FWD  O(h^2)
	dydx[0] = (y[1] - y[0]) / h;

	// Two-Point Central  O(h^2)
	for (int i = 1; i < m - 1; i++) {
		dydx[i] = (y[i + 1] - y[i - 1]) / (2 * h);
	}

	// Two-Point BWD  O(h)
	// Modify to Three-Point BWD  O(h^2)
	dydx[m - 1] = (y[m-1]-y[m - 2]) / (h);
}


// Return the dy/dx results for the target equation. (truncation error: O(h^2))
void gradientFunc(double func(const double x), double x[], double dydx[], int m) {
	double* y;

	y = (double*)malloc(sizeof(double) * m);
	for (int i = 0; i < m; i++) {
		y[i] = func(x[i]);
	}

	//printVec(y, m);
	gradient1D(x, y, dydx, m);

	free(y);
}

// Tutorial example for callback function 
void func_call(double func(const double x), double xin) {
	double yout = func(xin);
	printf("Y_out by my_func=%f\n", yout);
}

/*----------------------------------------------------------------\
	Integration  NP Library
----------------------------------------------------------------*/
