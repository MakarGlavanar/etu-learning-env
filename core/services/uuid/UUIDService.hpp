#include <string>
#include <sstream>

#ifndef _UUID
#define _UUID

namespace UUID {
  std::string uuid(const unsigned int len = 128);
}

#endif
