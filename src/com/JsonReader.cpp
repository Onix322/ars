#include "JsonReader.h"

#include <fstream>

#include "common.h"

JsonReader::JsonReader() {}

Json JsonReader::readFile(Path path) {
  std::ifstream file(path);
  Json data = Json::parse(file);
  return data;
}
