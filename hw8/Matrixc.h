#ifndef MATRIXC_H
#define MATRIXC_H

    typedef struct{
      //the number of rows and columns for a matrix and the array representing the matrix
     int matrixWidth;
     int matrixHeight;
     int** matrix;
    }Matrix;

    //function to make a matrix
    Matrix MakeMatrix(int, int);

    //a destructor like function
    void FreeMatrix(Matrix);

    //a function to add two matrices together
    Matrix AddMatrices(Matrix, Matrix);

    //a function to multiply to matricies
    Matrix MultiplyMatrices(Matrix, Matrix);

    //a function to multiply a matricx and an int
    Matrix MultiplyByInt(int, Matrix);

    //a function to transpose a matrix
    Matrix TransposeMatrix(Matrix);

    //used to print the contents of a matrix
    void Print(Matrix);

#endif