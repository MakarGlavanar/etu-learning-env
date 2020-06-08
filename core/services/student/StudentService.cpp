#include "StudentService.hpp"
#include "../uuid/UUIDService.hpp"
#include <iostream>

bool markInBounds(int targetMark, int currentMark)
{
  switch (targetMark)
  {
  case StudentMarks::C:
    return currentMark >= StudentMarks::C && currentMark < StudentMarks::B;

  case StudentMarks::B:
    return currentMark >= StudentMarks::B && currentMark < StudentMarks::A;

  case StudentMarks::A:
    return currentMark >= StudentMarks::A;

  default:
    break;
  }

  return false;
}

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

Student *StudentService::getStudents(int mark, int *count)
{
  const int STUDENTS_COUNT = list.size();
  Student *students = new Student[STUDENTS_COUNT];
  int i = 0;

  for (Student stud : list)
  {
    if (markInBounds(mark, stud.getMark())) {
      students[i++] = stud;
    }
  }

  const int FILTERED_STUDENTS_COUNT = i;
  
  if (FILTERED_STUDENTS_COUNT > 0) {
    Student *fixedStudents = new Student[FILTERED_STUDENTS_COUNT];

    for (int i = 0; i < FILTERED_STUDENTS_COUNT; i++) {
      fixedStudents[i] = students[i];
    }

    *count = FILTERED_STUDENTS_COUNT;
    std::cout << *count << "\n";
    return fixedStudents;
  }

  return NULL;
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

void StudentService::writeStudents()
{
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

StudentService::~StudentService()
{
  list.clear();
}
