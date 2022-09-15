/*------------------------------------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Name	        : Your Name Goes Here
ID		        : Your ID  Goes Here
Created         : 07-03-2019

Language/ver    : C /  MSVS2017
Course          : Numerical Programming 2022
Description     : Assignment of Non-linear solver
/------------------------------------------------------------------------------------------*/



#include "stdio.h"
#include "stdlib.h"
#include <math.h>

#include "../../../myNP.h"


double func(double x);
double dfunc(double x);

void main() {

	
	/*==========================================================================*/
	/*               Assignment -     Newton Rhapson                            */
	/*==========================================================================*/
	
	/************      Variables declaration & initialization      ************/
	double sol_nr;
	double x0 = 3;

	printf("------------------------------------------------------------------------------------\n");
	printf("         Newton-Raphson Method Results             \n");
	printf("------------------------------------------------------------------------------------\n");

	/************      Solve  &		Show Output			           ************/
	printf("Newton-Raphson Method Result:\n");
	sol_nr = newtonRaphson(func, dfunc, x0, tol);

	printf("Final Solution: %f \t", sol_nr);
	printf("\n");


	system("pause");
}




/*==========================================================================*/
/*						Function Definitions								*/			
/*==========================================================================*/


double func(double x) 
{
	
	double F = 0;	
	// [TO-DO] YOUR CODE GOES HERE
	return F;
}


double dfunc(double x)
{
	double dF = 0;
	// [TO-DO] YOUR CODE GOES HERE
	return dF;
}

