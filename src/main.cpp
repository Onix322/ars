#include <distribution.h>

#include <iostream>
int main(int argc, char* argv[]) {
  // distribution
  ArgsData argsData = distributions(argc, argv);
  std::cout << argsData.getProperties().size();
  // formatter

  // mapper

  // Write data
  return 0;
}
