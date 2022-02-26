#include <set>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using string = std::string; // for brevity
struct caseless{
  bool operator()(string const &l, string const &r) const {
    return std::lexicographical_compare(
      begin(l),end(l),begin(r),end(r),
      [](char lc, char rc) { 
        return std::tolower(lc) < std::tolower(rc);
      });
  }
};
using caseless_set = std::multiset<string, caseless>;
int main() {
  using in = std::istream_iterator<string>;
  caseless_set const wlist{in{std::cin},in{}};
  std::ostream_iterator<string> out{std::cout,"\n"};
  copy(wlist.begin(), wlist.end(), out);
}

/* input:
How much wood would a woodchuck called Chuck chuck if woodchuck Chuck could chuck wood?
Woodchuck Chuck would chuck no amount of wood since a woodchuck cannot chuck wood.
But if a woodchuck called Chuck could chuck and would chuck some amount of wood, what amount of wood would woodchuck Chuck chuck?
Even if a woodchuck could chuck wood, and even if a woodchuck called Chuck would chuck wood, should  woodchuck Chuck chuck wood? 
Woodchuck Chuck should chuck if woodchuck Chuck could chuck wood, as long as woodchuck Chuck would chuck wood.
*/