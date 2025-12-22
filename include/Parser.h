#pragma once

#include <map>
#include <mutex>
#include <ostream>
#include <string>
#include <vector>

struct Argument {
  std::string key;
  std::string value;
  bool operator==(const Argument& other) const {
    return key == other.key && value == other.value;
  }
  friend std::ostream& operator<<(std::ostream& os, const Argument& a) {
    os << "{" << a.key << ": " << a.value << "}" << std::endl;
    return os;
  }
};

struct Property {
  std::string section;
  std::string key;
  std::string value;
  bool operator==(const Property& other) const {
    return section == other.section && key == other.key && value == other.value;
  }
  friend std::ostream& operator<<(std::ostream& os, const Property& a) {
    os << "{" << a.section << "-> " << a.key << ": " << a.value << "}"
       << std::endl;
    return os;
  }
};

class Parser {
 private:
  static Parser* instancePtr;
  static std::mutex mtx;
  Parser() {};

 public:
  Parser(const Parser& obj) = delete;

  static Parser* getInstance();

  Argument parseArg(std::string& key, std::string& value);

  std::vector<Argument> parseArgs(std::map<std::string, std::string>& argMap);

  Property parseProperty(std::string& prop);

  std::vector<Property> parseProperties(std::vector<std::string>& props);
};
