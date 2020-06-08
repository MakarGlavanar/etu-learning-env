#include "StudentService.hpp"
#include "../uuid/UUIDService.hpp"
#include <iostream>

StudentService::StudentService(
    std::string inputFileName,
    std::string outputFileName) : inputFileName(inputFileName),
                                  outputFileName(outputFileName){};

Student StudentService::makeStudent(std::string fio, int groupId, int index)
{
  std::string id = uuid();
  Student student(id, fio, groupId, index);

  list.push_back(student);

  writeStudents();

  return student;
}

void StudentService::readStudents()
{
  input.open(inputFileName.c_str());
  
  bool wasStudentDataStarted = false;
  int dataIndex = 0;
  std::string line;
  std::string id;
  std::string fio;
  int groupId;
  int index;

  for (std::string line; getline(input, line, '\n');)
  {
    if (line != "")
    {
      if (!wasStudentDataStarted)
      {
        wasStudentDataStarted = true;
        dataIndex = 0;
      }
    }
    else
    {
      if (wasStudentDataStarted)
      {
        Student student(id, fio, groupId, index);

        list.push_back(student);
      }

      dataIndex = 0;
      wasStudentDataStarted = false;
    }

    if (wasStudentDataStarted)
    {
      switch (dataIndex)
      {
      case 0:
        id = line;
        break;

      case 1:
        fio = line;
        break;

      case 2:
        groupId = std::stoi(line);
        break;

      case 3:
        index = std::stoi(line);
        break;

      default:
        break;
      }

      dataIndex += 1;
    }
  }

  input.close();
}

Student *StudentService::getStudents()
{
  const int STUDENTS_COUNT = list.size();
  Student *students = new Student[STUDENTS_COUNT];
  int i = 0;

  for (Student stud : list)
  {
    students[i++] = stud;
  }

  return students;
}

int StudentService::getStudentsCount()
{
  return list.size();
}

void StudentService::deleteStudent(std::string id)
{
  Student searchingStudent;

  for (Student stud : list)
  {
    if (stud.getId() == id)
    {
      searchingStudent = stud;
    }
  }

  // list.remove(searchingStudent);
}

void StudentService::writeStudents() {
  output.open(outputFileName.c_str());

  for (Student stud : list)
  {
    output << stud.getId() << "\n";
    output << stud.getFio() << "\n";
    output << stud.getGroupId() << "\n";
    output << stud.getIndex() << "\n";
    output << "\n";
  }

  output.close();
}

StudentService::~StudentService() {
  list.clear();
}
