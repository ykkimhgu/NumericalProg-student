/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : Jan-04-2019
Modified        : Oct-30-2025
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Tutorial:  Eigenvalue,Eigenvector
------------------------------------------------------------------------------------------*/

#define ASGN	7		// enter your assignment number
#define EVAL	0		// set 0

// [ MODIFY Path and name of Headerfiles]
#include "../../include/myMatrix_2024.h"
#include "../../include/myNP_2024.h"


// [ TUTORIAL:  CREATE FUNCTIONS ]
// These must be in myMatrix.h, myMatrix.cpp
Matrix eigval_student(Matrix A);
void QRdecomp_student(Matrix _A, Matrix* _Q, Matrix* _R);
Matrix eigvec_student(Matrix A);

int main(int argc, char* argv[])
{
#if _WIN64 | _WIN32
	/*	 [воик DO NOT EDIT !!!]   Resources file path setting for evaluation	*/
	std::string path = "../../NP_Data/Assignment" + std::to_string(ASGN) + "/";
#elif __APPLE__
	//std::string path = "~/NP_Data/Assignment" + std::to_string(ASGN) + "/";
	std::string path = "../../NP_Data/Assignment" + std::to_string(ASGN) + "/";
#endif
#if EVAL
	path += "eval/";
#endif

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*		   : For each assignment, the file name will be notified			*/
	/*==========================================================================*/

	// Create a matrix from a 1D-array
	// Matrix matA_Q1 = txt2Mat(path, "prob1_matA");
	double arrayQ1[9] = { 45,30, -25, 30, -24, 68, -25, 68, 80 };

	int N = 3;
	Matrix	matA_Q1 = arr2Mat(arrayQ1, N, N); // NxN
	printMat(matA_Q1, "matA_Q1");

	Matrix eigVals_Q1 = createMat(N, 1);	// Nx1
	Matrix eigVecs_Q1 = createMat(N, N);	// NxN


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/

	// [Eigenval/vectors for Q1]
	eigVals_Q1 = eigval_student(matA_Q1);
	eigVecs_Q1 = eigvec_student(matA_Q1);


	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/

	printf("----------------------------------------------------------------------------------------------\n");
	printf("			       Eigenvalue & Eigenvector Results					\n");
	printf("----------------------------------------------------------------------------------------------\n");
	printf("\n[Eigen value]\n\n");
	printMat(eigVals_Q1, "Eigenvalue Q1");
	printf("\n[Eigen vector]\n\n");
	printMat(eigVecs_Q1, "Eigenvector Q1");
	printf("\n\n");


	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/

	// [Deallocate for Q1]
	freeMat(matA_Q1);
	freeMat(eigVals_Q1);
	freeMat(eigVecs_Q1);

	system("pause");
	return 0;
}



/*==========================================================================*/
/*							 User defined functions						*/
/*==========================================================================*/

// Create eigenvalue matrix:  Nx1
Matrix eigval_student(Matrix _A) {
	int N = _A.rows;
	Matrix Q = createMat(N, N);
	Matrix R = createMat(N, N);
	Matrix U = copyMat(_A);
	Matrix eigOut = zeros(N, 1);
	int itrMax = 200;

	// (OPTION) Check for Error	:  Dimension of A should be square 
	//							:  Should be  _A.rows==_A.cols  
	//if (_A.cols != _A.rows ) {
	//				Display Error Message 
	//				Exit Function
	//				[YOUR CODE GOES HERE]
	//}

	for (int i = 0; i < itrMax; i++) {
		// Step 1: A = QR decomposition
		// [Q, R] = QRdecomp_student(U); 
		// [YOUR CODE GOES HERE]
		
		// Step 2: Create Similar Matrix A = Q'AQ
		// U = R * Q;
		// [YOUR CODE GOES HERE]
		
		// (OPTION) You can add an exit condition
		//	Exit this loop if it is near triangular
		//  [YOUR CODE GOES HERE]
	}

	// Step 3: eigenvalues from U
	// lamdas = diag(U);
	//  [YOUR CODE GOES HERE]
	
	return eigOut;
}

// QR Factorization using HouseHold Matrix
// Input:	A(nxn)
// Output:	Q(nxn), R(nxn)
void QRdecomp_student(Matrix _A, Matrix* _Q, Matrix* _R)
{
	int N = _A.rows;
	Matrix I = eye(N, N);
	Matrix c = zeros(N, 1);
	Matrix e = zeros(N, 1);
	Matrix v = zeros(N, 1);
	Matrix H = zeros(N, N);

	// Local R, Q
	Matrix R = copyMat(_A);
	Matrix Q = copyMat(I);

	for (int j = 0; j < N - 1; j++) {
		//  Step 1. Create vector[c]
		//  [YOUR CODE GOES HERE]
		

		//	Step 2. Create vector[e]
		//  [YOUR CODE GOES HERE]


		//	Step 3. Create vector[v]
		//  [YOUR CODE GOES HERE]
		
		//	Step 4. Create matrix[H]
		//  [YOUR CODE GOES HERE]
		
		//	Step 5. Update[Q], [R]
		//  [YOUR CODE GOES HERE]

	}

	// Copy temporary R,Q to returning _R, _Q
	*_R = copyMat(R);
	*_Q = copyMat(Q);

	// Free R, Q
	freeMat(R);
	freeMat(Q);
}


Matrix eigvec_student(Matrix _A) {
	Matrix Aout = createMat(_A.rows, _A.cols);
	//  [YOUR CODE GOES HERE]
	//  [YOUR CODE GOES HERE]

	return Aout;
}