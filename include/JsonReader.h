#pragma once  // or #ifndef READER_H / #define READER_H / #endif

#include <common.h>

class JsonReader {
 public:
  JsonReader();
  Json readFile(const Path filename);
};
