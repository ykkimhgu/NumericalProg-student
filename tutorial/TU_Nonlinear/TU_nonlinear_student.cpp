/*------------------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 07-03-2019
Modified        : 03-01-2021
Language/ver    : C /  MSVS2017
Course          : Numerical method 2021-Spring
Description     : Tutorial of Bisection Method
/------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include <math.h>
//#include "../../include/myNP.h"


// Move function declaration to  `myNP.h`
double bisection(float _a0, float _b0, float _tol);  
double newtonRaphson(double _x0, double _tol);
double func(double x);
double dfunc(double x);



void main() {

	/*==========================================================================*/
	/*               Tutorial -     Bisection Method                            */
	/*==========================================================================*/

	/************      Variables declaration & initialization      ************/
	double tol = 0.00001;
	double a0 = 2;			//need to change initial value
	double b0 = 3;			//need to change initial value
	double sol_bm=0;

	/************      Solve  &		Show Output			           ************/
	printf("------------------------------------------------------------------------------------\n");
	printf("         Bisection Method Results             \n");
	printf("------------------------------------------------------------------------------------\n");

	printf("Bisection Method:\n");
	sol_bm = bisection(a0, b0, tol);

	printf("Final Solution: %f \t", sol_bm);
	printf("\n");



	/*==========================================================================*/
	/*               Assignment -     Newton Rhapson                            */
	/*==========================================================================*/
	
	/************      Variables declaration & initialization      ************/
	double sol_nr=0;
	double x0 = 3;

	printf("------------------------------------------------------------------------------------\n");
	printf("         Newton-Raphson Method Results             \n");
	printf("------------------------------------------------------------------------------------\n");

	/************      Solve  &		Show Output			           ************/
	printf("Newton-Raphson Method Result:\n");
	sol_nr = newtonRaphson(x0, tol);

	printf("Final Solution: %f \t", sol_nr);
	printf("\n");


	system("pause");
}




/*==========================================================================*/
/*                    Function Definitions		   		*/			
/*==========================================================================*/
//

// Move these function definitions to  `myNP.c`

/* function f(x) of the problem */
double func(double x) 
{
	
	double F = 0;
	// F = 8 - 4.5 * (x - sin(x));
	// [TO-DO] YOUR CODE GOES HERE
	return F;
}

/* first derivative of function f(x) of the problem */
double dfunc(double x)
{
	double dF = 0;
	// dF =  -4.5 * (1 - cos(x));
	// [TO-DO] YOUR CODE GOES HERE
	return dF;
}



/* Bisection Method
	_a      : initial value #1
	_b      : initial value #2
	_tol   : tolerance   
*/
double bisection(float _a0, float _b0, float _tol) 
{
	// Define Bisection function, assuming (func(a) * func(b) <0 )
	// Initialization
	int k = 0;
	int Nmax = 100;
	float a = _a0;
	float b = _b0;
	float xn = 0;
	float ep = 1000;

	// Bisection 
	while (k<Nmax && ep>_tol){
		// Update xn as midpoint
		// [TO-DO] YOUR CODE GOES HERE
		
		// Update range a, b
		// [TO-DO] YOUR CODE GOES HERE
		
		// Check tolerance
		// [TO-DO] YOUR CODE GOES HERE
		
		k++;

		printf("k:%d \t", k);
		printf("Xn(k): %f \t", xn);
		printf("Tol: %.8f\n", ep);
	} 
		
	return xn;
}



/* Newton-Raphson Method without Passing a Function  */
double newtonRaphson(double _x0, double _tol)
{
	float xn = _x0;
	float xn1 = 0;
	float ep = 1000;
	int Nmax = 1000;
	int k = 0;
	double h = 0;
	while (k<Nmax && ep>_tol) {
		if (dfunc(xn) == 0)
		{
			printf("[ERROR] dF == 0 !!\n");
			break;
		}
		else
		{
		// get h=f/df @ x(k)
		// [TO-DO] YOUR CODE GOES HERE
		// h=__________;   

		// update x(k+1)=x(k)+h(k)
		// [TO-DO] YOUR CODE GOES HERE
		// xk=_____________;  

		// check tolerance
		// [TO-DO] YOUR CODE GOES HERE
		//ep=_____________;  % YOUR CODE GOES HERE 

		k++;

		printf("k:%d \t", k);
		printf("X(k): %f \t", xn);
		printf("Tol: %.10f\n", ep);

		}
	} 

	return xn;
}



