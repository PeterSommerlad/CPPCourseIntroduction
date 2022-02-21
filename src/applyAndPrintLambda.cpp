#include <iostream>
auto const applyAndPrint{
    [](double x, auto f) {
       std::cout << "f(" << x << ") = " << f(x) << '\n';
    }};
int main() {
  double const three{3.0};
  auto const times_three = [three](double value) {
    return three * value;
  };
  applyAndPrint(1.5, times_three);
}