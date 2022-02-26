#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
auto is_prime = [](unsigned u) {
  for (unsigned i=2;i*i<=u;++i) {
    if (std::gcd(i,u)!=1) return false;
  }
  return true;
};
int main() {
  std::ostream_iterator<unsigned> out{std::cout,", "};
  std::vector<unsigned> values{54, 13, 17, 95, 2, 57, 12, 9};
  copy(begin(values),end(values),out); std::cout<<'\n';
  auto removed = std::remove_if(begin(values), end(values), is_prime);
  copy(begin(values),end(values),out); std::cout<<'\n';
  values.erase(removed,end(values));
  copy(begin(values),end(values),out); std::cout<<'\n';
}