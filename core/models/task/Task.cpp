#include "./Task.hpp"

Task::Task() {};

Task::Task(
    int _theme,
    std::string _title,
    std::string _description,
    std::string _inputData,
    std::string _outputData,
    std::string _solution)
{
  theme = _theme;
  title = _title;
  description = _description;
  inputData = _inputData;
  outputData = _outputData;
  solution = _solution;
};

int Task::getIndex()
{
  return index;
}

void Task::setIndex(int _index)
{
  index = _index;
}

int Task::getTheme()
{
  return theme;
}

std::string Task::getTitle()
{
  return title;
}

std::string Task::getDescription()
{
  return description;
}

std::string Task::getInputData()
{
  return inputData;
}

std::string Task::getOutputData()
{
  return outputData;
}

std::string Task::getSolution()
{
  return solution;
}
