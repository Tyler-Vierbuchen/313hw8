#include "Matrixcpp.h"

int main(){
    /*
    //used to test the matrix constructor and print function
    Matrix mat1(2,2);

    mat1.Print();

    //tests add function
    Matrix mat2(2,2);

    Matrix added = mat2.AddMatrices(mat1);
    
    added.Print();

    //tests multiplication between two matrices
    Matrix multiplied = mat2.MultiplyMatrices(mat1);

    multiplied.Print();

    cout << "-----------" <<endl;

    //tests multiplication between a matrix and an int
    Matrix multiplied2 = mat2.MultiplyByInt(5);

    multiplied2.Print();

    cout << "-----------" <<endl;

    //tests the transposed function
    Matrix mat3(2,3);

    mat3.Print();

    cout << "-----------" <<endl;

    Matrix transposed = mat3.TransposeMatrix();

    transposed.Print();

    cout << "-----------" <<endl;
     */

    //Assignment test for matrices D = A + (3*B) + C^T
    Matrix A(2,2);
    A.Print();
    Matrix B(2,3);
    B.Print();
    Matrix C(2,3);
    C.Print();

    cout << "-----------" <<endl;

    Matrix D = A.AddMatrices((B.MultiplyByInt(3)).MultiplyMatrices(C.TransposeMatrix()));

    D.Print();

    return 0;
}