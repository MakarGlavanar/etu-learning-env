#include <iostream>
#include "../TestService.hpp"

int main() {
  TestService* service = new TestService();

  auto test = service->generateTest(0, "Kek");
  auto tasks = test.getTasks();

  for (int i = 0; i < 12; i++) {
    std::cout << tasks[i].getTitle() << "\n";
  }

  return 0;
}
