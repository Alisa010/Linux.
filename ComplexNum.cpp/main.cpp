#include "ComplexNum.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(){

  ComplexNum c1{4 , 3};
  ComplexNum c2{5 , 6};
  ComplexNum c3{3 , 9};
  ComplexNum c4{8 , 9};

  std::vector<ComplexNum> vec;
  vec.push_back(c1);
  vec.push_back(c2);
  vec.push_back(c3);
  vec.push_back(c4);

  for(int i = 0; i < vec.size(); ++i){
    for(int j = 0; j < vec.size() - 1 - i; ++j){
        if(vec[j].getModulus() > vec[j + 1].getModulus()){
                   std::swap(vec[j] , vec[j + 1]);
         }
                 }
         }
  for(int i = 0; i < vec.size() ; ++i){
          std::cout << vec[i]  ;
     }

}
