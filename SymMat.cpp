#include "SymMat.h"

SymMat::SymMat (MatrixXd mat) {
  length = (mat.rows()*(mat.rows()+1))/2;
  size = mat.rows();

  // initialize symmetric matrix
  symmat = new double[length];

  // loading symmetric matrix
  int count = 0;
  for(int i = 0; i < size; i++) {
    for(int j = i; j < size; j++) {
      symmat[count++] = mat(i,j);
    }
  }
}

SymMat::SymMat(const SymMat& sm) {
  this->length = sm.length; // copies linear array length
  this->size = sm.size; // copies matrix dimensions

  this->symmat = new double[sm.length]; // copies linear array
  for(int i = 0; i < sm.length; i++) {
    (*this).symmat[i] = sm.symmat[i];
  }
}

double SymMat::operator()(int i, int j) const {
  if(i <= j) {
    return symmat[length-((size-i)*(size-i+1)/2)+(j-i)]; // formula to retrieve elements from linear array in O(1) time
  } else {
    return operator()(j,i);
  }
}

std::ostream& operator<<(std::ostream& os, const SymMat& sm) {
  for(int i = 0; i < sm.size; i++) {
    for(int j = 0; j < sm.size; j++) {
      os << sm(i,j) << '\t';
    }
    os << std::endl;
  }
  return os;
}

int SymMat::rows() const {
  return size;
}

int SymMat::cols() const {
  return size;
}

void SymMat::setZero() {
  for(int i = 0; i < this->length; i++) this->symmat[i] = 0;
}

SymMat SymMat::operator+(const SymMat& other) {
  SymMat result = *this;

  try {
    if(this->size != other.size) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat + SymMat)");

    for(int i = 0; i < this->length; i++) {
      result.symmat[i] += other.symmat[i];
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}

MatrixXd SymMat::operator+(const MatrixXd& other) {
  MatrixXd result = other;

  try {
    if(this->size != other.rows()) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat + Eigen::Matrix)");

    for(int i = 0; i < this->size; i++) {
      for(int j = 0; j < this->size; j++) {
        result(i,j) += (*this)(i,j);
      }
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}

SymMat SymMat::operator-(const SymMat& other) {
  SymMat result = *this;

  try {
    if(this->size != other.size) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat - SymMat)");

    for(int i = 0; i < this->length; i++) {
      result.symmat[i] -= other.symmat[i];
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}

MatrixXd SymMat::operator-(const MatrixXd& other) {
  MatrixXd result = other;

  try {
    if(this->size != other.rows()) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat - Eigen::Matrix)");

    for(int i = 0; i < this->size; i++) {
      for(int j = 0; j < this->size; j++) {
        result(i,j) = (*this)(i,j) - result(i,j);
      }
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}

MatrixXd SymMat::operator*(const SymMat& other) {
  MatrixXd result(this->size,this->size); // must be square

  try {
    if(this->size != other.size) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat * SymMat)");

    // native O(n^3) method, look into others for large matrices
    for(int i = 0; i < this->size; i++) {
      for(int j = 0; j < this->size; j++) {
        result(i,j)=0; // initialize values to 0
        for(int k = 0; k < this->size; k++) {
          result(i,j) += (*this)(i,k)*other(k,j);
        }
      }
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}

MatrixXd SymMat::operator*(const MatrixXd& other) {
  MatrixXd result(this->size,other.cols());

  try {
    if(this->size != other.rows()) throw std::runtime_error("Error: incompatible matrix dimensions (type SymMat * Eigen::Matrix)");

    // native O(n^3) method, look into others for large matrices
    for(int i = 0; i < this->size; i++) {
      for(int j = 0; j < other.cols(); j++) {
        result(i,j)=0; // initialize values to 0
        for(int k = 0; k < this->size; k++) {
          result(i,j) += (*this)(i,k)*other(k,j);
        }
      }
    }
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl; // displays error message
    result.setZero(); // sets return matrix to the zero matrix
  }
  return result;
}
