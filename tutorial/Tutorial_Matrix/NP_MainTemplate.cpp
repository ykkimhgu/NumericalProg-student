/*-------------------------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 07-10-2021
Language/ver     : C++ in MSVS2019

Description      : NP_MainTemplate.cpp
-------------------------------------------------------------------------------*/

#define Assignment	2		// enter your assignment number
#define eval		0		// set 0

#include "myNP.h"

int main(int argc, char* argv[])
{
	/*	 [¡Ø DO NOT EDIT IT !!!]   Resources file path setting for evaluation	*/
	std::string path = "C:/NP_data_2021/Assignment" + std::to_string(Assignment) + "/";

#if eval
	path += "eval/";
#endif

	/*==========================================================================*/
	/*					Variables declaration & initialization					*/
	/*--------------------------------------------------------------------------*/
	/*   - You can change the variable names									*/
	/*   - However, you must use the specified file name						*/
	/*	   : For each assignment, the file name will be notified on HISNET		*/
	/*==========================================================================*/
	Matrix matA = txt2Mat(path, "prob1_matA");
	Matrix vecb = txt2Mat(path, "prob1_vecb");
	Matrix matU = txt2Mat(path, "prob1_matU");
	Matrix vecd = txt2Mat(path, "prob1_vecd");
	Matrix vecx_true = txt2Mat(path, "prob1_vecx_true");


	/*==========================================================================*/
	/*					Apply your numerical method algorithm					*/
	/*==========================================================================*/
	// enter your algorithm here
	// enter your algorithm here
	// enter your algorithm here
	Matrix matAdd = addMat(matA, matU); // example

	/// Q1
	//Matrix matTemp = createMat(matA.rows, matA.cols);
	//initMat(matTemp, 3.141592);

	/// Q2
	//Matrix matTemp2 = zeros(matA.rows, matA.cols);

	/// Q3
	//Matrix vecx_backsub = backSub(matU, vecd);	// example


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
	//printMat(vecx_backsub, "x from backSub(U, d)");
	//printMat(vecx_true, "x_true");


	/*==========================================================================*/
	/*							  Deallocate memory 							*/
	/*==========================================================================*/
	freeMat(matA);		freeMat(vecb);
	freeMat(matU);		freeMat(vecd);		freeMat(vecx_true);
	freeMat(matAdd);


	system("pause");
	return 0;
}