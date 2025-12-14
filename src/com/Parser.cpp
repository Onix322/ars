#include <Parser.h>

#include <cassert>
#include <mutex>
#include <string>

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

Argument Parser::parseArgs(std::string& arg) {
  if (arg[0] == '-') arg.erase(arg.begin());
  return Argument(arg, "");
}

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
