/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 03-05-2021
Modified         : 03-05-2021
Language/ver     : C++ in MSVS2019

Description      : [Tutorial]curve_fitting.cpp
-------------------------------------------------------------------------------*/

#include "myNM.h"

// Returns the parameters of the linear least square function.
Matrix	linearFit(Matrix _x, Matrix _y);

// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);

int main(int argc, char* argv[])
{
	int M = 6;
	double T_array[] = { 30, 40, 50, 60, 70, 80 };
	double P_array[] = { 1.05, 1.07, 1.09, 1.14, 1.17, 1.21 };

	Matrix T = arr2Mat(T_array, M, 1);
	Matrix P = arr2Mat(P_array, M, 1);

	Matrix z = linearFit(T, P);

	printMat(T, "T");
	printMat(P, "P");
	printMat(z, "z");

	system("pause");
	return 0;
}

// Returns the parameters of the linear least square function.
Matrix	linearFit(Matrix _x, Matrix _y) {
	int mx = _x.rows;
	int my = _y.rows;

	double a1 = 0;
	double a0 = 0;

	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE
	// ADD YOUR CODE HERE

	double z_array[] = { a1, a0 };
	return arr2Mat(z_array, 2, 1);
}

// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
	Matrix Output = createMat(_rows, _cols);

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			Output.at[i][j] = _1Darray[i * _cols + j];

	return Output;
}