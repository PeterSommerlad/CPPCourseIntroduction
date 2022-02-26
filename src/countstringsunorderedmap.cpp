#include<unordered_map>
#include<string>
#include<algorithm>
#include<iterator>
#include<iostream>
void countStrings(std::istream &in, std::ostream &out) {
  std::unordered_map<std::string, size_t> occurrences{};
  std::istream_iterator<std::string> inputBegin{in};
  std::istream_iterator<std::string> inputEnd{};
  for_each(inputBegin, inputEnd, [&occurrences](auto const &str) {
    ++occurrences[str]; // creates entry if not existent
  });
  for(auto const & [str,count] : occurrences) {
    out << str << " = " << count << '\n';
  } // no longer sorted
}
int main(){
  countStrings(std::cin,std::cout);
}