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

Object createStudent(const CallbackInfo &info)
{
  Env env = info.Env();
  std::string fio = info[0].As<String>().ToString();
  int groupId = info[1].As<Number>().Int32Value();
  int index = info[2].As<Number>().Int32Value();

  Student student = service.makeStudent(fio, groupId, index);

  Object obj = decorateStudent(env, student);

  return obj;
}

void readStudents(const CallbackInfo &info)
{
  service.readStudents();
}

Array getStudents(const CallbackInfo &info)
{
  Env env = info.Env();
  int STUDENTS_COUNT = service.getStudentsCount();
  bool hasMarkFilter = info.Length() > 0;
  Student *students;

  if (hasMarkFilter) {
    int mark = info[0].As<Number>().Int32Value();

    students = service.getStudents(mark, &STUDENTS_COUNT);
  } else {
    students = service.getStudents();
  }

  if (students == NULL) {
    Array arr = Array::New(env);

    return arr;
  }

  Array arr = Array::New(env, STUDENTS_COUNT);

  for (int i = 0; i < STUDENTS_COUNT; i++)
  {
    Student student = students[i];

    Object obj = decorateStudent(env, student);

    arr[i] = obj;
  }

  return arr;
}
