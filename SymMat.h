#ifndef SYMMAT_H
#define SYMMAT_H

#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;

class SymMat {

private:
  int length; // length of 1D array
  int size; // size of square matrix
  double *symmat; // declare symmetric matrix

public:
  SymMat(MatrixXd mat); // constructor
  SymMat(const SymMat& sm); // copy constructor from SymMat
  double operator()(int i, int j) const; // accessor to index (i,j) = (j,i), read
  friend std::ostream& operator<<(std::ostream& os, const SymMat& sm); // formatted matrix output to console
  int rows() const; // rows of symmetric matrix, same as cols
  int cols() const; // cols of symmetric matrix, same as rows
  void setZero(); // sets matrix to the zero matrix

  SymMat operator+(const SymMat& other); // matrix addition with SymMat
  MatrixXd operator+(const MatrixXd& other); // matrix addition with Eigen
  SymMat operator-(const SymMat& other); // matrix subtraction with SymMat
  MatrixXd operator-(const MatrixXd& other); // matrix subtraction with Eigen
  MatrixXd operator*(const SymMat& other); // matrix multiplication with SymMat
  MatrixXd operator*(const MatrixXd& other); // matrix multiplication with Eigen
};

#endif
