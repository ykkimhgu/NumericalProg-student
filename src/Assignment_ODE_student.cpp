/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : 01-04-2019
Modified        : 01-04-2024
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Assignment 8 ODE IVP
/------------------------------------------------------------------------------------------*/

#define ASGN	8		// enter your assignment number
#define EVAL	0		// set 0


/*------------------------------------------------------------------------------------------*/
/*			MODIFY Path and name of Headerfiles										 		*/
/*------------------------------------------------------------------------------------------*/
#include "../../include/myNP.h"
#include "../../include/myMatrix.h"



/*------------------------------------------------------------------------------------------*/
/*			MOVE the following  #define to  myNP.h									 		*/
/*------------------------------------------------------------------------------------------*/
#define PI 3.14159265368979323846264338327950288412



/*------------------------------------------------------------------------------------------*/
/*			DEFINE ode model functions here											 		*/
/*------------------------------------------------------------------------------------------*/
// Problem1: RC circuit
double odeFunc_rc(const double t, const double v);

// Problem2: m-c-k system
void odeFunc_mck(double dYdt[], const double t, const double Y[]);



/*------------------------------------------------------------------------------------------*/
/*			MOVE ode function declations to myNP.h									 		*/
/*------------------------------------------------------------------------------------------*/

// 1st order ODE
void odeEU(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);
void odeRK2(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init);
void odeRK3(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y0);

// 2nd order ODE
void sys2RK2(double y1[], double y2[], void odeFuncSys(double dYdt[], const double t, const double Y[]), const double t0, const double tf, const double h, const double y1_init, const double y2_init);





int main(int argc, char* argv[])
{
/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 1:  1st order ODE-IVP (single equation)			*/
	/*--------------------------------------------------------------------------*/
	/*   - A simple RC circuit response to sinusoidal voltage input				*/
	/*   - You can change the variable names									*/
	/*   - You can create additional functions									*/
	/*==========================================================================*/


	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/
	// Initial Conditions
	double a = 0;
	double b = 0.1;
	double h = 0.001;


	unsigned int N = ((b - a) / h) + 1;
	double y_EU[200] = { 0 };				//Cannot use sytanx of  y_EU[N]={0};	
	double y_RK2[200] = { 0 };
	double y_RK3[200] = { 0 };

	// IVP initial values
	double y_init = 0;


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// Euler's Explicit Method (given)
	odeEU(y_EU, odeFunc_rc, a, b, h, y_init);

	//  Runge-Kutta 2nd order
	odeRK2(y_RK2, odeFunc_rc, a, b, h, y_init);

	//  Runge-Kutta 3rd order
	odeRK3(y_RK3, odeFunc_rc, a, b, h, y_init);



	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/

	// Print outputs
	printf("----------------------------------------------------------------\n");
	printf("			       1st ODE - IVP  Results						\n");
	printf("----------------------------------------------------------------\n");

	printf("i\t t\t\t yEU\t\t yRK2\t\t yRK3\t \n\n");
	for (int i = 0; i < N; i++)
		printf("%d\t %0.5f\t %.5f\t %.5f\t %.5f\t \n", i, a + i * h, y_EU[i], y_RK2[i], y_RK3[i]);
	printf("\n");


/*------------------------------------------------------------------------------------------*/

	/*==========================================================================*/
	/*					Part 2:  2nd order ODE-IVP								*/
	/*--------------------------------------------------------------------------*/
	/*   - A simple m-c-k  response to sinusoidal force input					*/
	/*   - You can change the variable names									*/
	/*   - You can create additional functions									*/
	/*==========================================================================*/

	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/
	//Parameter Definitions
	double t0 = 0;
	double tf = 1;
	h = 0.01;
	N = (tf - t0) / h + 1;
	double Y[200] = { 0 };
	double V[200] = { 0 };

	// Initial values
	double y_initQ2 = 0;
	double v_initQ2 = 0.2;


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	//  Runge-Kutta 2nd order
	sys2RK2(Y, V, odeFunc_mck, t0, tf, h, y_initQ2, v_initQ2);


	// Extra: Runge-Kutta 4th order
	//sys2RK4(Y, V, odeFunc_mck, t0, tf, h, y_initQ2, v_initQ2);


	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/
	//
	printf("----------------------------------------------------------------\n");
	printf("			       2nd order ODE - IVP  Results					\n");
	printf("----------------------------------------------------------------\n");

	printf("i\t t\t\t Y\t\t V\t\t \n\n");
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]



	system("pause");
	return 0;
}


/*------------------------------------------------------------------------------------------*/



/*==========================================================================*/
/*							  Function Definitions							*/
/*==========================================================================*/

// Gradient function for ODE - 1st order 
double odeFunc_rc(const double t, const double v)
{
	// Input:	 y, t
	// Output:	 dydt 

	// system modeling parameters 
	double tau = 0.01;
	double f = 100;
	double Vm = 1;
	double omega = 2 * PI * f;
	double dvdt = 0;

	// output
	// [YOUR CODE GOES HERE]	
	// dvdt =_______________
	
	return dvdt;
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





/*------------------------------------------------------------------------------------------*/
/*			MOVEfunction definitions to  myNP.cpp								 		*/
/*------------------------------------------------------------------------------------------*/



void odeEU(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init)
{
// 
// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
// 
	// Variable Initialization
	int N = (tf - t0) / h + 1;

	//Initial Condition
	double ti = t0;
	y[0] = y_init;

	// Euler Explicit ODE Method
	for (int i = 0; i < N - 1; i++) {
		ti += h;
		y[i + 1] = y[i] + odeFunc(ti, y[i]) * h;
	}
}


void odeRK2(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y_init)
{
// 
// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
// 

	// Variable Initialization
	int N = (tf - t0) / h + 1;
	double y2 = 0;
	double t2 = 0;

	// Initial Condition
	double ti = t0;
	y[0] = y_init;

	// RK Design Parameters
	double C1 = 0.5;
	double C2 = 1 - C1;
	double alpha = 1;
	double beta = alpha;
	double K1 = 0, K2 = 0;

	// RK2 ODE Solver
	for (int i = 0; i < N - 1; i++) {

		// [First-point Gradient]
		K1 = odeFunc(ti, y[i]);

		// [Second-point Gradient]
		// Calculate t2=t(i)+alpha*h
		// [YOUR CODE GOES HERE]	
		// t2 =_______________
		
		// Calculate y2 = y(i) + beta * K1 * h
		// [YOUR CODE GOES HERE]	
		// y2 =_______________
		
		// Calculate: K2   using t2 and y2
		// [YOUR CODE GOES HERE]	
		// K2 =_______________


		// Estimate: y(i+1) using RK2 
		// [YOUR CODE GOES HERE]	
		// y[i + 1] =_______________

		ti += h;
	}
}



void odeRK3(double y[], double odeFunc(const double t, const double y), const double t0, const double tf, const double h, const double y0)
{
// 
// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
// 
	// Variable Initialization
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	

	// Initial Condition	
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	

	// RK Design Parameters
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	


	// RK3 ODE
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	

}


// ODE RK2 for 2nd order ODE 
void sys2RK2(double y1[], double y2[], void odeFuncSys(double dYdt[], const double t, const double Y[]), const double t0, const double tf, const double h, const double y1_init, const double y2_init)
{
// 
// [BRIEF DESCRIPTION OF THE FUNCTION  GOES HERE]
// 

	// Variable Initialization
	int N = (tf - t0) / h + 1;
	double ti = t0;

	// Initial Condition	
	y1[0] = y1_init;
	y2[0] = y2_init;

	// RK Design Parameters
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	
	// Examples:
		//double K1[2] = { 0 };
		//double K2[2] = { 0 };
		//double Yin[2] = { 0 };
		// ....  



	// RK2 ODE for 2nd ODE
	// [YOUR CODE GOES HERE]	
	// [YOUR CODE GOES HERE]	


}

