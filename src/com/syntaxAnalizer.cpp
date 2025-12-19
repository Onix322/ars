#include <syntaxAnalizer.h>

#include <iostream>
#include <mutex>
#include <regex>
#include <stdexcept>
SyntaxAnalizer* SyntaxAnalizer::instancePtr = nullptr;
std::mutex SyntaxAnalizer::mutex;

SyntaxAnalizer* SyntaxAnalizer::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mutex);
    if (instancePtr == nullptr) {
      instancePtr = new SyntaxAnalizer();
    }
  }
  return instancePtr;
}

bool SyntaxAnalizer::checkDesktopPropSyntax(std::string property) {
  std::regex pattern(R"(--[A-Za-z0-9_-]+::[A-Za-z0-9_-]+=[A-Za-z0-9_-]*)");

  return std::regex_match(property, pattern);
}

bool SyntaxAnalizer::checkDesktopPropSyntaxSafe(std::string property) {
  try {
    if (!SyntaxAnalizer::checkDesktopPropSyntax(property)) {
      throw std::runtime_error("Property typo : " + property);
    }
    return true;
  } catch (std::runtime_error& e) {
    std::cerr << e.what();
    return false;
  }
}
