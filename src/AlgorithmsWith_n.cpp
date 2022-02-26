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
  std::vector<unsigned> numbers{};
  generate_n(std::back_inserter(numbers),100,
            [n=1u]()mutable{return n++;});
  std::cout << numbers.front() << ".." << numbers.back();
  numbers.erase(remove_if(begin(numbers),end(numbers),
                std::not_fn(is_prime)),end(numbers));
  std::cout << " has " << numbers.size() 
            << " prime numbers\nthe first 10 are:\n";
  copy_n(begin(numbers),10,out);
}