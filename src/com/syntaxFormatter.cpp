#include <syntaxFormatter.h>

#include <cassert>
#include <iostream>
#include <string>

std::string argFormat(std::string arg) {
  std::cout << "Arg Before: " << arg;

  if (arg[0] == '-') arg.erase(0);
  std::cout << "Arg After: " << arg;
  return arg;
}

std::string propertyFormat(std::string prop) {
  return "";
}
