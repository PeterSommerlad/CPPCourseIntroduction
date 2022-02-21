#include <iostream>
#include <cctype> // for tolower()
int main() {
  char c{};
  while(std::cin.get(c)) {
    std::cout.put(std::tolower(c));
  }
}