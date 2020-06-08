#include "Student.hpp"

Student::Student(){};

Student::Student(
    std::string id,
    std::string fio,
    int groupId,
    int index) : id(id),
                 fio(fio),
                 groupId(groupId),
                 index(index){};

std::string Student::getId() {
  return id;
}

std::string Student::getFio()
{
  return fio;
}

int Student::getGroupId()
{
  return groupId;
}

int Student::getIndex()
{
  return index;
}
