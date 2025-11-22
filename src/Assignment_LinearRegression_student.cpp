/*------------------------------------------------------------------------------------------\
@ Numerical Programming  by Young-Keun Kim - Handong Global University

Author          : Young-Keun Kim
Created         : Jan-04-2019
Modified        : Nov-18-2025
Language/ver	: C in MSVS2017
Course			: Numerical Programming

Description     : Assignment 9 Linear Regression
/------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*/
/*			MODIFY Path and name of Headerfiles										 		*/
/*------------------------------------------------------------------------------------------*/
#include "../../include/myNP_2024.h"
#include "../../include/myMatrix_2024.h"


/*------------------------------------------------------------------------------------------*/
/*			MOVE the followings  to  myNP.h									 		*/
/*------------------------------------------------------------------------------------------*/
// Calculates coefficients of least squares regression - Line
void linearRegression (double z_opt[], double xdata[], double ydata[], int dataN) ;

// [COMMENT GOES HERE]
void expRegression(double z_opt[], double xdata[], double ydata[], int dataN) ;




int main(int argc, char* argv[])
{
/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 1-1:  Linear Regression (line)						*/
	/*--------------------------------------------------------------------------*/
	/*   - order n=1 linearFit													*/
	/*==========================================================================*/


	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/

	// Initial Conditions
	double L[] = { 1,     2,     3,     4,     5,     6,     7,     8,     9,    10 };
	double V[] = {3.7897,    6.3118,    9.2534,   10.6665,   13.0796,   15.6108,   18.5669,   21.0461,   23.3253,   25.4691 };
	double Z_Q1[2] = { 0 };
	double vout = 0;
	int orderN = 1;	// nth order	
	int m_Q1 = 10;	// length of dataset 
	
	// Check Is length(X)~= length(Y) ? Exit: Continue 
	int mx = sizeof(L) / sizeof(L[0]);
	int my = sizeof(V) / sizeof(V[0]);
	if (my != mx) {
		printf("[ERROR] X and Y have different length!! \n\r");
		return 0;
	}

	/*==========================================================================*/
	/*					Apply your numerical algorithm							*/
	/*==========================================================================*/

	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
			
	printf("----------------------------------------------------------------\n");
	printf("\t\t Part 1: Linear Regression (Line)							\n");
	printf("----------------------------------------------------------------\n");
	printf("Z_Q1= [a0=%.3f, a1=%.3f] \n\n\r", Z_Q1[0], Z_Q1[1]);
	printf("Estimated V(L=10N)= %.3f \n\n\r", vout);

	

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
	/*==========================================================================*/
	/*					Part 2:  Exponential fit								*/
	/*--------------------------------------------------------------------------*/
	/*   yhat=a0*exp(a1*t)														*/
	/*   																		*/
	/*==========================================================================*/

	/*==========================================================================*/
	/*						Initialization										*/
	/*==========================================================================*/
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]

	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]

	system("pause");
	return 0;
}





/*------------------------------------------------------------------------------------------*/


// [YOUR COMMENT GOES HERE]
void linearRegression(double z_opt[], double xdata[], double ydata[], int dataN){
	// Initialization	
	double Sx = 0;
	double Sxx = 0;
	double Sxy = 0;
	double Sy = 0;
	double a1 = 0;
	double a0 = 0;

	// Is length(X)~= length(Y) ? Exit: Continue 
	// NOTE: 
	//		int mx = sizeof(vecX) / sizeof(vecX[0]); // <-- Does not work inside a function
	
	// Solve for Sx, Sxx, Sy, Sxy, 	
	// [YOUR CODE GOES HERE]

	// Solve for a1, a2
	// [YOUR CODE GOES HERE]

	// Return z = [a0, a1]
	z_opt[0] = a0;
	z_opt[1] = a1;
}



// [YOUR COMMENT GOES HERE]
void expRegression(double z_opt[], double xdata[], double ydata[], int dataN) {
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
	// [YOUR CODE GOES HERE]
}