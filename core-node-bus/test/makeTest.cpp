#include <napi.h>
#include "./makeTest.hpp"
#include "../../core/models/test/test.hpp"

using namespace Napi;
using namespace std;

Object makeTest(const CallbackInfo& info) {
  Env env = info.Env();

  string name = info[0].As<String>();

  Test test(name);

  Object kek = Object::New(env);

  kek.Set("name", test.getName());

  return kek;
}
