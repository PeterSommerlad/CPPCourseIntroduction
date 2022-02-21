#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

int main(){
  
  using input=std::istream_iterator<std::string>;
  input eof{};
  input in{std::cin};
  std::ostream_iterator<std::string> out{std::cout,"\n"};
  copy(in,eof,out);
  
}