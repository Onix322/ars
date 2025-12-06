#include <regex>
#include <vector>

bool checkDesktopSyntax(std::string property) {
  std::regex pattern("--\\w+::\\w+=(?:\\w+|)");

  return std::regex_match(property, pattern);
}
bool checkMultipleDesktopProps(std::vector<std::string> properties) {
  for (auto prop : properties) {
    bool result = false;
    if (!checkDesktopSyntax(prop)) {
      return false;
    }
  }
  return true;
}
