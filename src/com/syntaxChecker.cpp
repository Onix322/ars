#include <iostream>
#include <regex>
#include <stdexcept>

bool checkDesktopPropSyntax(std::string property) {
  std::regex pattern(R"(--[A-Za-z0-9_-]+::[A-Za-z0-9_-]+=[A-Za-z0-9_-]*)");

  return std::regex_match(property, pattern);
}

bool checkDesktopPropSyntaxSafe(std::string property) {
  try {
    if (!checkDesktopPropSyntax(property)) {
      throw std::runtime_error("Property typo : " + property);
    }
    return true;
  } catch (std::runtime_error& e) {
    std::cerr << e.what();
    return false;
  }
}
