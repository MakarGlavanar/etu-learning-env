#include <string>
#ifndef TASK
#define TASK

class Task
{
private:
  int theme;
  int index;
  std::string title;
  std::string description;
  std::string inputData;
  std::string outputData;
  std::string solution;

public:
  Task();

  Task(
      int _theme,
      std::string _title,
      std::string _description,
      std::string _inputData,
      std::string _outputData,
      std::string _solution);

  int getIndex();

  void setIndex(int index);

  int getTheme();

  std::string getTitle();

  std::string getDescription();

  std::string getInputData();

  std::string getOutputData();

  std::string getSolution();
};

#endif