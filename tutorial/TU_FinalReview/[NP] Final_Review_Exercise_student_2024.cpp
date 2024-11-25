/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : YK KIM
Created          : 25-NOV-2024
Language/ver     : C++ in MSVS2022

Description      : [NP] Final Review Exercise
-------------------------------------------------------------------------------*/



#include "../../include/myNP.h"
#include "../../include/myMatrix.h"

void odeFunc_mck(const double t, const double Y[], double dYdt[]);
double odeFunc_rc(const double t, const double v);


int main()
{
/*==========================================================================*/
/*					EX. Linear System
/*==========================================================================*/

		/************      Variables declaration & initialization      ************/
	double arrA[] = { 0.5, -0.5, 0, 0, 0.87, 0.87,0, 0, 0,0,1,0,0,0,0,1 };	
	double arrB[] = { 0,-10,-5.75 * cos(PI / 3), 5.75 * sin(PI / 3) };

	Matrix matA = arr2Mat(arrA, 4, 4);
	Matrix vecb = arr2Mat(arrB, 4, 1);
	Matrix vecx = zeros(4, 1);

		
	// [TO-DO]  YOUR NP CODE GOES HERE   
	// solveLinear() 


	printf("\n**************************************************");
	printf("\n|                   Question 1.                  |");
	printf("\n**************************************************\n");

	printMat(matA, "A");
	printMat(vecb, "b");
	printMat(vecx, "solution x");


	/************      Deallocate Memory							     ************/
	freeMat(matA);	
	// free more matrices



	/*==========================================================================*/
	/*					EX. EigenValue
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double k = 800;
	double c = 200;
	double m = 10;
	double arrA2[] = { 0, 1, -k / m, -c / m };
	Matrix A = zeros(2, 2);
	Matrix A_Eig = zeros(2, 2);
	Matrix A_EigVec = zeros(2, 2);

	A = arr2Mat(arrA2, 2, 2);

	// [TO-DO]  YOUR NP CODE GOES HERE  
	// eig();
	// eigVec();


	printf("\n**************************************************");
	printf("\n|                   Question 2.                  |");
	printf("\n**************************************************\n");

	printf("Eigenvalue:\n\t");
	printMat(A, "Matrix A");
	printMat(A_Eig, "EigenValue");
	printMat(A_EigVec, "EigenVector");

	/************      Deallocate Memory							     ************/
	freeMat(A);
	freeMat(A_Eig);
	freeMat(A_EigVec);
	// free more matrices





	/*==========================================================================*/
	/*					EX. ODE 1st order
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double a = 0;
	double b = 15;
	double h_ode1 = 1;
	double v_RK[200] = { 0 };
	double vinit = 11.91;
	int mtest = 1;

	// YOUR NP ALGORITHM GOES HERE	
	// ode()


	printf("\n**************************************************");
	printf("\n|                   Question 3.                  |");
	printf("\n**************************************************\n");

	printf("ODE RC:\n\t at t=%0.1f \t V=%0.6f \t\n", h_ode1 * mtest, v_RK[mtest]);
	printf("\n\n");




	/*==========================================================================*/
	/*					EX. ODE 2nd order
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double t0 = 0;
	double tf = 1;
	double h = 0.01;
	// [TO-DO]  YOUR CODE GOES HERE  
	// initiation of variables



	// [TO-DO]  YOUR NP CODE GOES HERE  
	// sysRK2()



	printf("\n**************************************************");
	printf("\n|                   Question 4.                  |");
	printf("\n**************************************************\n");

	// print your result
	//printf("ODE MCK:\n\t at t=%0.1f \t y=%0.6f \t v=%0.6f\n", h * ntest, y[ntest], v[ntest]);
	printf("\n\n");






	/*==========================================================================*/
	/*					EX. Linear Regression
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	int n_x = 15;

	double arrX[] = { 1, 2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14,	15 };
	double arrY[] = { 2.272,	2.092,	1.887,	1.629,	1.482,	1.308,	1.030,	0.875,	0.693,	0.470,	0.336,	0.095, -0.163, -0.371, -0.511 };

	Matrix vecT = zeros(n_x, 1);
	vecT = arr2Mat(arrX, n_x, 1);
	Matrix vecV = zeros(n_x, 1);
	vecV = arr2Mat(arrY, n_x, 1);
	Matrix Zopt = zeros(n_x, 1);



	// [TO-DO]  YOUR NP CODE GOES HERE  
	// polyfit()
	

	// print your result
	printf("Linear Regression:\n\t a0=%0.3f \t a1=%0.3f \n", Zopt.at[1][0], Zopt.at[0][0]);	
	printf("\n\n");


	/************      Deallocate Memory							     ************/
	freeMat(Zopt);	freeMat(vecT); freeMat(vecV);


	/*==========================================================================*/
	/*					EX. Exponential Curve-Fit
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	
	double arrT[] = { 1, 2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14,	15 };
	double arrV[] = { 9.7 8.1 6.6 5.1 4.4 3.7 2.8 2.4 2.0 1.6 1.4 1.1 0.85 0.69 0.6 };

	// [TO-DO]  YOUR NP CODE GOES HERE  
	// [TO-DO]  YOUR NP CODE GOES HERE  


	// print your result
	//printf("Exponential Curvefit :\n\t a0=%0.3f \t a1=%0.3f \n", Zopt.at[1][0], Zopt.at[0][0]);
	//printf("\n\n");


	system("pause");
	return 0;
}




// Gradient function for ODE - 2nd order 
void odeFunc_mck(double dYdt[], const double t, const double Y[])
{
	// Input:	 vecY = [y; v], t
	// Output:	 dYdt = [dydt; dvdt]

	// system modeling parameters 
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	


	// output
	// [YOUR CODE GOES HERE]	
	// dYdt[0] =_______________

	// [YOUR CODE GOES HERE]	
	// dYdt[1] =_______________
}


// Gradient function for ODE - 1st order 
double odeFunc_rc(const double t, const double v)
{
	// Input:	 y, t
	// Output:	 dydt 

	// system modeling parameters 
	double Vm = 11.91;
	double dvdt = 0;
	// [YOUR CODE GOES HERE]	
	// tau =_______________
	
	
	// output
	// [YOUR CODE GOES HERE]	
	// dvdt =_______________

	return dvdt;
}






//// Create a matrix from 1D-array
//Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
//{
//	Matrix Output = createMat(_rows, _cols);
//
//	for (int i = 0; i < _rows; i++)
//		for (int j = 0; j < _cols; j++)
//			Output.at[i][j] = _1Darray[i * _cols + j];
//
//	return Output;
//}
