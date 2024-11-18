/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : Jan-04-2019
Modified        : Nov-18-2024
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Assignment 9 Curvefitting
/------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*/
/*			MODIFY Path and name of Headerfiles										 		*/
/*------------------------------------------------------------------------------------------*/
#include "../../include/myNP_2024.h"
#include "../../include/myMatrix_2024.h"




/*------------------------------------------------------------------------------------------*/
/*			MOVE the followings  to  myNP.h									 		*/
/*------------------------------------------------------------------------------------------*/
// Calculates coefficients of least squares regression - Line
void linearFit(double vecZ[], double vecX[], double vecY[], int dataL);

// Calculates coefficients of least squares regression - Nth order polynomial
void polyFit(double vecZ[], double vecX[], double vecY[], int dataL, int orderN);

// [YOUR COMMENT]
//void expFit(double vecZ[], double vecX[], double vecY[], int dataL);


// Option 2:. Delete the below if you selected to use 1D arrays
// It will be much easier to use Option 2
/*
Matrix	linearFit_mat(Matrix _X, Matrix _Y);
Matrix	polyFit_mat(Matrix _vecX, Matrix _vecY, int n);
Matrix	expFit_mat(Matrix _X, Matrix _Y);
*/




/*------------------------------------------------------------------------------------------*/
/*			MOVE the following  to  myMatrix.h									 		*/
/*------------------------------------------------------------------------------------------*/
// Create a Matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);  // <-- move this to myMatrix.h, myMatrix.cpp


int main(int argc, char* argv[])
{
	/*------------------------------------------------------------------------------------------*/
		/*==========================================================================*/
		/*					Part 1-1:  Polyfit(line)								*/
		/*--------------------------------------------------------------------------*/
		/*   - order n=1 linearFit													*/
		/*==========================================================================*/


		/*==========================================================================*/
		/*						Initialization										*/
		/*==========================================================================*/

		// Initial Conditions
	double T[] = { 30, 40, 50, 60, 70, 80,90 };
	double P[] = { 1.05, 1.07, 1.09, 1.14, 1.17, 1.21 };
	double Z_Q1[2] = { 0 };
	int orderN = 1;	// nth order
	int m_Q1 = 6;	// length of dataset
	int mx = 0; int my = 0;


	// Is length(X)~= length(Y) ? Exit: Continue 
	mx = sizeof(T) / sizeof(T[0]);
	my = sizeof(P) / sizeof(P[0]);
	printf("Q1: mx=%d \t my=%d \n\r", mx, my);
	if (my != mx) {
		printf("[ERROR] X and Y have different length!! \n\r");
		return 0;
	}



	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// Option 1: using 1D array
	orderN = 1;
	polyFit(Z_Q1, T, P, m_Q1, orderN);

	// Print output
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]



	// Option 2	
	/*
	Matrix matT = arr2Mat(T, m_Q1, 1);
	Matrix matP = arr2Mat(P, m_Q1, 1);
	Matrix vecZ_Q1 = polyFit_mat(matT, matP, orderN);
	printMat(vecZ_Q1, "Z_Q1");
	*/


	/*------------------------------------------------------------------------------------------*/
		/*==========================================================================*/
		/*					Part 1-2:  Polyfit(nth )								*/
		/*--------------------------------------------------------------------------*/
		/*   - order n=2 or higher, polyfit											*/
		/*==========================================================================*/


		/*==========================================================================*/
		/*						Initialization										*/
		/*==========================================================================*/

		// Initial Conditions
	int m_Q2 = 16;				// data length
	double Stress[] = { 0, 3, 4.5, 5.8, 5.9, 5.8, 6.2, 7.4, 9.6, 15.6, 20.7, 26.7,31.1, 35.6, 39.3, 41.5 };
	double Strain[16] = { 0 };
	for (int k = 0; k < m_Q2; k++)
		Strain[k] = 0.4 * k;


	// Is length(X)~= length(Y) ? Exit: Continue 
	// [YOUR CODE GOES HERE]
	// mx = _________;
	// my = __________;
	printf("Q2: mx=%d \t my=%d \n\r ", mx, my);
	if (my != mx) {
		printf("[ERROR] X and Y have different length!! \n\r");
		return 0;
	}


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/

	// Option 1: using 1D array
	orderN = 4;	// nth order
	double Z_Q2[5] = { 0 };		// 4th order - a0 to a4
	polyFit(Z_Q2, Strain, Stress, m_Q2, orderN);

	// Print output
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]


	// Option 2	
	/*
	Matrix matStrain = arr2Mat(Strain, m_Q2, 1);
	Matrix matStress = arr2Mat(Stress, m_Q2, 1);
	Matrix vecZ_Q2 = polyFit_mat(matStrain, matStress, n);
	printMat(vecZ_Q2, "Z_Q2");
	*/






	/*------------------------------------------------------------------------------------------*/
		/*==========================================================================*/
		/*					Part 2:  Exponential fit								*/
		/*--------------------------------------------------------------------------*/
		/*   yhat=a0*exp(a1*t)														*/
		/*   														*/
		/*==========================================================================*/

		/*==========================================================================*/
		/*						Initialization										*/
		/*==========================================================================*/
		// [YOUR CODE GOES HERE]
		// [YOUR CODE GOES HERE]
		// [YOUR CODE GOES HERE]

		/*==========================================================================*/
		/*					Apply your numerical method algorithm					*/
		/*==========================================================================*/
		// [YOUR CODE GOES HERE]
		// [YOUR CODE GOES HERE]
		// [YOUR CODE GOES HERE]



	system("pause");
	return 0;
}



/*------------------------------------------------------------------------------------------*/


/*==========================================================================*/
/*					Function Definitions:  [MOVE] to myNP.h								*/
/*--------------------------------------------------------------------------*/

// [YOUR COMMENT GOES HERE]
void linearFit(double vecZ[], double vecX[], double vecY[], int dataL) {

	// Initialization	
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;

	// Check m = length(X) and length(Y)
	// Is length(X)~= length(Y) ? Exit: Continue 
	// NOTE: 
	//		int mx = sizeof(vecX) / sizeof(vecX[0]); // <-- Does not work inside a function
	//		You need to pass the dataLength as an argument. 
	//		OR you can use Option 2:  Matrix structure

	// Solve for Sx, Sxx, Sy, Sxy, 	
	// [YOUR CODE GOES HERE]


	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z = [a0, a1]
	vecZ[0] = a0;
	vecZ[1] = a1;
}

// [YOUR COMMENT GOES HERE]
void polyFit(double vecZ[], double vecX[], double vecY[], int dataL, int orderN) {

	// Initialization	
	double a1 = 0;
	double a0 = 0;
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]


	// Check m = length(X) and length(Y)
	// Is length(X)~= length(Y) ? Exit: Continue 
	// NOTE: 
	//		int mx = sizeof(vecX) / sizeof(vecX[0]); // <-- Does not work inside a function
	//		You need to pass the dataLength as an argument. 
	//		OR you can use Option 2:  Matrix structure


	// If n=1, use linearFit
	if (orderN == 1)
	{
		linearFit(vecZ, vecX, vecY, dataL);
		return;
	}



	// Solve for Sx, Sxx, Sy, Sxy, 	
	// [YOUR CODE GOES HERE]


	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z 

}

/*
// [OPTION 2]

// Returns the parameters of the linear least square function.
Matrix	linearFit_mat(Matrix _vecX, Matrix _vecY) {

	// Initialization
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;


	// Check m = length(X) and length(Y)
	int mx = _vecX.rows;
	int my = _vecY.rows;

	// Is length(X)~= length(Y) ? Exit: Continue
	// [YOUR CODE GOES HERE]

	// Solve for Sx, Sxx, Sy, Sxy,
	// [YOUR CODE GOES HERE]


	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z = [a0, a1]
	double z_array[] = { a0, a1 };
	return arr2Mat(z_array, 2, 1);
}


// [YOUR COMMENT GOES HERE]
Matrix	polyFit_mat(Matrix _vecX, Matrix _vecY, int n) {

	// Initialization
	Matrix vecZ = createMat(n + 1, 1);

	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	return vecZ;
}

*/




/*==========================================================================*/
/*					Function Definitions:  [MOVE] to myMatrix.h				*/
/*--------------------------------------------------------------------------*/

// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
	Matrix Output = createMat(_rows, _cols);

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			Output.at[i][j] = _1Darray[i * _cols + j];

	return Output;
}