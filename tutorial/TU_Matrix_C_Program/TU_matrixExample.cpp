#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../../include/myMatrix_student.h"


void myNPfunc(Matrix L, Matrix U, Matrix Ain);
Matrix myNPfunc2(Matrix Ain, Matrix bin);


int main(int argc, char* argv[]) {
    
    printf("\n**************************************************");
    printf("\n|         Various Initialization methods          |");
    printf("\n**************************************************\n");

    // Method 1:  Initialize matrix Z from array
    int M = 3;
    int dim = 1;
    double z[3] = { 1, 2, 3 };
    Matrix Zinit = arr2Mat(z, M, dim);
    Matrix Z = createMat(M, 1);
    copyMatrix(Z, Zinit);
    printMat(Z, "Z is ");

    // Method 2:  Initialize by a constant
    int N = 3;
    Matrix Ain = createMat(N, N);
    initMat(Ain, 1);

    // Method 3:  Initialize with Zero matrix
    Matrix L = zeros(Ain.rows, Ain.cols);
    Matrix U = zeros(Ain.rows, Ain.cols);



    printf("\n**************************************************");
    printf("\n|       Example Code 1                          |");
    printf("\n**************************************************\n");
    
    printMat(Ain, "A is ");
    printMat(L, "L is ");
    printMat(U, "U is ");

    // Your Algorithm
    myNPfunc(L, U, Ain);

    printMat(Ain, "Ain is (after) ");
    printMat(L, "L is (after)");
    printMat(U, "U is (after)");
    


    printf("\n**************************************************");
    printf("\n|        Example Code 2                          |");
    printf("\n**************************************************\n");

    // Initialize matrix Ain    
    initMat(Ain, 1);

    Matrix Xin = zeros(Ain.cols, 1);
    Matrix Bin = zeros(Ain.rows, 1);
    printMat(Ain, "A is ");
    printMat(Bin, "Bin is ");

    // Your Algorithm
    Xin = myNPfunc2(Ain, Bin);

    printMat(Xin, "Xin is (after)");
    printMat(Ain, "Ain is (after) ");


    freeMat(Z); freeMat(Ain);
    freeMat(L); freeMat(U); freeMat(Ain);
    freeMat(Xin); freeMat(Bin);


    system("pause");
    return 0;
}



void myNPfunc(Matrix L, Matrix U, Matrix Ain) {

    // Initialize Output Matrix:   Ain--> U
    copyMatrix(U, Ain);
    initMat(L, 0);

    // Modify Mout by your NP algorithm 
    U.at[1][0] = 30;
    U.at[2][0] = 40;

    L.at[0][0] = 6;
    L.at[1][0] = 7;
    L.at[2][0] = 8;

    // This also changes Ain in main() !!!
    // You may NOT want to modify Ain.
    Ain.at[0][0] = 10;

    // This does not changes Ain in main()
    // For input A,  make a Copy to prevent modification
    Matrix Atemp = zeros(Ain.rows, Ain.cols);
    copyMatrix(Atemp, Ain);
    Atemp.at[0][0] = 100;

    return;
}

Matrix myNPfunc2(Matrix Ain, Matrix bin)
{
    // Initialize Output Matrix
    int n = Ain.cols;
    Matrix Xout = zeros(n, 1);


    // Modify Mout by your NP algorithm 
    Xout.at[1][0] = 11;
    Xout.at[2][0] = 12;

    // This also changes Ain in main() !!! 
    // You may NOT want to modify Ain.
    Ain.at[0][0] = 10;

    // This does not changes Ain in main() 
    // For input A,  make a Copy to prevent modification
    Matrix Atemp = zeros(Ain.rows, Ain.cols);
    copyMatrix(Atemp, Ain);
    Atemp.at[0][0] = 100;

    return Xout;
}
