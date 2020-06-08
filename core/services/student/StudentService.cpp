#include "StudentService.hpp"
#include "../uuid/UUIDService.hpp"
#include <iostream>

StudentService::StudentService(std::string inputFileName, std::string outputFileName)
{
  input.open(inputFileName.c_str());
  output.open(outputFileName.c_str());
}

Student StudentService::makeStudent(std::string fio, int groupId, int index)
{
  std::string id = UUID::uuid();
  Student student(id, fio, groupId, index);

  // list.push_front(student);

  return student;
}

std::string StudentService::readStudents()
{
  std::string result = "";
  std::string line;

  while (std::getline(input, line))
  {
    result += line + "*___*";
  }

  return result;
}

Student *StudentService::getStudents()
{
  const int STUDENTS_COUNT = list.size();
  Student *students = new Student[STUDENTS_COUNT];
  int i = 0;

  for (Student stud : list)
  {
    students[i] = stud;
  }

  return students;
}

int StudentService::getStudentsCount() {
  return list.size();
}

void StudentService::deleteStudent(std::string id) {
  Student searchingStudent;
  
  for (Student stud : list) {
    if (stud.getId() == id) {
      searchingStudent = stud;
    }
  }

  // list.remove(searchingStudent);
}
