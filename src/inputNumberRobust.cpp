#include <sstream>

int inputAge(std::istream& in){
  std::string line{}; // mutable
  while (getline(in,line)){
    std::istringstream is{line};
    int age{-1}; // mutable
    if (is >> age) { // false when fail
      return age;
    } 
  }
  return -1;// input failed
}

#include <iostream>
int main(){
  std::cout << "How old are you?";
  int const age = inputAge(std::cin);
  std::cout << "\nYou are " << age << " years old\n";
}