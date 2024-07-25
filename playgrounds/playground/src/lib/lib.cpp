#include "lib.hpp"

void hello(void) {
  int x, y{};
  std::cout << &x << " " << &y << "\n";
  std::cout << x << " " << y << "\n";
}

int hello2(void) {
  return 5;
}