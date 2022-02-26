#include<set>
#include<string>
#include<algorithm>
#include<iterator>
#include<iostream>
void sortedStringList(std::istream & in, std::ostream & out) {
  using inIter = std::istream_iterator<std::string>;
  using outIter = std::ostream_iterator<std::string>;
  std::multiset<std::string> words{inIter{in}, inIter{}};
  copy(cbegin(words), cend(words), outIter(out, "\n"));
  out<<"-----------------------------------\n";
  auto current = cbegin(words);
  while (current != cend(words)) {
    auto endOfRange = words.upper_bound(*current);
    copy(current, endOfRange, outIter{out, ", "});
    out << '\n'; // next range on new line
    current = endOfRange;
  }
}
int main(){
  sortedStringList(std::cin,std::cout);
}