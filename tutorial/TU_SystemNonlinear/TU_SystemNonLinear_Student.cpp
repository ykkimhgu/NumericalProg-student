/*------------------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 11-27-2023
Language/ver	: C in MSVS2017
Course			: Numerical Programming 

Description     : TU System of NonLinear
/------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include <math.h>

#include "../../../include/myNP.h"
#include "../../../include/myMatrix.h"


// Goes to myNP.h
Matrix nonlinearSys(Matrix Funcs(Matrix _Z), Matrix Jacob(Matrix _Z), Matrix _Z0, double tol);


// Defined in main code
Matrix myFuncEx1(Matrix X);
Matrix myJacobEx1(Matrix X);
//Matrix myFuncEx2(Matrix X);
//Matrix myJacobEx2(Matrix X);



void main() {

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*	   : For each assignment, the file name will be notified on HISNET		*/
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double loss = 0;
	double n = 2;
	Matrix J = zeros(n, n);
	Matrix F = zeros(n, 1);
	Matrix H = zeros(n, 1);
	Matrix Z = zeros(n, 1);

	// Initial condition
	double z0[2] = { 2.5, 2 };
	Z = arr2Mat(z0, n, 1);



	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	printf("----------------------------------------------------------------------------------------------\n");
	printf("			            System of NonLinear													  \n");
	printf("----------------------------------------------------------------------------------------------\n\r");

	Z = nonlinearSys(myFuncEx1, myJacobEx1, Z, 0.001);
	printMat(Z, "Z");



	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(J);	freeMat(H);	freeMat(F); 	freeMat(Z);

	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/

Matrix myFuncEx1(Matrix X)
{
	int n = X.rows;
	Matrix F = zeros(n, 1);
	double x1 = X.at[0][0];
	double x2 = X.at[1][0];

	// [TO-DO] YOUR CODE GOES HERE
	// F.at[0][0] =_________________________
	F.at[1][0] = 9 * (x1) * (x1)+25 * x2 * x2 - 225;

	return F;
}


Matrix myJacobEx1(Matrix X)
{
	int n = X.rows;
	Matrix J = zeros(n, n);
	double x1 = X.at[0][0];
	double x2 = X.at[1][0];

	// [TO-DO] YOUR CODE GOES HERE
	//J.at[0][0] =_____________;
	//J.at[0][1] =_____________;
	//J.at[1][0] =_____________;
	J.at[1][1] = 50 * x2;


	return J;
}


Matrix nonlinearSys(Matrix Funcs(Matrix _Z), Matrix Jacob(Matrix _Z), Matrix _Z0, double tol) {
	// Initialization
	int n = _Z0.cols;
	double loss = 10;
	Matrix J = zeros(n, n);
	Matrix F = zeros(n, 1);
	Matrix H = zeros(n, 1);
	Matrix Z = zeros(n, 1);

	// Initial condition
	Z = _Z0;

	for (int k = 0; k < 20; k++) {
		F = Funcs(Z);
		J = Jacob(Z);

		// [TO-DO]  YOUR CODE GOES HERE
		// F =-1*F;
		// F=____________

		// [TO-DO]  YOUR CODE GOES HERE
		// Solve for H in  JH = (-F)	
		// H = ___________
		
		// [TO-DO]  YOUR CODE GOES HERE
		//	Z = Z + H;
		// Z=______________
		

		// After Z update, print loss
		F = Funcs(Z);

		// [TO-DO]  YOUR CODE GOES HERE
		// loss = norm2(F);   // sqrt((F.at[0][0])^2+(F.at[1][0])^2+...)


		printf("iter =%d \t x=%0.3f \t y=%0.3f \t loss=%0.3f\n", k, Z.at[0][0], Z.at[1][0], loss);

		if (loss < tol) {
			printf("Early Termination\n\r");
			return Z;
		}
	}
	return Z;
}
