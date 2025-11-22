/*----------------------------------------------------------------\
@ Numerical Programming by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 26-03-2018
Modified         : 14-10-2024
Language/ver     : C++ in MSVS2019

Description      : myMatrix.h
----------------------------------------------------------------*/

#ifndef		_MY_MATRIX_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_MATRIX_H

#include <iostream>
#include <string>
#include <fstream>

typedef struct { 
	double** at;
	int rows, cols;
}Matrix;


// Create Matrix with specified size
extern	Matrix	createMat(int _rows, int _cols);

// initialization of Matrix elements
extern	void	initMat(Matrix _A, double _val);

// Free a memory allocated matrix
extern	void	freeMat(Matrix _A);

// Copy matrix
extern	Matrix	copyMat(Matrix _A);

// Copy matrix Elements from A to B
extern	void	copyVal(Matrix _A, Matrix _B);

// Create a matrix from a text file
extern	Matrix	txt2Mat(std::string _filePath, std::string _fileName);

// Create a matrix from 1D-array
extern Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);  

// Print matrix
extern	void	printMat(Matrix _A, const char* _name);

// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);



//////////////////////////////////////////////////////////////////
/*							Tutorial							*/
//////////////////////////////////////////////////////////////////


// Create matrix of all zeros
extern	Matrix	zeros(int _rows, int _cols);

// Create matrix of all ones
extern	Matrix	ones(int _rows, int _cols);

// Create identity matrix
extern	Matrix	eye(int _rows, int _cols);


// Matrix subtraction
extern	Matrix	subMat(Matrix _A, Matrix _B);

// Multiply  matrix A and matrix B
extern	Matrix	multMat(Matrix _A, Matrix _B);

// Multiply  matrix A with a scalar k
extern	Matrix	smultMat(Matrix _A, double _k);

// Create Transpose matrix
extern	Matrix	transpose(Matrix _A);



#endif

