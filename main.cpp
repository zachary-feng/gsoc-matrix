#include <iostream>
#include <Eigen/Dense>
#include "SymMat.h"
using Eigen::MatrixXd;

// LIST OF THINGS TO MAKE THE LIBRARY BETTER:
// TODO: create setter functions (e.g. if mat is a SymMat object, then mat(2,2) = 6.32 should set the value at index 2,2)
// TODO: better output formatting for SymMat objects
// TODO: +-* from both sides (e.g. Eigen::Matrix + SymMat <=> SymMat + Eigen::Matrix)
// TODO: create destructors for dynamically allocated storage
// TODO: try Strassen or Coppersmith–Winograd algorithms for matrix multiplication of large arrays

int main()
{
  std::cout << "We set up our 3x3 Eigen::Matrix called \"m\"\n" << std::endl;
  std::cout << "m =" << std::endl;

  MatrixXd m(3,3);
  for(int i = 0; i < m.rows(); i++) {
    for(int j = 0; j < m.cols(); j++) {
      m(i,j) = 5*i+j-(2*i%5); // assign random values
    }
  }

  std::cout << m << std::endl;
  std::cout << "This is not a symmetric matrix\n" << "So we will create one with the SymMat constructor and call it \"sm\"" << std::endl;
  std::cout << "sm =\n" << std::endl;

  SymMat sm = m;

  std::cout << sm << std::endl;
  std::cout << "We have created our symmetric matrix as a SymMat object" << std::endl;

  std::cout << "We can retrieve any element we want with the object's accessor" << std::endl;
  std::cout << "sm(0,2) is " << sm(0,2) << std::endl;
  std::cout << "sm(2,0) is " << sm(2,0) << std::endl;
  std::cout << "sm(1,1) is " << sm(1,1) << std::endl;
  std::cout << "sm(1,2) is " << sm(1,2) << std::endl;

  std::cout << "Addition, subtraction, and multiplication of only SymMat types is shown here" << std::endl;
  std::cout << "(note that we have created a SymMat identity matrix called \"sid\")" << std::endl;

  // We have created an identity matrix to enhance the demonstration
  MatrixXd id = MatrixXd::Identity(3,3);
  SymMat sid (id);

  std::cout << "sm + sm =\n" << sm + sm << "\n" << std::endl;
  std::cout << "sm - sm =\n" << sm - sm << "\n" << std::endl;
  std::cout << "sm * sm =\n" << sm * sm << "\n" << std::endl;
  std::cout << "sid + sm =\n" << sid + sm << "\n" << std::endl;
  std::cout << "sid * sm =\n" << sid * sm << "\n" << std::endl;
  std::cout << "sm * sid =\n" << sm * sid << "\n" << std::endl;

  std::cout << "Addition, subtraction, and multiplication with Eigen::Matrix types are shown now" << std::endl;
  std::cout << "An Eigen::Matrix identity matrix \"id\" already exists" << std::endl;
  std::cout << "We will create another 3x5 Eigen::Matrix called \"big\" to demonstrate further SymMat's abilities" << std::endl;

  MatrixXd big(3,5);
  for(int i = 0; i < big.rows(); i++) {
    for(int j = 0; j < big.cols(); j++) {
      big(i,j) = 4*i+j-(1+6*i%3); // assign random values
    }
  }

  std::cout << "big =\n" << big << std::endl;
  std::cout << "sm + m =\n" << sm + m << "\n" << std::endl;
  std::cout << "sm - m =\n" << sm - m << "\n" << std::endl;
  std::cout << "sm * m =\n" << sm * m << "\n" << std::endl;
  std::cout << "sm * big =\n" << sm * big << "\n" << std::endl;
  std::cout << "sm - id =\n" << sm - id << "\n" << std::endl;
  std::cout << "sm * id =\n" << sm * id << "\n" << std::endl;

  std::cout << "Finally, we will show all the exceptions that SymMat currently throws" << std::endl;
  std::cout << "We will handle the exceptions by displaying an error message and returning a zero matrix" << std::endl;
  std::cout << "We will create Eigen::Matrix \"toobig\" and its corresponding SymMat \"stoobig\"" << std::endl;

  MatrixXd toobig(4,4);
  for(int i = 0; i < toobig.rows(); i++) {
    for(int j = 0; j < toobig.cols(); j++) {
      toobig(i,j) = 3*i+j-(1+8*i%5); // assign random values
    }
  }
  SymMat stoobig = toobig;

  std::cout << "toobig =\n" << toobig << std::endl;
  std::cout << "stoobig =\n" << stoobig << std::endl;

  std::cout << "sm + stoobig =\n" << sm + stoobig << std::endl;
  std::cout << "sm + toobig =\n" << sm + toobig << std::endl;
  std::cout << "sm - stoobig =\n" << sm - stoobig << std::endl;
  std::cout << "sm - toobig =\n" << sm - toobig << std::endl;
  std::cout << "sm * stoobig =\n" << sm * stoobig << std::endl;
  std::cout << "sm * toobig =\n" << sm * toobig << std::endl;

  std::cout << "There are a few other features that I implemented to assist me in creating these core features" << std::endl;
  std::cout << "You can find them in the library source code. Thank you for reading the tutorial on how to use the SymMat package!" << std::endl;
  std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^ Please scroll to the top to begin the tutorial (demo) ^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n" << std::endl;

  return 0;
}
