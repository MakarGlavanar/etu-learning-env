#include <iostream>
#include "../Task.hpp"

int main() {
  Task task = Task(0, "hello", "some", "cool", "theme", "blya");

  std::cout << task.getTheme() << "\n";
  std::cout << task.getTitle() << "\n";
  std::cout << task.getDescription() << "\n";
  std::cout << task.getInputData() << "\n";
  std::cout << task.getOutputData() << "\n";
  std::cout << task.getSolution() << "\n";

  return 0;
}
