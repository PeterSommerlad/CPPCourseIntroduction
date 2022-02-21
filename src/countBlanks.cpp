#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
namespace loop {
size_t count_blanks(std::string s){
  size_t count{0};
  for (size_t i{0}; i < s.size(); ++i){
    if (s[i] == ' '){
      ++count;
    }
  }
  return count;
}
}
namespace algo {
size_t count_blanks(std::string s){
  return count(begin(s),end(s),' ');
}
}
int main(){
  using namespace std::literals;
  auto s{"This is a longer example text with some blank characters   "s};
  std::cout << s << "\nhas " << loop::count_blanks(s) << " blanks\n";
  std::cout << s << "\nhas " << algo::count_blanks(s) << " blanks\n";
}