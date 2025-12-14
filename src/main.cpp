#include <Dispacher.h>

#include <iostream>

#include "Parser.h"
int main(int argc, char* argv[]) {
  // dispaching
  Dispacher* dispacher = Dispacher::getInstance();
  ArgsData argsData = dispacher->dispach(argc, argv);
  std::cout << argsData.getProperties().size();
  // parser
  Parser* parser = Parser::getInstance();
  // mapper

  // Write data
  return 0;
}
