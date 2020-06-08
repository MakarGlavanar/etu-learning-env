#include <napi.h>

#include "./test/TestDecorator.hpp"
#include "./student/StudentDecorator.hpp"

using namespace Napi;

Object init(Env env, Object exports) {
    // TEST
    exports.Set(String::New(env, "generateTest"), Function::New(env, generateTest));

    // STUDENTS
    exports.Set(String::New(env, "getStudents"), Function::New(env, getStudents));
    exports.Set(String::New(env, "readStudents"), Function::New(env, readStudents));

    return exports;
};

NODE_API_MODULE(etu_le_core, init);
