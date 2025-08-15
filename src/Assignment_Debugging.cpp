/*----------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : Your Name Goes Here (20500000)
Created          : 08-30-2024
Modified         : 08-30-2024
Language/ver     : C++ in MSVS2022

Description      : [Assingment] Common Debbuging
----------------------------------------------------------------*/

#include <stdio.h>
#include "NP_debugging_header.h"



/////////////////////////////////////////////////////////
//					Function Declaration
/////////////////////////////////////////////////////////

int sum_int(int a, int b);


/////////////////////////////////////////////////////////
//					MAIN Function
/////////////////////////////////////////////////////////


int main() {
	int a = 1;
	int b = 2;
	int c = 3;


	printf("a= %d,  b= %d \n", a, b);
	printf("sum is %f\n", sum_int(a, b));
	printf("difference is %d\n", subtract_int(a, b));


	int vecA[3] = { 1,2,4 };
	int num = 4;
	int vecB[num] = { 0 };

	for (int j = 0; j < 4; j++) {
		printf("vecA[%d]= %d \n\t", j, vecA[j]);
	}


	return 0;
}


/////////////////////////////////////////////////////////
//					Function Definition
/////////////////////////////////////////////////////////

// Sum of two intergers
int sum_int(int a, int b) {
	int sum = a + b;
	return sum;
}

// Subtract two integers
int subtract_int(int a, int b) {
	return a - b;
}

