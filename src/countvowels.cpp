#include <map>
#include <iostream>
#include <iterator>
int main(){
  std::map<char,size_t> vowels{{'a',0},{'e',0},{'i',0},{'o',0},{'u',0},{'y',0}};
  char c;
  while (std::cin >> c) {
    if (vowels.contains(c)) {
      ++vowels[c];
    }
  }
  for(auto const [key,value] : vowels) {
    std::cout << key << " = "<< value << '\n';
  }
  for(auto const p : vowels) {
    std::cout << p.first << " = "<< p.second << '\n';
  }
}
