#include <ArgsData.h>

#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string>& ArgsData::getArgs() {
  return this->args;
}

std::vector<std::string>& ArgsData::getProperties() {
  return this->properties;
}

void ArgsData::addProperty(std::string property) {
  this->properties.push_back(property);
}

void ArgsData::addArg(std::string key, std::string value) {
  this->args.insert({key, value});
}

void ArgsData::setArgs(std::map<std::string, std::string> args) {
  this->args = args;
}
