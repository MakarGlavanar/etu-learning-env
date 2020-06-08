#include <string>

#ifndef STUDENT
#define STUDENT

class Student
{
private:
  std::string id;
  std::string fio;
  int groupId;
  int index;

public:
  Student();

  Student(
      std::string id,
      std::string fio,
      int groupId,
      int index);

  std::string getId();

  std::string getFio();

  int getGroupId();

  int getIndex();
};

#endif
