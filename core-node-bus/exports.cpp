#include <napi.h>
#include "./test/makeTest.hpp"

using namespace Napi;

Object init(Env env, Object exports) {
    exports.Set(String::New(env, "makeTest"), Function::New(env, makeTest));

    return exports;
};

NODE_API_MODULE(etu_le_core, init);
