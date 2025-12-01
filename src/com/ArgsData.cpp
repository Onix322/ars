#include <ArgsData.h>

#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string> ArgsData::getArgs() {
  return this->args;
}

std::vector<std::string> ArgsData::getProperties() {
  return this->properties;
}

void ArgsData::setArgs(std::map<std::string, std::string> args) {
  this->args = args;
}
