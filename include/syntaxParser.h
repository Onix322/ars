#pragma once

#include <string>
struct Property {
  std::string section;
  std::string key;
  std::string value;
  bool operator==(const Property& other) const {
    return section == other.section && key == other.key && value == other.value;
  }
};
template <typename V>
V parse(std::string& prop);
