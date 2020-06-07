#include "test.hpp"

Test::Test(std::string name) : name(name) {};

std::string Test::getName() {
  return name;
}
