#include <iostream>
#include "../TaskService.hpp"

int main() {
  TaskService service = TaskService();

  std::cout << service.getTask(0, 0).getTitle() << "\n";
  std::cout << service.getTask(0, 1).getTitle() << "\n";
  std::cout << service.getTask(1, 0).getTitle() << "\n";
  std::cout << service.getTask(2, 0).getTitle() << "\n";

  return 0;
}
