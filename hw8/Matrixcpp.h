#ifndef MATRIXCPP_H
#define MATRIXCPP_H

#include <iostream>
#include <string>
using namespace std;

class Matrix{
    public:
    //default constructor
    Matrix();

    //an overloaded constructor to build a matrix
    Matrix(int, int);

    //copy constructor
    Matrix(const Matrix&);

    //matrix destructor
    ~Matrix();

    //a function to add two matrices together
    Matrix AddMatrices(Matrix);

    //a function to multiply to matricies
    Matrix MultiplyMatrices(Matrix);

    //a function to multiply a matricx and an int
    Matrix MultiplyByInt(int);

    //a function to transpose a matrix
    Matrix TransposeMatrix();

    Matrix& operator=(const Matrix&);

    //used to print the contents of a matrix
    void Print();

    //mutators for the private fields
    void SetWidth(int);

    void SetHeight(int);

    void SetMatrix(int**);

    int GetWidth() const;

    int GetHeight() const;

    int** GetMatrix() const;

    private:
    //the number of rows and columns for a matrix and the array representing the matrix
    int m_matrixWidth;
    int m_matrixHeight;
    int** m_matrix;
};

#endif