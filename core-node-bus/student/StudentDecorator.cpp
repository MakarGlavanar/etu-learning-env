#include "StudentDecorator.hpp"

StudentService service("./students.txt", "./students.txt");

Object decorateStudent(Env env, Student student)
{
  Object obj = Object::New(env);

  obj.Set("id", student.getId());
  obj.Set("fio", student.getFio());
  obj.Set("groupId", student.getGroupId());
  obj.Set("index", student.getIndex());

  return obj;
}

void readStudents(const CallbackInfo &info)
{
  service.readStudents();
}

Array getStudents(const CallbackInfo &info)
{
  Env env = info.Env();
  const int STUDENTS_COUNT = service.getStudentsCount();
  Student *students = service.getStudents();

  Array arr = Array::New(env, STUDENTS_COUNT);

  for (int i = 0; i < STUDENTS_COUNT; i++)
  {
    Student student = students[i];

    Object obj = decorateStudent(env, student);

    arr[i] = obj;
  }

  return arr;
}
