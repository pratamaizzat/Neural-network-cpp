#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

class Matrix {
  private:
    int rows = 0; 
    int cols = 0; 
    int data[99][99];

  public:
    Matrix(int rows, int cols){
      if(rows == 0 || cols == 0){
        std::cout << "Value 0 is not allowed";
        return;
      }
      this->rows = rows;
      this->cols = cols;
      this->data[this->rows][this->cols];

      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          this->data[i][j] = 0;
        }
      }
    }

    void randomize() {
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          this->data[i][j] = rand() % 10;
        }
      }
    }

    void add(int n){
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          this->data[i][j] += n;
        }
      }
    }

    /** 
     * Method Static Matrix *
     * (Object, Object) Matrix* - paramter object pointer matrix
    */
    static Matrix addMatrix (Matrix* firstMatrix, Matrix* secondMatrix){
      if(firstMatrix->rows != secondMatrix->rows || firstMatrix->cols != secondMatrix->cols){
        throw "ERROR! Matrix do not match";
      }
      Matrix result(firstMatrix->rows, secondMatrix->cols);
      for(int i = 0; i < firstMatrix->rows; i++){
        for(int j = 0; j < firstMatrix->cols; j++){
          result.data[i][j] = firstMatrix->data[i][j] + secondMatrix->data[i][j];
        }
      }
      return result;
    }

    void scalar(int n){
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          this->data[i][j] *= n;
        }
      }
    }

    static Matrix matrixProduction(Matrix* firstMatrix, Matrix* secondMatrix){
      if(firstMatrix->cols != secondMatrix->rows){
        throw "Matrix do not match for mutlipy";
      }

      Matrix result(firstMatrix->rows, secondMatrix->cols);
      for(int i = 0; i < firstMatrix->rows; i++){ 
        for(int j = 0; j < secondMatrix->cols; j++){ 
          for(int k = 0; k < firstMatrix->cols; k++){ 
            result.data[i][j] += firstMatrix->data[i][k] * secondMatrix->data[k][j];
          }
        }
      }
      return result;
    }

    void map(int(*func)(int)){
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          int value = this->data[i][j];
          this->data[i][j] = func(value);
        }
      }
    }

    Matrix transpose() {
      Matrix result(this->cols, this->rows); 
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          result.data[j][i] = this->data[i][j];
        }
      }
      return result;
    }

    void printMatrix() {
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
          std::cout << this->data[i][j] << "\t";
        }
        std::cout << "\n";
      }
    }
};

int oddValue(int x){
  if(x % 2 != 0){
    return 1;
  }else{
    return 0;
  }
}

int main() {
  // Matrix firstMatrix(10, 10);
  // firstMatrix.randomize();
  // firstMatrix.printMatrix();
  // std::cout << "\n";

  // Matrix secondMatrix(10, 10);
  // secondMatrix.randomize();
  // secondMatrix.printMatrix();
  // std::cout << "\n";

  // Matrix newMatrix = Matrix::matrixProduction(&firstMatrix, &secondMatrix);
  // newMatrix.printMatrix();
  // std::cout << "\n";
  // newMatrix.map(oddValue);
  // newMatrix.printMatrix();

  // Matrix matrix1(3, 3); 
  // matrix1.randomize();
  // matrix1.printMatrix();
  // std::cout << "\n";

  // matrix1.add(2);
  // matrix1.printMatrix();
  // std::cout << "\n";

  // matrix1.scalar(2);
  // matrix1.printMatrix();

  // Matrix matrix2(3, 3);
  // matrix2.randomize();
  // matrix2.printMatrix();
  // std::cout << "\n";

  // Matrix newMatrix = Matrix::addMatrix(&matrix1, &matrix2);
  // newMatrix.printMatrix();
  // std::cout << "\n";
  // newMatrix.add(2);
  // newMatrix.printMatrix();
  
  // matrix.randomize();
  // matrix.printMatrix();
  return 0;
}