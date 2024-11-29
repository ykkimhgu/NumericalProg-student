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




double myLossEx3(Matrix Z, Matrix X, Matrix Y);
Matrix myLossGradEx3(Matrix Z, Matrix X, Matrix Y);




//double maxMat(Matrix A);
//double minMat(Matrix A);

//Matrix unnormalizeMat(Matrix Z, Matrix X)
Matrix normalizeMat(Matrix A);
Matrix unnormMat(Matrix Z, Matrix X);


void main() {

	/*==========================================================================*/
	/*					EX. 3.  See TU_GradientDescent.mlx
	/*==========================================================================*/

	printf("----------------------------------------------------------------------------------------------\n");
	printf("			           EX.3										\n");
	printf("----------------------------------------------------------------------------------------------\n");


	/************      Variables declaration & initialization      ************/

	
	// Variables
	Matrix Z = zeros(2, 1);
	Matrix H = zeros(2, 1);
	Matrix grad_L = zeros(2, 1);
	Matrix Z_est = zeros(2, 1);		// 2x1

	double loss = 0;

	// Datasets
	double t_raw[] = { 30,	40,	50,	60,	70,	80 };
	double p_raw[] = { 1.05,	1.07,	1.09,	1.14,	1.17,	1.21 };
	Matrix T_raw = arr2Mat(t_raw, 6, 1);
	Matrix P_raw = arr2Mat(p_raw, 6, 1);
	Matrix T = normalizeMat(T_raw);
	Matrix P = copyMat(P_raw);
	
	printMat(T, "Tmat");
	printMat(P, "Pmat");

	// Design Parameter
	int N = T.rows;
	double eta = 0.1;
	int itrMax = 100;


	// Initial Condition
	double z0_ex3[] = {0,0 };
	Z = arr2Mat(z0_ex3, 2, 1);
	

	/************      Gradient Descent							     ************/
	for (int k = 0; k < itrMax; k++) {
		grad_L = myLossGradEx3(Z, T, P);

		// [TO-DO]  YOUR CODE GOES HERE
		// update Z as  Z=Z+H, where H=-eta*gradL 

		// H =______________;		
		// Z =______________;	



		loss = myLossEx3(Z,T,P);
		printf("iter =%d \t x=%0.3f \t y=%0.3f \t L(x)=%0.3f\n", k, Z.at[0][0], Z.at[1][0], loss);
	}
	
	
	// Unormalize
	Z_est = unnormMat(Z, T_raw);
	printMat(Z_est, "Final Z");


	printf("\n\n");

	///*==========================================================================*/
	///*							  Deallocate memory 						*/
	///*==========================================================================*/
	
	freeMat(grad_L);	freeMat(Z);		freeMat(H); 	
	freeMat(T_raw);		freeMat(P_raw);	freeMat(T); freeMat(P); freeMat(Z_est);

	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/


double myLossEx3(Matrix Z, Matrix X, Matrix Y) {
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


Matrix myLossGradEx3(Matrix Z, Matrix X, Matrix Y) {
		
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
			A_norm.at[i][j]= (A.at[i][j]- max)/minMax;

	return A_norm;
}


Matrix unnormMat(Matrix Z, Matrix X)
{
	double max = maxMat(X);
	double min = minMat(X);
	double minMax = (max - min);

	Matrix Z_un=zeros(2,1);
	
	Z_un.at[0][0] = Z.at[0][0] - Z.at[1][0] * max / minMax;
	Z_un.at[1][0] = Z.at[1][0] / minMax;

	return Z_un;
}