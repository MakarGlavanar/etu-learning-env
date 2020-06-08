#include <napi.h>

#include "./test/TestDecorator.hpp"

using namespace Napi;

Object init(Env env, Object exports) {
    exports.Set(String::New(env, "generateTest"), Function::New(env, generateTest));

    return exports;
};

NODE_API_MODULE(etu_le_core, init);
