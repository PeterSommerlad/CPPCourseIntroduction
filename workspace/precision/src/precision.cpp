
#include <iostream>
#include <iomanip> // setw() setprecision()
#include <cmath>   // acos()
#include <ios>

void test() {
	std::cout << 42 << '\t' << std::dec << 42 << '\n';
}

int main() {
  std::cout << 42 << '\t'
            << std::oct << 42 << '\t'
            << std::hex << 42 << '\n';
	test();
  std::cout << std::setw(10) << 42
            << std::left << std::setw(5)<< 43 << "*\n";
  std::cout << std::setw(10) << "hallo"<<"*\n";

  double const pi{std::acos(0.5) * 3};
  std::cout << std::setprecision(6) << pi*100 << '\n';
  std::cout << std::scientific << pi <<  '\n';
  std::cout << std::fixed << pi * 1e6 <<  '\n';
  std::cout << std::defaultfloat << std::setprecision(6) << 100.00123f << '\n';

}
