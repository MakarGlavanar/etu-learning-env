#include "./Test.hpp"

Test::Test(
    int index,
    std::string title,
    Task *tasks) : index(index),
                   title(title),
                   tasks(tasks){};

int Test::getIndex() {
  return index;
}

std::string Test::getTitle() {
  return title;
}

Task* Test::getTasks() {
  return tasks;
}

Test::~Test() {
  delete[] tasks;
}
