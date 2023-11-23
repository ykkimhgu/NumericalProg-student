/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : Jan Park
Created          : 10-05-2021
Modified         : 10-05-2021
Language/ver     : C++ in MSVS2019

Description      : [Tutorial]Differentiation.cpp
-------------------------------------------------------------------------------*/

#include "myNM.h"

// Define a function that defines the target equation.
double myFunc(const double x);

int main(int argc, char* argv[])
{

	// PART 1
	printf("\n**************************************************");
	printf("\n|                     PART 1.                    |");
	printf("\n**************************************************\n");

	Matrix t = txt2Mat("", "Q1_vect");
	Matrix x = txt2Mat("", "Q1_vecx");

	Matrix vel = gradient(t, x);
	Matrix acc = gradient(t, vel);

	printMat(t, "t");
	printMat(x, "x");
	printMat(vel, "vel");
	printMat(acc, "acc");


	// PART 2
	printf("\n**************************************************");
	printf("\n|                     PART 2.                    |");
	printf("\n**************************************************\n");

	Matrix xin = txt2Mat("", "Q2_vecxin");
	Matrix dydx = gradientFunc(myFunc, xin);

	printMat(xin, "xin");
	printMat(dydx, "dydx");
	

	system("pause");
	return 0;
}


// Define a function that defines the target equation.
double myFunc(const double x) {
	return  x * x * x;
}
