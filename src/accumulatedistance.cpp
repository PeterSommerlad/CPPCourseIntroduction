#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <iterator>
void printDistanceAndLength(std::string s) {
  std::cout << "distance: "<< distance(begin(s), end(s)) <<'\n';
  std::cout << "in a string of length: "<< size(s)<<'\n';
}

int main(){

  std::vector v{5, 4, 3, 2, 1};
  std::cout << accumulate(begin(v), end(v), 0)<< " = sum\n";

  std::cout << reduce(begin(v), end(v), 0)<< " = sum\n";

  printDistanceAndLength("Hello Peter");

}