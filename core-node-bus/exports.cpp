#include <napi.h>

#include "./test/TestDecorator.hpp"
#include "./student/StudentDecorator.hpp"

using namespace Napi;

Object init(Env env, Object exports) {
    exports.Set(String::New(env, "generateTest"), Function::New(env, generateTest));
    exports.Set(String::New(env, "kek"), Function::New(env, kek));

    return exports;
};

NODE_API_MODULE(etu_le_core, init);
