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
  std::vector<unsigned> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto nOfPrimes = std::count_if(begin(numbers), end(numbers), is_prime);
  copy(begin(numbers),end(numbers),out);
  std::cout << "\nhas " << nOfPrimes << " prime nubmers\n";
  copy_if(begin(numbers),end(numbers),out,is_prime);
}