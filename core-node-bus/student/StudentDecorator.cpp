#include "StudentDecorator.hpp"

String kek(const CallbackInfo &info)
{
  StudentService service("./students.txt", "./students.txt");

  String lol = String::New(info.Env(), service.readStudents());

  return lol;
}
