/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 01-04-2024
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Assignment 9 Curvefitting
/------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*/
/*			MODIFY Path and name of Headerfiles										 		*/
/*------------------------------------------------------------------------------------------*/
#include "../../include/myNP.h"
#include "../../include/myMatrix.h"




/*------------------------------------------------------------------------------------------*/
/*			MOVE the followings  to  myNP.h									 		*/
/*------------------------------------------------------------------------------------------*/
// Calculates coefficients of least squares regression - Line
void linearFit(double vecZ[], double vecX[], double vecY[]);
// Calculates coefficients of least squares regression - Nth order polynomial
void polyFit(double vecZ[], double vecX[], double vecY[], int n);

// Option 2:. Delete the below if you selected to use 1D arrays
Matrix	linearFit_mat(Matrix _X, Matrix _Y);
Matrix	polyFit_mat(Matrix _vecX, Matrix _vecY, int n);


//void expFit(double vecZ[], double vecX[], double vecY[]);
// or
//Matrix	expFit_mat(Matrix _X, Matrix _Y);


/*------------------------------------------------------------------------------------------*/
/*			MOVE the following  to  myMatrix.h									 		*/
/*------------------------------------------------------------------------------------------*/
// Create a Matrix from 1D-array
//Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);  // <-- move this to myMatrix.h, myMatrix.cpp


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
	double T[] = { 30, 40, 50, 60, 70, 80 };
	double P[] = { 1.05, 1.07, 1.09, 1.14, 1.17, 1.21 };
	double Z_Q1[2] = { 0 };
	int n = 1;	// nth order
	int m_Q1 = 6;	// length of dataset



	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// Option 1: using 1D array
	n = 1;
	polyFit(Z_Q1, T, P, n);
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]



	// Option 2	
	// Delete the below if you selected Option 1
	Matrix matT = arr2Mat(T, m_Q1, 1);
	Matrix matP = arr2Mat(P, m_Q1, 1);
	Matrix vecZ_Q1 = polyFit_mat(matT, matP, n);
	printMat(vecZ_Q1, "Z_Q1");



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
	double Stress[] = { 0, 3, 4.5, 5.8, 5.9, 5.8, 6.2, 7.4, 9.6, 15.6, 20.7, 26.7,31.1, 35.6, 39.3, 41.5};
	double Strain[16] = { 0 };
	for (int k = 0; k < m_Q2; k++)
		Strain[k] = 0.4 * k;
	double Z_Q2[4] = { 0 };		// 3th order - a0 to a3


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// Option 1: using 1D array
	n = 4;	// nth order
	polyFit(Z_Q2, Strain, Stress, n);

	// Print results
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]



	// Option 2	
	// Delete the below if you selected Option 1
	Matrix matStrain = arr2Mat(Strain, m_Q2, 1);
	Matrix matStress = arr2Mat(Stress, m_Q2, 1);
	Matrix vecZ_Q2 = polyFit_mat(matStrain, matStress, n);
	printMat(vecZ_Q2, "Z_Q2");





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

void linearFit(double vecZ[], double vecX[], double vecY[]){

	// Initialization	
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;


	// Check m = length(X) and length(Y)
	int mx = sizeof(vecX) / sizeof(vecX[0]); 
	// [YOUR CODE GOES HERE]
	// int my = _______________

	// Is length(X)~= length(Y) ? Exit: Continue 
	// [YOUR CODE GOES HERE]


	// Solve for Sx, Sxx, Sy, Sxy, 	
	// [YOUR CODE GOES HERE]


	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z = [a0, a1]
	vecZ[0] = a0;
	vecZ[1] = a1;
}


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



void polyFit(double vecZ[], double vecX[], double vecY[],int n) {

	// Initialization	
	double a1 = 0;
	double a0 = 0;
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]



	// If n=1, use linearFit
	if (n == 1)
	{
		linearFit(vecZ, vecX, vecY);
		return;
	}


	// Check m = length(X) and length(Y)
	int mx = sizeof(vecX) / sizeof(vecX[0]);
	// [YOUR CODE GOES HERE]
	// int my = _______________

	// Is length(X)~= length(Y) ? Exit: Continue 
	// [YOUR CODE GOES HERE]


	// Solve for Sx, Sxx, Sy, Sxy, 	
	// [YOUR CODE GOES HERE]


	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z 
	
}

Matrix	polyFit_mat(Matrix _vecX, Matrix _vecY, int n) {

	// Initialization	
	Matrix vecZ= createMat(n+1,1);

	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	return vecZ;
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