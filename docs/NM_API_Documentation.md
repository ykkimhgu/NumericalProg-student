`#include "myNM.h"`



# Linear Solver

## gaussElim()

solves for vector **x** from  Ax=b,  a linear system problem  

```c
void	gaussElim(Matrix _A, Matrix _B, Matrix* _U, Matrix* _B_out);
```

#### **Parameters**

- **A**:  Matrix **A** in structure Matrix form.  Should be (nxn) square.

- **B**:  vector  **b** in structure Matrix form.  Should be (nx1) 

  

  

## solveLinear()

solves for vector **x** from  Ax=b,  a linear system problem  

```c
extern Matrix solveLinear(Matrix _A, Matrix _b, char* _method)
```

#### **Parameters**

- **A**:  Matrix **A** in structure Matrix form.  Should be (nxn) square.

- **b**:  vector  **b** in structure Matrix form.  Should be (nx1) 

- **method:  character type,** 

  - **'lu' :** LU decomposition
  - **'gauss':** Gauss elimination

  

#### Example code

```C
double A_array[] = { 1, 3, -2, 4,		2, -3, 3, -1,		-1, 7, -4, 2,		-1, 7, -4, 2 };
double b_array[] = { -11,		6,		-9,		15 };

Matrix matA = arr2Mat(A_array, M, N);
Matrix vecb = arr2Mat(b_array, M, 1);

Matrix x_lu = solveLinear(matA, vecb, "LU");
Matrix invA_gj = inv(matA, "gj");
Matrix invA_lu = inv(matA, "LU");
```





***



# Numerical Differentiation

## gradientFunc()

Solves for numerical gradient  (dy/dt) from  given equation

```c
Matrix gradientFunc(double func(double t), double xin);
```

#### Parameters

* **func**: a function as input argument 

## gradient()

Solves for numerical gradient  (dy/dt) from  a set of discrete data

```c
Matrix	gradient(Matrix _t, Matrix _y);
```

#### **Parameters**

- **t**:  vector **t** in structure Matrix form.  Should be (nx1) vector
- **y**:  vector  **y** in structure Matrix form.  Should be (nx1) vector and same length as t
- Returns **dydt** in structure Matrix form. Output is also (nx1) vector



#### Example code

```c
Matrix t = txt2Mat("", "Q1_vect");
Matrix x = txt2Mat("", "Q1_vecx");

Matrix vel = gradient(t, x);
Matrix acc = gradient(t, vel);

printMat(t, "t");
printMat(x, "x");
printMat(vel, "vel");
printMat(acc, "acc");
```

See full example code:  [TutorialDifferentiation.cpp](https://github.com/ykkimhgu/tutorial-NM/blob/main/samples/Tutorial-Differentiation.cpp)

