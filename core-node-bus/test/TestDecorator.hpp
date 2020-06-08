#include "napi.h"
#include "../../core/models/test/Test.hpp"

using namespace Napi;

Object decorateTest(Env env, Test test);

Object generateTest(const CallbackInfo& info);
