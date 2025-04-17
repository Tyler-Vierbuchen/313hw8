#include "Matrixc.h"
#include <stdio.h>

int main(){
    /*
    //tests making a matrix and printing it
    Matrix mat1;
    mat1 = MakeMatrix(2,2);

    Print(mat1);

    //test the add function
    Matrix mat2;
    mat2 = MakeMatrix(2,2);

    Matrix added = AddMatrices(mat1,mat2);

    Print(added);

    printf("-----------\n");

    //tests multiplication between two matrices
    Matrix multiplied = MultiplyMatrices(mat1,mat2);

    Print(multiplied);

    printf("-----------\n");
    //test int multiplication
    Matrix multByInt = MultiplyByInt(3,mat1);

    Print(multByInt);

    printf("-----------\n");

    //test transpose
    Print(mat2);

    printf("-----------\n");
    
    Matrix transpose = TransposeMatrix(mat2);

    Print(transpose);



    FreeMatrix(mat1);
    FreeMatrix(mat2);
    FreeMatrix(added);
    FreeMatrix(multiplied);
    FreeMatrix(multByInt);
    FreeMatrix(transpose);
     */

    //test for assignment 
    Matrix A = MakeMatrix(2,2);
    Print(A);
    Matrix B = MakeMatrix(2,3);
    Print(B);
    Matrix C = MakeMatrix(2,3);
    Print(C);

    printf("-----------\n");

    Matrix Ctrans = TransposeMatrix(C);
    Matrix multB = MultiplyByInt(3, B);
    Matrix BtimesCtrans = MultiplyMatrices(multB, Ctrans);
    Matrix AplusBtimesC = AddMatrices(A, BtimesCtrans);
    Matrix D = AplusBtimesC;
    
    Print(D);

    FreeMatrix(A);
    FreeMatrix(B);
    FreeMatrix(C);
    FreeMatrix(D);
    FreeMatrix(Ctrans);
    FreeMatrix(multB);
    FreeMatrix(BtimesCtrans);
    
    return 0;
}