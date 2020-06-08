#include <random>

#include "UUIDService.hpp"

unsigned int random_char()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 255);
  return dis(gen);
}

std::string uuid(const unsigned int len)
{
  std::stringstream ss;
  for (unsigned int i = 0; i < len; i++)
  {
    const auto rc = random_char();
    std::stringstream hexstream;
    hexstream << std::hex << rc;
    auto hex = hexstream.str();
    ss << (hex.length() < 2 ? '0' + hex : hex);
  }
  return ss.str();
}