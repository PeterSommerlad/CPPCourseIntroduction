#include <algorithm>
#include <vector>
#include <iostream>

void print(int x) {
  std::cout << "print: "<< x << '\n';
}
void printReverse(std::vector<int> v) {
  std::for_each(crbegin(v), crend(v), print);
}

int main(){
  std::vector v{1,2,3,4,5};
  printReverse(v);
}