#include <iostream>
#include <cmath>

double getNumber(std::istream &is){
  double num{};
  is >> num;
  return num;
}

int main(){
  auto const number { getNumber(std::cin) };
  std::cout << "The square root of "
            << number 
            << " is " << sqrt(number);
}
