#include <string>
#include "../../models/task/Task.hpp"

#ifndef TASK_SERVICE
#define TASK_SERVICE

namespace TaskThemes {
  const int THEMES_COUNT = 6;
  const int LINKED_LIST = 0;
  const int DOUBLY_LINKED_LIST = 1;
  const int POLISH_NOTATION = 2;
  const int BINARY_TREE = 3;
  const int PRIM = 4;
  const int KRUSKAL = 5;
}

class TaskService {
  private:
    const int TASKS_COUNT = 12;
    Task* tasks;

  public:
    TaskService();

    int getTasksCount();

    Task getTask(int theme, int variant);

    ~TaskService();
};

#endif
