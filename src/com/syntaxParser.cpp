#include <syntaxParser.h>

#include <cassert>
#include <string>

template <>
std::string parse(std::string& arg) {
  if (arg[0] == '-') arg.erase(arg.begin());
  return arg;
}

template <>
Property parse<Property>(std::string& prop) {
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
