#include <string>
#include "../task/Task.hpp"

#ifndef TEST
#define TEST

class Test {
  private:
    int index;
    std::string title;
    Task* tasks;

  public:
    Test(int index, std::string, Task* tasks);

    int getIndex();

    std::string getTitle();

    Task* getTasks();

    ~Test();
};

#endif
