#include <algorithm>
#include <vector>
#include <iostream>

void printReverse(std::vector<int> v, std::ostream &out) {
  std::for_each(crbegin(v), crend(v), 
    [&out](auto elt){ // lambda function expression
      out << "print: " << elt << '\n';
    }); // end of for_each arguments
}

int main(){
  std::vector v{1,2,3,4,5};
  printReverse(v,std::cout);
}