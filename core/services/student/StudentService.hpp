#include <string>
#include <fstream>
#include <algorithm>
#include <list>

#include "../../models/student/Student.hpp"

#ifndef STUDENT_SERVICE
#define STUDENT_SERVICE

class StudentService {
  private:
    std::list<Student> list;
    std::ifstream input;
    std::ofstream output;
  
  public:
    StudentService(std::string inputFileName, std::string outputFileName);

    Student makeStudent(std::string fio, int groupId, int index);

    std::string readStudents();

    Student* getStudents();

    int getStudentsCount();

    void deleteStudent(std::string id);
};

#endif