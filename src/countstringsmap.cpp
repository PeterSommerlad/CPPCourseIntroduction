#include<map>
#include<string>
#include<algorithm>
#include<iterator>
#include<iostream>
void countStrings(std::istream &in, std::ostream &out) {
  std::map<std::string, size_t> occurrences{};
  std::istream_iterator<std::string> inputBegin{in};
  std::istream_iterator<std::string> inputEnd{};
  for_each(inputBegin, inputEnd, [&occurrences](auto const &str) {
    ++occurrences[str]; // creates entry if not existent
  });
  for(auto const & [str,count] : occurrences) {
    out << str << " = " << count << '\n';
  }
}
int main(){
  countStrings(std::cin,std::cout);
}