#ifndef COMPLEX_NUM_H
#define COMPLEX_NUM_H
#include <iostream>

class ComplexNum {
private:
	double mRe = 0; // real parth
	double mIm = 0; // imaginary path 
public:
	ComplexNum();
	ComplexNum(const double& a); 
	ComplexNum(const double& a, const double& b);

	double getModulus();
 
	double getRe();

	double getIm();

  // ComplexNum + ComplexNum, 
  ComplexNum operator+(const ComplexNum& other);
  // ComplexNum - ComplexNum, 
  ComplexNum operator-(const ComplexNum& other);
  // ComplexNum * k, where k is a constant
  ComplexNum operator*(int k);
  // and operator<<
  friend std::ostream &operator<<(std::ostream& , ComplexNum&);


  // 
	
};

#endif // COMPLEX_NUM_H
