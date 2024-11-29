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


double myLossEx1(double x);
double myLossGradEx1(double x);

double myLossEx2(Matrix Z);
Matrix myLossGradEx2(Matrix Z);



void main() {

	/*==========================================================================*/
	/*					EX. 1.  See TU_GradientDescent.mlx
	/*==========================================================================*/

	printf("----------------------------------------------------------------------------------------------\n");
	printf("			           EX.1										\n");
	printf("----------------------------------------------------------------------------------------------\n");

	
	/************      Variables declaration & initialization      ************/

	int itrMax = 10;
	double	eta= 0.25;
	int k = 0;
	double grad_e = 0;
	double x = 0;	
	double loss = 0;

	// Initial Condition
	x = 0;

	/************      Gradient Descent							     ************/

	for (k = 0; k < itrMax; k++) {
		grad_e = myLossGradEx1(x);
		
		// [TO-DO]  YOUR CODE GOES HERE
		// update x as  x=x-eta*gradL 
		// x =______________;		

		loss = myLossEx1(x);
		printf("iter =%d \t x=%0.3f \t L(x)=%0.3f\n", k, x, loss);				
	}

	printf("\n\n");




	/*==========================================================================*/
	/*					EX. 2.  See TU_GradientDescent.mlx
	/*==========================================================================*/

	printf("----------------------------------------------------------------------------------------------\n");
	printf("			           EX.2										\n");
	printf("----------------------------------------------------------------------------------------------\n");


	/************      Variables declaration & initialization      ************/

	itrMax = 10;	
	eta = 0.25;	
	Matrix grad_L;
	Matrix Z;
	Matrix H=zeros(2, 1);
	loss = 0;

	// Initial Condition
	double z0[] = { -2,-2 };	
	Z = arr2Mat(z0, 2, 1);

	
	/************      Gradient Descent							     ************/

	for (k = 0; k < itrMax; k++) {
		grad_L = myLossGradEx2(Z);		
		
		// [TO-DO]  YOUR CODE GOES HERE
		// update Z as  Z=Z+H, where H=-eta*gradL 
		
		// H =______________;		
		// Z =______________;		

		loss = myLossEx2(Z);
		printf("iter =%d \t x=%0.3f \t y=%0.3f \t L(x)=%0.3f\n", k, Z.at[0][0], Z.at[1][0], loss);
	}

	printf("\n\n");


	///*==========================================================================*/
	///*							  Deallocate memory 						*/
	///*==========================================================================*/
	
	freeMat(grad_L);	freeMat(Z);		freeMat(H); 	

	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/
/*==========================================================================*/

double myLossEx1(double x) {
	double L= x * x - 4 * x + 6;
	return L;
}

double myLossGradEx1(double x) {
	
	double dL = 0;
	// [TO-DO] YOUR CODE GOES HERE
	//  dL=_______

	
	return dL;
}

double myLossEx2(Matrix Z) {

	double L = 0;
	int n = Z.rows;
	double z1 = Z.at[0][0];
	double z2 = Z.at[1][0];

	// [TO-DO] YOUR CODE GOES HERE
	//  L=_______
	
		
	return L;
}


Matrix myLossGradEx2(Matrix Z) {
		
	int n = Z.rows;
	Matrix dL = zeros(n, 1);

	double z1 = Z.at[0][0];
	double z2 = Z.at[1][0];
	
	// [TO-DO] YOUR CODE GOES HERE
	//	dL = [6 * (Z(1) - 2);
	//		  2 * (Z(2) - 2)];
	

	//dL.at[0][0] =_____________;
	//dL.at[1][0] =_____________;
	
	return dL;
};


