#include <stdexcept>
#include <string>
#include <istream>
#include <algorithm>
#include <cctype>
#include <iostream>

std::string inputName(std::istream &is){
  std::string input{};
  is >> input;
  if (input.size()){
    if (all_of(cbegin(input), cend(input), isalpha)) {
        return input;
    } else { throw std::runtime_error("wrong character"); }
  } else { throw std::logic_error("missing input"); }
}
int main(){
  while(std::cin) {// eof terminates
    try {
      auto result = inputName(std::cin);
      std::cout << "you are " << result << '\n';
    } catch (std::logic_error const &e){
      std::cout << e.what() << '\n';
    } catch (std::runtime_error const &e){
      std::cout << e.what() << '\n';
    }
  }
}