#include <iostream>
#include "../test.hpp"

int main() {
  Test* test = new Test("Valera");

  std::cout << test->getName() << std::endl;

  return 0;
}
