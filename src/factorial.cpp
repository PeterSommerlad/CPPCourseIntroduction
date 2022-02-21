#include <iostream>
int factorial(int n){
  if (n > 1) 
    return n * factorial(n-1);
  return 1;
}
double factorial(double n) {
  if (n < 15)
    return factorial(int(n));
  double result=1;
  while(n > 1) {
    result *= n--; // bad!
  }
  return result;
}
int main() {
  //factorial(10u); // ambiguous
  //factorial(1e1l);// ambiguous	
  std::cout << factorial(3) << "\n";
  std::cout << factorial(1e2) << "\n";
}
