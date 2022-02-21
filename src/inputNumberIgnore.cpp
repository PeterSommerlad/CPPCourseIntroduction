#include <istream>
int inputAge(std::istream& in){
  while (in.good()){
    int age{-1}; // mutable
    if (in >> age) { // false when fail
      return age;
    } 
    in.clear(); // reset state
    in.ignore(); // skip 1 char
    //in.ignore(10000,'\n'); // ignore whole line
  }
  return -1;// input failed
}

#include <iostream>
int main(){
  std::cout << "How old are you?";
  int const age = inputAge(std::cin);
  std::cout << "\nYou are " << age << " years old\n";
}