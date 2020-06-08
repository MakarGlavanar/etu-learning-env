#include "TaskDecorator.hpp"

Object decorateTask(Env env, Task task) {
  Object obj = Object::New(env);

  obj.Set("index", task.getIndex());
  obj.Set("title", task.getTitle());
  obj.Set("description", task.getDescription());
  obj.Set("inputData", task.getInputData());
  obj.Set("outputData", task.getOutputData());
  obj.Set("solution", task.getSolution());

  return obj;
}
