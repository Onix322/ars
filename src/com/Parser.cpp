#include <Parser.h>

#include <cassert>
#include <map>
#include <mutex>
#include <string>
#include <vector>

Parser* Parser::instancePtr = nullptr;
std::mutex Parser::mtx;

Parser* Parser::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new Parser();
    }
  }
  return instancePtr;
}

Argument Parser::parseArg(std::string& key, std::string& value) {
  return Argument(key[0] == '-' ? key.substr(1) : key, value);
}

std::vector<Argument> Parser::parseArgs(
    std::map<std::string, std::string>& argMap) {
  std::vector<Argument> args;
  for (auto pair : argMap) {
    std::string key = pair.first;
    Argument parsedArg = parseArg(key, pair.second);
    args.push_back(parsedArg);
  }
  return args;
};

Property Parser::parseProperty(std::string& prop) {
  // --Terminal=True -> key=Terminal && value=True
  std::string section;
  std::string key;
  std::string value;
  char leader = 0;
  for (int i = 0; i < prop.size(); i++) {
    char c = prop.at(i);
    switch (c) {
      case '=':
        leader = '=';
        i++;
        break;
      case '-':
        if (leader != '-') {
          leader = '-';
          i++;
          continue;
        }
        break;
      case ':':
        if (leader != ':') {
          leader = ':';
          i++;
          continue;
        }
        break;
    }

    c = prop.at(i);
    switch (leader) {
      case '-':
        section += c;
        break;
      case '=':
        value += c;
        break;
      case ':':
        key += c;
        break;
    }
  }

  return Property(section, key, value);
}

std::vector<Property> Parser::parseProperties(std::vector<std::string> props) {
  std::vector<Property> properties;
  for (auto p : props) {
    properties.push_back(this->parseProperty(p));
  }

  return properties;
}
