#include "Matrixcpp.h"

//default constructor
Matrix::Matrix(){
    SetHeight(0);
    SetWidth(0);
}

//overloaded constructor
Matrix::Matrix(int height, int width){
    SetHeight(height);
    SetWidth(width);

    m_matrix = new int*[GetHeight()];

    //crates the 2d array that represents the matrix with the specified height and width
    for(int i = 0; i < GetHeight(); i++){
        m_matrix[i] = new int[GetWidth()];
    }

    //asks user to set the values of the matrix
    for(int i = 0; i < GetHeight(); i++){
        for(int j = 0; j < GetWidth(); j++){
            cout << "Enter Matrix Values:" << endl;
            cin >> m_matrix[i][j];
        }
    }

}

//copy constructor
Matrix::Matrix(const Matrix& mat) {
    // Copy dimensions
    SetHeight(mat.GetHeight());
    SetWidth(mat.GetWidth());

    // Allocate new memory for the matrix
    m_matrix = new int*[GetHeight()];
    for (int i = 0; i < GetHeight(); i++) {
        m_matrix[i] = new int[GetWidth()];
        for (int j = 0; j < GetWidth(); j++) {
            m_matrix[i][j] = mat.GetMatrix()[i][j];
        }
    }
}

//matrix destructor
Matrix::~Matrix(){
    for(int i = 0; i < GetHeight(); i++){
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

//a function to add two matrices together
Matrix Matrix::AddMatrices(Matrix mat1){
    
    //only adds if the matricie have the same dimensions
    if(mat1.GetHeight() == GetHeight() and mat1.GetWidth() == GetWidth()){
        Matrix added = mat1;

        for(int i = 0; i < added.GetHeight(); i++){
            for(int j = 0; j < added.GetWidth(); j++){
                added.GetMatrix()[i][j] = mat1.GetMatrix()[i][j] + GetMatrix()[i][j];
            }
        }

        return added;
    }
    else{
        throw "Matricies are different sizes and can't be added";
    }
}

Matrix Matrix::MultiplyMatrices(Matrix mat1) {
    // Check for dimension validation
    if (GetWidth() != mat1.GetHeight()) {
        throw "Matrices cannot be multiplied due to incompatible dimensions.";
    }

    Matrix multiplied; 
    multiplied.SetHeight(GetHeight());
    multiplied.SetWidth(mat1.GetWidth());

    // Allocate memory
    multiplied.m_matrix = new int*[multiplied.GetHeight()];
    for (int i = 0; i < multiplied.GetHeight(); i++) {
        multiplied.m_matrix[i] = new int[multiplied.GetWidth()];
    }

    // Perform matrix multiplication
    for (int i = 0; i < multiplied.GetHeight(); i++) {
        for (int j = 0; j < multiplied.GetWidth(); j++) {
            multiplied.m_matrix[i][j] = 0; 
            for (int k = 0; k < GetWidth(); k++) { 
                multiplied.m_matrix[i][j] += GetMatrix()[i][k] * mat1.GetMatrix()[k][j];
            }
        }
    }

    return multiplied;  // Return the result
}

//a function to multiply a matricx and an int
Matrix Matrix::MultiplyByInt(int value){
    if(m_matrix){

        Matrix multiplied = *this;

        for(int i = 0; i < multiplied.GetHeight(); i++){
            for(int j = 0; j < multiplied.GetWidth(); j++){
                multiplied.GetMatrix()[i][j] = this->GetMatrix()[i][j] * value;
            }
        }

        return multiplied;

    }
    else{
        throw "matrix is empty";
    }
}

//a function to transpose a matrix
Matrix Matrix::TransposeMatrix(){
    if(m_matrix){

        Matrix transposed;

        transposed.SetHeight(GetWidth());
        transposed.SetWidth(GetHeight());
    
        // Allocate memory
        transposed.m_matrix = new int*[transposed.GetHeight()];
        for (int i = 0; i < transposed.GetHeight(); i++) {
            transposed.m_matrix[i] = new int[transposed.GetWidth()];
        }

        for(int i = 0; i < transposed.GetHeight(); i++){
            for(int j = 0; j < transposed.GetWidth(); j++){
                transposed.GetMatrix()[i][j] = this->GetMatrix()[j][i];
            }
        }

        return transposed;

    }
    else{
        throw "matrix is empty";
    }
}

//used to print a matrix
void Matrix::Print(){
    if(m_matrix){
        for(int i = 0; i < GetHeight(); i++){
            for(int j = 0; j < GetWidth(); j++){
            cout << "[" << GetMatrix()[i][j] << "] ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Empty matrix" << endl;
    }
}

Matrix& Matrix::operator=(const Matrix& mat) {
    // Prevent self-assignment
    if (this == &mat) {
        return *this;
    }

    // Free existing memory
    if (m_matrix) {
        for (int i = 0; i < GetHeight(); i++) {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }

    // Set new dimensions
    SetHeight(mat.GetHeight());
    SetWidth(mat.GetWidth());

    // Allocate new memory and perform a deep copy
    if (mat.GetMatrix()) {  // Check if the source matrix is initialized
        m_matrix = new int*[GetHeight()];
        for (int i = 0; i < GetHeight(); i++) {
            m_matrix[i] = new int[GetWidth()];
            for (int j = 0; j < GetWidth(); j++) {
                m_matrix[i][j] = mat.GetMatrix()[i][j];  // Copy values
            }
        }
    } else {
        m_matrix = nullptr;  // Ensure the matrix is null if the source is empty
    }

    return *this;  // Return the current object
}

//mutators for the private fields
void Matrix::SetWidth(int width){
    m_matrixWidth = width;
}

void Matrix::SetHeight(int height){
    m_matrixHeight = height;
}

void Matrix::SetMatrix(int** matrix) {
    // Free existing memory
    if (m_matrix) {
        for (int i = 0; i < GetHeight(); i++) {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }

    // Allocate new memory
    m_matrix = new int*[GetHeight()];
    for (int i = 0; i < GetHeight(); i++) {
        m_matrix[i] = new int[GetWidth()];
        for (int j = 0; j < GetWidth(); j++) {
            m_matrix[i][j] = matrix[i][j];  // Copy values
        }
    }
}

int Matrix::GetWidth() const{
    return m_matrixWidth;
}

int Matrix::GetHeight() const{
    return m_matrixHeight;
}

int** Matrix::GetMatrix() const{
    return m_matrix;
}