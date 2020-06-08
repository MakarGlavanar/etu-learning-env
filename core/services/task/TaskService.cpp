#include "./TaskService.hpp"

TaskService::TaskService()
{
  tasks = new Task[TASKS_COUNT];

  tasks[0] = Task(
    TaskThemes::LINKED_LIST,
    "Односвязный список",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[1] = Task(
    TaskThemes::LINKED_LIST,
    "Односвязный список",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[2] = Task(
    TaskThemes::DOUBLY_LINKED_LIST,
    "Двусвязный список",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[3] = Task(
    TaskThemes::DOUBLY_LINKED_LIST,
    "Двусвязный список",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[4] = Task(
    TaskThemes::POLISH_NOTATION,
    "Польская нотация",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[5] = Task(
    TaskThemes::POLISH_NOTATION,
    "Польская нотация",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[6] = Task(
    TaskThemes::BINARY_TREE,
    "Бинарное дерево",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[7] = Task(
    TaskThemes::BINARY_TREE,
    "Бинарное дерево",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[8] = Task(
    TaskThemes::PRIM,
    "Алгоритм Прима",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[9] = Task(
    TaskThemes::PRIM,
    "Алгоритм Прима",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[10] = Task(
    TaskThemes::KRUSKAL,
    "Алгоритм Краскала",
    "hello",
    "hello",
    "hello",
    "hello"
  );

  tasks[11] = Task(
    TaskThemes::KRUSKAL,
    "Алгоритм Краскала",
    "hello",
    "hello",
    "hello",
    "hello"
  );
}

int TaskService::getTasksCount() {
  return TASKS_COUNT;
}

Task TaskService::getTask(int theme, int variant) {
  int currentVariant = 0;
  
  for (int i = 0; i < TASKS_COUNT; i++) {
    Task task = tasks[i];

    if (task.getTheme() == theme) {
      if (currentVariant == variant) {
        return task;
      }

      currentVariant += 1;
    }
  }
}

TaskService::~TaskService() {
  delete[] tasks;
}
