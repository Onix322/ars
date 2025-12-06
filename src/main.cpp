#include <distribution.h>
#include <syntaxChecker.h>

#include <iostream>
int main(int argc, char* argv[]) {
  ArgsData argsData = distribution(argc, argv);

  std::cout << argsData.getProperties().size();
  // bool syntaxChecker = checkMultipleDesktopProps(argsData.getProperties());
  return 0;
}
