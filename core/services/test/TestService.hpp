#include <string>
#include "../../models/test/Test.hpp"
#include "../task/TaskService.hpp"

#ifndef TEST_SERVICE
#define TEST_SERVICE

class TestService {
  private:
    TaskService* service;
  
  public:
    TestService();

    Test generateTest(int index, std::string title);

    int getTasksCount();
};

#endif
