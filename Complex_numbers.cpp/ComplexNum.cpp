#include "ComplexNum.h"
#include <cmath>
#include <iostream>

ComplexNum::ComplexNum() {};

ComplexNum::ComplexNum(const double& re)
	:mRe{re}
{}

ComplexNum::ComplexNum(const double& re, const double& im)
	: mRe{ re }
	, mIm{ im }
{}

double ComplexNum::getModulus(){
	return sqrt(mRe * mRe + mIm * mIm);
}

double ComplexNum::getRe() {
	return mRe;
}

double ComplexNum::getIm() {
	return mIm;
}

// ComplexNum + ComplexNum, 
  ComplexNum ComplexNum::operator+(const ComplexNum& other){
     return ComplexNum(other.mRe + mRe, other.mIm + mIm);
}
// ComplexNum - ComplexNum, 
  ComplexNum ComplexNum::operator-(const ComplexNum& other){
     return ComplexNum(other.mRe - mRe, other.mIm - mIm);
}
 // ComplexNum * k, where k is a constant
  ComplexNum ComplexNum::operator*(int k){
     return ComplexNum(k * mRe, k * mIm);
}
// and operator<<
std::ostream &operator<<(std::ostream &out, ComplexNum &complex)
{
  out <<  complex.mRe << "+" << complex.mIm << + "i" << "\n";
 
   return out;
}
