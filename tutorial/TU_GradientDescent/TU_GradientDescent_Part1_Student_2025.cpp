/*------------------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 12-08-2022
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : TU System of NonLinear - Solution
/------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include <math.h>

#include "../../include/myNP.h"


double myLossEx1(Matrix Z, Matrix X, Matrix Y);
Matrix myLossGradEx1(Matrix Z, Matrix X, Matrix Y);

double maxMat(Matrix A);
double minMat(Matrix A);
Matrix normalizeMat(Matrix A);
Matrix unnormMat(Matrix Z, Matrix X);


void main() {

	/*==========================================================================*/
	/*					EX. 1.  See TU_GradientDescent_Part1.mlx
	/*==========================================================================*/

	printf("----------------------------------------------------------------------------------------------\n");
	printf("			           EX.1										\n");
	printf("----------------------------------------------------------------------------------------------\n");


	/************      Variables declaration & initialization      ************/

	
	// Variables
	Matrix W = zeros(2, 1);
	Matrix H = zeros(2, 1);
	Matrix grad_L = zeros(2, 1);
	Matrix W_est = zeros(2, 1);		// 2x1

	double loss = 0;

	// Datasets
	double L_raw[] = { 30,	40,	50,	60,	70,	80 };
	double V_raw[] = { 1.05,	1.07,	1.09,	1.14,	1.17,	1.21 };
	Matrix L_raw = arr2Mat(L_raw, 6, 1);
	Matrix V_raw = arr2Mat(V_raw, 6, 1);
	Matrix L = normalizeMat(T_raw);
	Matrix V = copyMat(P_raw);
	
	printMat(L, "Lmat");
	printMat(V, "Vmat");

	// Design Parameter
	int N = L.rows;
	double eta = 0.1;
	int itrMax = 100;


	// Initial Condition
	double w0_ex1[] = {0,0};
	W = arr2Mat(w0_ex1, 2, 1);
	

	/************      Gradient Descent							     ************/
	for (int k = 0; k < itrMax; k++) {
		// Update w with Gradient Descent
		// [TO-DO]  YOUR CODE GOES HERE		
		grad_L = myLossGradEx1(W, L, V);		
		// W =______________;	

		// Calculate Loss
		loss = myLossEx1(W,L,V);
		printf("iter =%d \t x=%0.3f \t y=%0.3f \t L(x)=%0.3f\n", k, W.at[0][0], W.at[1][0], loss);
	}
	
	
	// Unormalize
	W_est = unnormMat(W, L_raw);
	printMat(W_est, "Final W");


	printf("\n\n");

	///*==========================================================================*/
	///*							  Deallocate memory 						*/
	///*==========================================================================*/
	
	freeMat(grad_L);	freeMat(W);		freeMat(H); 	
	freeMat(L_raw);		freeMat(V_raw);	freeMat(L); freeMat(V); freeMat(W_est);

	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


double myLossEx1(Matrix Z, Matrix X, Matrix Y) {
	int n = Z.rows;
	double a0 = Z.at[0][0];
	double a1 = Z.at[1][0];
	double r = 0;
	double L = 0;

	// [TO-DO] YOUR CODE GOES HERE
	//  L=(1/n*sum(r.^2))
	for (int k = 0; k < n; k++)
	{
		// [TO-DO] YOUR CODE GOES HERE
		//  r=____
		// [TO-DO] YOUR CODE GOES HERE
		//  L=____
	}
	

	return L;
}


Matrix myLossGradEx1(Matrix Z, Matrix X, Matrix Y) {
		
	double a0 = Z.at[0][0];
	double a1 = Z.at[1][0];
	double r = 0;

	Matrix dL = zeros(2, 1);
	
	int n = X.rows;

	
	// loss_grad = @(Z)[-2. / n.*(sum(r)) - 2. / n.*(sum(x * r)];
	for (int k = 0; k < n; k++)
	{
		// [TO-DO] YOUR CODE GOES HERE
		//  r=____
		
		// [TO-DO] YOUR CODE GOES HERE		
		//dL.at[0][0] =_____________;
		//dL.at[1][0] =_____________;

	}
		
	return dL;
}




double maxMat(Matrix A)
{
	// Finds the max value in matrix
	double max = A.at[0][0];
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			if (A.at[i][j] > max)
				max = A.at[i][j];
		}
	}
return max;
}

double minMat(Matrix A){
	// Finds the min value in matrix
	double min = A.at[0][0];
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			if (A.at[i][j] < min)			
				min = A.at[i][j];			
		}		
	}
return min;
}



Matrix normalizeMat(Matrix A) {
	// Normalize matrix from -1 to 0

	double max = maxMat(A);
	double min = minMat(A);
	double minMax = (max - min);
	int m = A.rows;
	int n = A.cols;

	Matrix A_norm = zeros(m,n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A_norm.at[i][j]= (A.at[i][j]- min)/minMax;

	return A_norm;
}


Matrix unnormMat(Matrix Z, Matrix X)
{
	double max = maxMat(X);
	double min = minMat(X);
	double minMax = (max - min);

	Matrix Z_un=zeros(2,1);
	
	Z_un.at[0][0] = Z.at[0][0] - Z.at[1][0] * min / minMax;
	Z_un.at[1][0] = Z.at[1][0] / minMax;

	return Z_un;
}