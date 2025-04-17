#include "Matrixc.h"
#include <stdlib.h>
#include <stdio.h>
//function to make a matrix
Matrix MakeMatrix(int height, int width){
    Matrix matrix;
    matrix.matrixHeight = height;
    matrix.matrixWidth = width;

    // Allocate memory
    matrix.matrix = (int**)malloc(matrix.matrixHeight * sizeof(int*));
    for (int i = 0; i < matrix.matrixHeight; i++) {
        matrix.matrix[i] = (int*)malloc(matrix.matrixWidth * sizeof(int));
    }

    //asks user to set the values of the matrix
    for(int i = 0; i < matrix.matrixHeight; i++){
        for(int j = 0; j < matrix.matrixWidth; j++){
            printf("Enter Matrix Values:\n");
            scanf("%d", &matrix.matrix[i][j]);
        }
    }

    return matrix;
}

//a destructor like function
void FreeMatrix(Matrix mat) {
    if (mat.matrix != NULL) {
        for (int i = 0; i < mat.matrixHeight; i++) {
            if (mat.matrix[i] != NULL) {
                free(mat.matrix[i]);
            }
        }
        free(mat.matrix);
        mat.matrix = NULL;
    }
    mat.matrixHeight = 0;
    mat.matrixWidth = 0;
}

//a function to add matricies
Matrix AddMatrices(Matrix mat1, Matrix mat2) {
    //only adds if the matrices have the same dimensions
    if ((mat1.matrixHeight == mat2.matrixHeight) && (mat1.matrixWidth == mat2.matrixWidth)) {
        
        Matrix added;
        added.matrixHeight = mat1.matrixHeight;
        added.matrixWidth = mat1.matrixWidth;

        //allocate new memory for the result matrix
        added.matrix = (int**)malloc(added.matrixHeight * sizeof(int*));
        for (int i = 0; i < added.matrixHeight; i++) {
            added.matrix[i] = (int*)malloc(added.matrixWidth * sizeof(int));
        }

        //add the matricies together and store the values
        for (int i = 0; i < added.matrixHeight; i++) {
            for (int j = 0; j < added.matrixWidth; j++) {
                added.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
            }
        }

        return added;
    } else {
        printf("Can't add matrices\n");
        exit(1);
    }
}

//multiply two matrices
Matrix MultiplyMatrices(Matrix mat1, Matrix mat2) {

    if(mat1.matrixWidth != mat2.matrixHeight){
        printf("Can't multiply matrices\n");
        exit(1);
    }

    Matrix multiplied; 
    multiplied.matrixHeight = mat1.matrixHeight;
    multiplied.matrixWidth = mat2.matrixWidth;

    // Allocate memory
    multiplied.matrix = (int**)malloc(multiplied.matrixHeight * sizeof(int*));
    for (int i = 0; i < multiplied.matrixHeight; i++) {
        multiplied.matrix[i] = (int*)malloc(multiplied.matrixWidth * sizeof(int));
    }

    // Perform matrix multiplication
    for (int i = 0; i < multiplied.matrixHeight; i++) {
        for (int j = 0; j < multiplied.matrixWidth; j++) {
            multiplied.matrix[i][j] = 0; 
            for (int k = 0; k < mat1.matrixWidth; k++) { 
                multiplied.matrix[i][j] += mat1.matrix[i][k] * mat2.matrix[k][j];
            }
        }
    }

    return multiplied; 
}

Matrix MultiplyByInt(int value, Matrix mat){
    //only adds if the matrices have the same dimensions
    if ((mat.matrix)) {
        
        Matrix multiplied;
        multiplied.matrixHeight = mat.matrixHeight;
        multiplied.matrixWidth = mat.matrixWidth;

        //allocate new memory for the result matrix
        multiplied.matrix = (int**)malloc(multiplied.matrixHeight * sizeof(int*));
        for (int i = 0; i < multiplied.matrixHeight; i++) {
            multiplied.matrix[i] = (int*)malloc(multiplied.matrixWidth * sizeof(int));
        }

        //add the matricies together and store the values
        for (int i = 0; i < multiplied.matrixHeight; i++) {
            for (int j = 0; j < multiplied.matrixWidth; j++) {
                multiplied.matrix[i][j] = mat.matrix[i][j] * value;
            }
        }

        return multiplied;
    } else {
        printf("Can't multiply an empty matrix");
        exit(1);
    }
}

//function to tanspose a matrix
Matrix TransposeMatrix(Matrix mat){
    if(mat.matrix){

        Matrix transposed;

        transposed.matrixHeight = mat.matrixWidth;
        transposed.matrixWidth = mat.matrixHeight;
    
        //allocate new memory for the result matrix
        transposed.matrix = (int**)malloc(transposed.matrixHeight * sizeof(int*));
        for (int i = 0; i < transposed.matrixHeight; i++) {
            transposed.matrix[i] = (int*)malloc(transposed.matrixWidth * sizeof(int));
        }

        for(int i = 0; i < transposed.matrixHeight; i++){
            for(int j = 0; j < transposed.matrixWidth; j++){
                transposed.matrix[i][j] = mat.matrix[j][i];
            }
        }

        return transposed;

    }
    else{
        printf("matrix is empty\n");
        exit(1);
    }
}

//used to print a matrix
void Print(Matrix mat){
    if(mat.matrix){
        for(int i = 0; i < mat.matrixHeight; i++){
            for(int j = 0; j < mat.matrixWidth; j++){
            printf( "[");
            printf( "%d", mat.matrix[i][j] );
            printf( "] ");
            }
            printf("\n");
        }
    }
    else{
        printf("Empty matrix\n");
    }
}