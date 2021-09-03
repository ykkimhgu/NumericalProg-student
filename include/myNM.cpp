/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 18-03-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp
----------------------------------------------------------------*/

#include "myNM.h"

void tempFunction(int m) {
	printf("Hello ");
}

// Matrix addition
Matrix	addMat(Matrix _A, Matrix _B)
{
	if (_A.rows != _B.rows || _A.cols != _B.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'addMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}

	Matrix Out = createMat(_A.rows, _B.cols);
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _B.cols; j++)
			Out.at[i][j] = _A.at[i][j] + _B.at[i][j];

	return Out;
}

// Apply back-substitution
Matrix	backSub(Matrix _A, Matrix _b)
{
	Matrix Out = createMat(_b.rows, 1);

	// error check: whether _A is a triangular matrix
	for (int i = _A.rows-1; i >= 0; i--) {
		double temp = 0;
		for (int j = i + 1; j < _A.cols; j++)
			temp += _A.at[i][j] * Out.at[j][0];
		Out.at[i][0] = (_b.at[i][0] - temp) / _A.at[i][i];
	}

	return Out;
}


// Return the dy/dx results for the target equation. (truncation error: O(h^2))
Matrix	gradientFunc(double func(const double x), Matrix xin) {

	int n = xin.rows;

	Matrix yin = createMat(n, 1);
	for (int i = 0; i < n; i++)
		yin.at[i][0] = func(xin.at[i][0]);

	return gradient(xin, yin);
}


// Return the dy/dx results for the input data. (truncation error: O(h^2))
Matrix	gradient(Matrix _x, Matrix _y) {

	if (_x.rows != _y.rows || _x.rows < 3) {
		printf("ERROR: The number of elements in x must be the same as in y.\n");
		return createMat(0, 0);
	}

	else {
		int n = _x.rows;
		Matrix dydx = createMat(n, 1);
		double h = _x.at[1][0] - _x.at[0][0];

		dydx.at[0][0] = (-3 * _y.at[0][0] + 4 * _y.at[1][0] - _y.at[2][0]) / (2 * h);
		for (int i = 1; i < n - 1; i++)
			dydx.at[i][0] = (_y.at[i + 1][0] - _y.at[i - 1][0]) / (2 * h);
		dydx.at[n - 1][0] = (_y.at[n - 3][0] - 4 * _y.at[n - 2][0] + 3 * _y.at[n - 1][0]) / (2 * h);

		return dydx;
	}
}