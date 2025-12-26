#include <Dispacher.h>

#include <filesystem>
#include <optional>
#include <ranges>
#include <stdexcept>
#include <vector>

#include "FileWritter.h"
#include "Parser.h"

void writeDesktopFile(FileWritter& writer, std::vector<Property>& properties,
                      std::vector<Argument>& arguments) {
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
    writer.write(tagetedPath, properties);
  }
}

int main(int argc, char* argv[]) {
  auto* analizer = SyntaxAnalizer::getInstance();
  Dispacher::init(*analizer);
  auto* dispacher = Dispacher::getInstance();
  auto* parser = Parser::getInstance();
  auto* writter = FileWritter::getInstance();
  // dispaching
  ArgsData argsData = dispacher->dispach(argc, argv);
  // parsing
  std::vector<Argument> arguments = parser->parseArgs(argsData.getArgs());
  std::vector<Property> properties =
      parser->parseProperties(argsData.getProperties());

  // Write data
  writeDesktopFile(*writter, properties, arguments);

  // preventing memory liking
  delete analizer;
  delete dispacher;
  delete parser;
  delete writter;
  return 0;
}
