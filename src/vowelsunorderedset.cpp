#include <unordered_set>
#include <iostream>
void filtervowels(std::istream &in, std::ostream &out){
  std::unordered_set const vowels{'a','e','o','u','i','y'};
  char c{};
  while (in.get(c)) {
    if (! vowels.count(c)) { 
      out << c;
    }
  }
}
int main(){
  filtervowels(std::cin,std::cout);
}
