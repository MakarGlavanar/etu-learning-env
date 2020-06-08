#include "./TestService.hpp"

TestService::TestService()
{
  service = new TaskService();
};

Test TestService::generateTest(int index, std::string title)
{
  int tasksCount = service->getTasksCount();
  Task *tasks = new Task[tasksCount];

  for (int i = 0; i < tasksCount; i++)
  {
    tasks[i] = service->getTask(i / 2, i % 2);
    tasks[i].setIndex(i);
  }

  Test test = Test(index, title, tasks);

  return test;
}

int TestService::getTasksCount() {
  return service->getTasksCount();
}
