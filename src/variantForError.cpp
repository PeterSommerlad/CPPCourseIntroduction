#include <variant>
#include <string>
#include <istream>
#include <algorithm>
#include <cctype>

enum class error_code { empty, invalid};
std::variant<std::string, error_code> inputName(std::istream &is){
  std::string input{};
  is >> input;
  if (input.size()){
    if (all_of(cbegin(input), cend(input), isalpha)) {
        return input;
    } else { return error_code::invalid; }
  } else { return error_code::empty; }
}

#include <iostream>

int main(){
  auto result = inputName(std::cin);
  while(std::holds_alternative<error_code>(result)){
    switch(std::get<error_code>(result)){
    case error_code::empty: std::cout << "missing input\n"; return 1;
    case error_code::invalid: std::cout << "wrong characters\n"; break;
    }
    std::cout << "\nplease try again: \n";
    result = inputName(std::cin);
  }
  if (std::holds_alternative<std::string>(result)){
    std::cout << "you are " << std::get<std::string>(result);
  }
}