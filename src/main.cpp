#include <Dispacher.h>

#include <vector>

#include "Parser.h"

int main(int argc, char* argv[]) {
  auto* analizer = SyntaxAnalizer::getInstance();
  Dispacher::init(*analizer);
  auto* dispacher = Dispacher::getInstance();
  auto* parser = Parser::getInstance();

  // dispaching
  ArgsData argsData = dispacher->dispach(argc, argv);
  // parsing
  std::vector<Argument> arguments = parser->parseArgs(argsData.getArgs());
  std::vector<Property> properties =
      parser->parseProperty(argsData.getProperties());
  // mapper

  // Write data
  return 0;
}
