/*-------------------------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 19-10-2023
Language/ver     : C++ in MSVS2019

Description      : Tutorial code for using matrix structure
-------------------------------------------------------------------------------*/

#define ASGN		999		// enter your assignment number
#define EVAL		0		// [¡Ø DO NOT EDIT !!!]


#include "../../include/myMatrix.h"
#include "../../include/myNP.h"


int main(int argc, char* argv[])
{
#if _WINDOWS
	/*	 [¡Ø DO NOT EDIT !!!]   Resources file path setting for evaluation	*/
	std::string path = "C:/NP_Data/Assignment" + std::to_string(ASGN) + "/";
#elif __APPLE__
	std::string path = "~/NP_Data/Assignment" + std::to_string(ASGN) + "/";
#endif
	
#if EVAL
	path += "eval/";
#endif

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified txt file name					*/	
	/*==========================================================================*/
	
	// Option 1:  Read from datafile
	Matrix matA = txt2Mat(path, "prob1_matA");
	Matrix vecb = txt2Mat(path, "prob1_vecb");
	Matrix matU = txt2Mat(path, "prob1_matU");
	Matrix vecd = txt2Mat(path, "prob1_vecd");
	Matrix vecx_true = txt2Mat(path, "prob1_vecx_true");

	// Option 2:  Create an empty Matrix or Vector
	int rows = 4;
	int cols = 4;
	Matrix matC = createMat(rows, cols);
	Matrix vecy = createMat(rows, 1);
		
	// Option 3:  Create a zero matrix with specific size
	Matrix matD = zeros(matA.rows, matA.cols);
	
	
	// Your Code goes Here
	// Your Code goes Here




	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
		
	// Example:   Accessing each element in Matrix
	for (int i = 0; i < matA.rows; i++)
		for (int j = 0; j < matA.cols; j++)
			matC.at[i][j] = matA.at[i][j];


	// Exmaple: Applying your NP algorithm
	Matrix matAdd = addMat(matA, matU);


	// Your code goes Here
	// Your code goes Here

	


//////////////////////////////////////////////////////////////////
/*							Tutorial							*/
//////////////////////////////////////////////////////////////////
	
	/// Q1
	Matrix matTemp = createMat(matA.rows, matA.cols);
	//initMat(matTemp, 3.141592);

	/// Q2
	//Matrix matTemp2 = zeros(matA.rows, matA.cols);

	/// Q3
	//Matrix matTemp3 = ones(matA.rows, matA.cols);
	

	/// Q4
	//Matrix matTemp4 = multMat(matA, matU);


	/// Q5
	//Matrix matTemp5 = transpose(matA);



	/*==========================================================================*/
	/*							  Print your results							*/
	/*==========================================================================*/
	printMat(matA, "matA");
	printMat(vecb, "vecb");
	printMat(matU, "matU");
	printMat(vecd, "vecd");
	printMat(matAdd, "matU + matA");


	/// Q1
	//printMat(matTemp, "initMat result");

	/// Q2
	//printMat(matTemp2, "zeros result");

	/// Q3
	//printMat(matTemp3, "ones result");


	/// Q4
	//printMat(matTemp4, "A times U result");


	/// Q5
	//printMat(matTemp5, "A trasnpose result");






	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(matA);		freeMat(vecb);
	freeMat(matU);		freeMat(vecd);		freeMat(vecx_true);
	freeMat(matAdd);

	// free other  created  matrices


	system("pause");
	return 0;
}
