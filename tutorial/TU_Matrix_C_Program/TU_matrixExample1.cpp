#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../include/myMatrix_student.h"

Matrix myFunc(Matrix Z);
void myFunc2(Matrix Z, Matrix Mout);
void printAddress(Matrix Z, const char* name);

int main(int argc, char* argv[]) {
    int M = 3;
    int dim = 1;
    double z[3] = { 1, 2, 3 };

    printf("\n**************************************************");
    printf("\n|         Intiialization                         |");
    printf("\n**************************************************\n");

    // Initialize matrix Z
    Matrix Zinit = arr2Mat(z, M, dim);
    Matrix Z = createMat(M, 1);
    copyMatrix(Z, Zinit);
    printMat(Z, "Z is ");
    printAddress(Z, "Z is  ");
    

    printf("\n**************************************************");
    printf("\n|         Example 1 (return Matrix)              |");
    printf("\n**************************************************\n");
        
    Matrix M_out = zeros(Z.rows, Z.cols);
    printMat(M_out, "M_out is (before)");
    printAddress(M_out, "M_out  ");

    M_out = myFunc(Z);
    printf("\n[Main()]\n\r");
    printMat(M_out, "M_out is (after)");
    printAddress(M_out, "M_out (after)  ");
    printMat(Z, "Z is (after) ");




    printf("\n**************************************************");
    printf("\n|         Example 2  (void)                       |");
    printf("\n**************************************************\n");
    
    // Initialize matrix Z
    copyMatrix(Z, Zinit);
    
    Matrix M_out2 = zeros(Z.rows, Z.cols);
    printMat(M_out2, "M_out2 is (before)");
    printAddress(M_out2, "M_out2  ");

    myFunc2(Z, M_out2);
    printf("\n[Main()]\n\r");
    printMat(M_out2, "M_out2 is (after)");
    printAddress(M_out2, "M_out2 (after)  ");
    printMat(Z, "Z is (after) ");



    freeMat(Z);
    freeMat(M_out);
    freeMat(M_out2);

    system("pause");
    return 0;
}


Matrix myFunc(Matrix Z)
{    
    // Initialize Output Matrix
    int n = Z.rows;
    Matrix Mout = zeros(n, 1);
    Matrix Ztemp = zeros(n, 1);

    printf("\n[myFunc_Q1]\n\r");
    printAddress(Z, "Z in myFunc");
    printAddress(Mout, "Mout in myFunc ");
    
    // Copy Matrix  
    copyMatrix(Mout,Z);
    printAddress(Mout, "Mout in myFunc (after)");
    // Copy Matrix  
    copyMatrix(Ztemp, Z);

    // Modify Mout by your NP algorithm 
    Mout.at[1][0] = 20;

    // This also changes Z in main()
    Z.at[0][0] = 10;

    // This does not changes Z in main()
    Ztemp.at[0][0] = 100;

    return Mout;
}


void myFunc2(Matrix Z, Matrix Mout) 
{
    printf("\n[myFunc_Q2]\n");
    printAddress(Z, "Z in myFunc2");
    printAddress(Mout, "Mout in myFunc2");

    // Initialize Output Matrix by Copying    Z--> Mout
    copyMatrix(Mout, Z);
    printAddress(Mout, "Mout in myFunc (after)");

    // Modify Mout by your NP algorithm 
    Mout.at[1][0] = 20;

    // This also changes Z in main()
    Z.at[0][0] = 10;

    return;
}



void printAddress(Matrix Z, const char* name)
{
    printf("%s\n\r", name);
    //printf("  &Matrix.at[0][0] : %p\n\n", &Z.at[0][0]);
    //printf("  &Matrix struct   : %p\n\n\r", &Z);
    printf("  Matrix.at        : %p\n", Z.at);
}

