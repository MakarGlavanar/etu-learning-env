#include <string>
#include "napi.h"

#include "../../core/services/test/TestService.hpp"
#include "../../core/models/task/Task.hpp"

#include "./TestDecorator.hpp"
#include "../task/TaskDecorator.hpp"

using namespace Napi;

Object decorateTest(Env env, Test *test) {
  TestService service = TestService();
  const int TASKS_COUNT = service.getTasksCount();

  Object obj = Object::New(env);
  Array arr = Array::New(env, TASKS_COUNT);

  obj.Set("index", test->getIndex());
  obj.Set("title", test->getTitle());
  
  Task *tasks = test->getTasks();

  for (int i = 0; i < TASKS_COUNT; i++) {
    arr[i] = decorateTask(env, tasks[i]);
  }

  obj.Set("tasks", arr);
  
  return obj;
}

Object generateTest(const CallbackInfo& info) {
  Env env = info.Env();

  int index = info[0].As<Number>().Int32Value();
  std::string title = info[1].As<String>().ToString();

  TestService service = TestService();

  Test test = service.generateTest(index, title);

  Object obj = decorateTest(env, &test);

  return obj;
}
