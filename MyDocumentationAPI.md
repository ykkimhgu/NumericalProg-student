`#include "myNM.h"`

# Non-Linear Solver

## bisectionNL()

Solves the non-linear problem using bisection method

```c
double bisectionNL(double _a0, double _b0, double _tol);
```

#### Parameters

- **a0** is initial value.
- **b0** is initial value.
- **tol** is Tolerance error.

#### Example code

```c
 double tol = 0.00001;
 double a0 = 1.9;
 double b0 = 2.5; 
 double BM_result;

BM_result = bisectionNL(a0, b0, tol);
```





# Non-Linear Solver

## newtonRaphson()

### Parameter

### Example code

```C++
 double tol = 0.00001;
 double a0 = 1.9;
 double b0 = 2.5; 
 double BM_result;

BM_result = bisectionNL(a0, b0, tol);
```

 



