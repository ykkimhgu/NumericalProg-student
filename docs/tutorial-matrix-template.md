# Tutorial: Matrix Template





 

# Preparation 

# 

## Download

Download data files:  [NP_Matrix_TemplateCode_Data.zip](https://github.com/ykkimhgu/NumericalProg-student/blob/main/tutorial/NP_Matrix_TemplateCode_Data.zip) 

Download tutorial source files:  [NP_Matrix_TemplateCode_Src.zip](https://github.com/ykkimhgu/NumericalProg-student/blob/main/tutorial/NP_Matrix_TemplateCode_Src.zip)





## Create Data Folder

Create a folder in **C:\\** Drive and name the folder as `NP_Matrix_Data`

* **C:\NP_Matrix_Data**

  

Unzip the data files and copy them in the data folder

e.g.

![NP_Matrix_Data_Example_img](https://github.com/ykkimhgu/NumericalProg-student/blob/main/docs/NP_Matrix_Data_example.png?raw=true)



## Create Project

Create a new empty project in Visual Studio Community. Name the project as **TU_MatrixTemplate**

* **e.g ) C:\Users\yourID\source\repos\NP\tutorial\TU_MatrixTemplate**

  



Create a new C/C++ source file for main()

* Name the source file as `TU_matrixTemplate.cpp`

* Unzip the downloaded source files

* Paste from the following code:   [TU_matrixTemplate.cpp](https://github.com/ykkimhgu/NumericalProg-student/blob/main/tutorial/TU_integration_student.cpp)




## Using Template

Notice of the **text file** and **file name** of the matrix required along with the assignment.

```txt
[File Path]
    C:/NP_Matrix_Data/Assignment3

[File Name]
Q1.
    matrix A : prob1_matA
    vector b : prob1_vecb
Q2.
    matrix A : prob2_matA
    vector b : prob2_vecb
Q3.
    matrix A : prob3_matA
    vector b : prob3_vecb
```

#### Make Text File

![file_explorer_img](https://github.com/ykkimhgu/NumericalProg-student/blob/main/docs/file_explorer_img.png?raw=true)

#### Write Text File

* Change Row : **Enter**
* Change Column: **Tap**

> Notice: Regardless of number length

e.g. write matrix

![matrix_text_file_example](https://github.com/ykkimhgu/NumericalProg-student/blob/main/docs/matrix_text_file.png?raw=true)

e.g. write vector

![vector_text_file_example](https://github.com/ykkimhgu/NumericalProg-student/blob/main/docs/vector_text_file.png?raw=true)

#### Code Structure

1. Initially, you should outline your code and fix your assignment number.

    ```C
    /*-------------------------------------------------------------------------------\
    @ Numerical Programing by Young-Keun Kim - Handong Global University

    Author           : [YOUR NAME]
    Created          : 26-03-2018
    Modified         : 19-10-2023
    Language/ver     : C++ in MSVS2019

    Description      : NP_MainTemplate.cpp
    -------------------------------------------------------------------------------*/
    #define ASGN 3      // Enter your assignment number
    #define eval 0      // [% DO NOT EDIT IT %] set 0

    #include "myMatrix.h"

    int main(int argc, char* argv[])
    {
        // [% DO NOT EDIT IT %] Resource file path setting for evaluation
        string path = "C:/NP_Matrix_Data/Assignment" + to_string(ASGN) + "/";

    #if eval
        path += "eval/";
    #endif

        ...

    ```

2. Declare a variable based on the given file name.
And then apply your algorithm.

    ```C++
        ...

        /*==========================================================================*/
        /*                  Variables declaration & initialization                  */
        /*--------------------------------------------------------------------------*/
        /*   - You can change the variable names                                    */
        /*   - However, you must use the specified file name                        */
        /*     : For each assigment, the file name will be notified on LMS          */
        /*==========================================================================*/
        Matrix matA = txt2Mat(path, "prob1_matA");
        Matrix vecb = txt2Mat(path, "prob1_vecb");

        /*==========================================================================*/
        /*                  Apply your numerical method algorithm                   */
        /*==========================================================================*/
        // enter your algorithm here
        // enter your algorithm here
        // enter your algorithm here

        ...
    ```

3. Prints the results. You must clearly state what value the result is for.

    ```C
        ...

        /*==========================================================================*/
        /*                          Print your results                              */
        /*==========================================================================*/
        printMat(matA, "Problem 1, Matrix A");
        printMat(vecb, "Problem 1, Vector b");

        ...
    ```

4. Frees memory allocated to a matrix or array.
Even if you omit it, the code will work,
but if you run it multiple times,
data corruption may occur due to a memory leak.
Free memory if possible.

    ```C
        ...

        /*==========================================================================*/
        /*                          Deallocate memory                               */
        /*==========================================================================*/
        freeMat(matA);
        freeMat(vecb);

        return 0;
    }
    ```

---



# Tutorial & Exercise

Go to   **\tutorial** Directory 

* **e.g ) C:\Users\yourID\source\repos\NP\tutorial**


  

Declare and define the following functions in  `myMatrix.h` and  `myMatrix.cpp`



```c++
// initialization of Matrix elements
extern	void	initMat(Matrix _A, double _val);

// Create matrix of all zeros
extern	Matrix	zeros(int _rows, int _cols);

// Create matrix of all ones
extern	Matrix	ones(int _rows, int _cols);

// Multiply matrix A to B
extern	Matrix	multMat(Matrix _A, Matrix _B);

// Create identity 
extern	Matrix	eye(int _rows, int _cols);

// Create Transpose matrix
extern	Matrix	transpose(Matrix _A);

// Copy matrix
extern	Matrix	copyMat(Matrix _A);

// Copy matrix Elements from A to B
extern	void	copyVal(Matrix _A, Matrix _B);
```




---



