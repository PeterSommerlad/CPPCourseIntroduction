#include <iostream>

int howOldYouAre(std::istream& in, std::ostream& out){
  out << "What year were you born?";
  int year{}; // mutable
  in >> year;
  int age = 2024 - year; // mutable
  out << "Did you already have your birthday (y/n)?";
  char hadBirthday{}; // mutable
  in >> hadBirthday; 
  if (hadBirthday != 'y') {
    --age;
  }
  return age;
}

int main(){
  int const age = howOldYouAre(std::cin, std::cout);
  std::cout << "\nYou are " << age << " years old\n";
}