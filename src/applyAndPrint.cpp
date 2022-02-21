#include <iostream>
#include <cmath>
void applyAndPrint(double x, double f(double)) {
  std::cout << "f(" << x << ") = " << f(x) << '\n';
}
int main() {
  auto const times_three = [](double value) {
    return 3.0 * value;
  };
  applyAndPrint(1.5, times_three);
  applyAndPrint(0.0, acos); // π/2
}