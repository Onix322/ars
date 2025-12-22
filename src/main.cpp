#include <Dispacher.h>

#include <filesystem>
#include <optional>
#include <ranges>
#include <stdexcept>
#include <vector>

#include "FileWriter.h"
#include "Parser.h"

int main(int argc, char* argv[]) {
  auto* analizer = SyntaxAnalizer::getInstance();
  Dispacher::init(*analizer);
  auto* dispacher = Dispacher::getInstance();
  auto* parser = Parser::getInstance();
  auto* writer = FileWriter::getInstance();
  // dispaching
  ArgsData argsData = dispacher->dispach(argc, argv);
  // parsing
  std::vector<Argument> arguments = parser->parseArgs(argsData.getArgs());
  std::vector<Property> properties =
      parser->parseProperties(argsData.getProperties());

  // Write data
  // TODO implement
  auto value =
      arguments | std::views::filter([](Argument a) { return a.key == "t"; });
  std::optional<Argument> found;

  if (!value.empty()) {
    found = *value.begin();
  } else {
    throw std::runtime_error("Target argument: '-t' not found");
  }

  if (found.has_value() && found->value.empty()) {
    throw std::runtime_error("Tageted path not found for argument: '-t'");
  } else {
    std::filesystem::path tagetedPath(found->value);
    writer->write(tagetedPath, properties);
  }

  delete analizer;
  delete dispacher;
  delete parser;
  delete writer;
  return 0;
}
