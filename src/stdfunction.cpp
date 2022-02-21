#include <functional>
#include <iostream>

void applyAndPrint(double x, std::function<double(double)> f) {
  std::cout << "f(" << x << ") = " << f(x) << '\n';
}

int main() {
  double factor{3.0};
  auto const multiply = [factor](double value) {
    return factor * value;
  };
  applyAndPrint(1.5, multiply);
}