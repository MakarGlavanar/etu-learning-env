#include <string>
#include "napi.h"

#include "../../core/models/student/Student.hpp"
#include "../../core/services/student/StudentService.hpp"

#ifndef STUDENT_DECORATOR
#define STUDENT_DECORATOR

using namespace Napi;

Object decorateStudent(Env env, Student student);

Object createStudent(const CallbackInfo& info);

void readStudents(const CallbackInfo& info);

Array getStudents(const CallbackInfo& info);

#endif