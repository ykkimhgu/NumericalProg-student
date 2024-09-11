/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 17-05-2021
Modified         : 17-05-2023
Language/ver     : C++ in MSVS2019

Description      : [Tutorial] Integration_student.cpp
-------------------------------------------------------------------------------*/

#include "stdio.h"
#include "stdlib.h"

//#include "../../include/myNP_myID.h"

// Sample Code: Integration rectangular method 
double IntegrateRect(double x[], double y[], int m);

// You need to create myFunc() in this main source file
double myFunc(const double x);


// You need to create the followins in  in myNP.h. myNP.cpp
// double trapz (double x[ ], double y[ ], int m);
// double simpson13(double x[ ], double y[ ], int m);
// double integral(double func(const double x), double a, double b, int n);  


int main(int argc, char* argv[])
{
	
	printf("\n**************************************************");
	printf("\n        PART 1. Integration from Datasets         ");
	printf("\n**************************************************\n");

	/************      Variables declaration & initialization      ************/
	double x[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
	double y[] = { 0, 3, 8, 20, 33, 42, 40, 48, 60, 12, 8, 4, 3 };
	int M = sizeof(x) / sizeof(x[0]);



	/************      Solve  &	Show Output	   ************/
	double I_rect = IntegrateRect(x, y, M);
	printf("I_rect  = %f\n", I_rect);

	// Exercise 1. Trapezoid
	double I_trapz = 0;
	// [YOUR CODE HERE]
	// I_trapz=trapz()
	printf("I_trapz = %f\n\n", I_trapz);


	// Exercise 2. Simpson
	double I_simpson = 0;
	// [YOUR CODE HERE]
	// I_simpson13=simpson13()
	printf("I_simpson13  = %f\n\n", I_simpson13);
	

	
	
	printf("\n**************************************************");
	printf("\n        PART 2. Integration from a Function       ");
	printf("\n**************************************************\n");
	
	// Exercise 3. Integral
	double I_function = 0;
	// [YOUR CODE HERE]
	// I_function=integral()
	printf("I_function  = %f\n\n", I_function);

	system("pause");
	return 0;
}




// Sample Code: Integration rectangular method 
double IntegrateRect(double x[], double y[], int m) {
	int N = m - 1;
	double I = 0;
	for (int i = 0; i < N; i++)
		I += y[i] * (x[i + 1] - x[i]);
	return I;
}
