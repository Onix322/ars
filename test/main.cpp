#include <Dispacher.h>
#include <Parser.h>

#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>
using std::string;

template <typename T>
void expect_equals(const T& input, const T& expected, std::string test_name) {
  if (input == expected) {
    std::cout << "TEST PASSED: ---> " << test_name << std::endl;
  } else {
    std::cerr << "TEST FAILED: ---> " << test_name << std::endl;
  };
}
template <typename T>
void printArray(T arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << std::endl;
  }
}
template <typename K, typename V>
void printMap(std::map<K, V> map) {
  for (const auto& [key, value] : map) {
    std::cout << key << ": " << value << std::endl;
  }
}

void test_syntaxChecker(SyntaxAnalizer& analizer) {
  std::cout << std::endl;

  const std::string name = "2. TEST syntaxChecker.cpp";
  const char* input[] = {
      "--Desktop_Entry::Terminal=True", "--Desktop_Entry::Type=Application",
      "--Desktop_Entry::::", "--Desktop Entry::Termuinal=True", "Desktop::en"};

  std::vector<std::string> propertiesExpected = {
      "--Desktop_Entry::Terminal=True", "--Desktop_Entry::Type=Application"};
  std::vector<std::string> outputCorrect;
  std::vector<std::string> outputFail;

  for (const char* prop : input) {
    if (analizer.checkDesktopPropSyntax(prop)) {
      outputCorrect.push_back(prop);
      continue;
    }
    outputFail.push_back(prop);
  }

  expect_equals(propertiesExpected, outputCorrect, name);

  std::cout << "Data Expected:" << std::endl;
  printArray(propertiesExpected);

  std::cout << "Output CORRECT" << std::endl;
  printArray(outputCorrect);

  std::cout << "Output FAILED" << std::endl;
  printArray(outputFail);

  std::cout << std::endl;
}

void test_parser_properties(Parser& parser) {
  std::cout << std::endl;
  const auto name = "3.2. TEST syntaxFormatter.cpp -- parseProperties()";

  std::vector<std::string> input = {"--Desktop_Entry::Terminal=True"};
  const Property expected = Property("Desktop_Entry", "Terminal", "True");
  Property output = parser.parseProperty(input.at(0));

  expect_equals(output, expected, name);

  std::cout << "Data provided" << std::endl;
  printArray(input);
  std::cout << "Data expected:" << std::endl;
  std::cout << expected;
  std::cout << "Ouput:" << std::endl;
  std::cout << output;
}

void test_parser_args(Parser& parser) {
  std::cout << std::endl;
  const auto name = "3.1. TEST Parser.cpp -- parseArgs()";

  const char* input[] = {"-path", "-test"};
  const std::vector<Argument> expected = {Argument("path", ""),
                                          Argument("test", "")};
  std::vector<Argument> output;

  for (std::string arg : input) {
    Argument argument = parser.parseArgs(arg);
    output.push_back(argument);
  }

  expect_equals(expected, output, name);

  std::cout << "Data Expected:" << std::endl;
  printArray(expected);

  std::cout << "Output" << std::endl;
  printArray(output);
}

void test_dispacher(Dispacher& dispacher) {
  const char* input[] = {"FRST_SKIPPED", "-path", "path/to/file",
                         "--Desktop_Entry::Terminal=True"};
  std::string name = "1.1. TEST Dispacher.cpp -> Dispacher (Singleton)";

  ArgsData providedData = dispacher.dispach(4, const_cast<char**>(input));
  ArgsData expectedData;

  std::map<std::string, std::string> expectedArgs;
  expectedArgs.insert({"-path", "path/to/file"});
  expectedData.setArgs(expectedArgs);

  std::vector<std::string> expectedProperties;
  expectedProperties.push_back("--Desktop_Entry::Terminal=True");
  expectedData.setProperties(expectedProperties);

  expect_equals<ArgsData>(providedData, expectedData, name);

  std::cout << "Data provided:" << std::endl;
  printArray(providedData.getProperties());
  printMap(providedData.getArgs());

  std::cout << "Data expected:" << std::endl;
  printArray(expectedData.getProperties());
  printMap(expectedData.getArgs());

  std::cout << std::endl;
}

int main() {
  // init Singletons
  SyntaxAnalizer* analizer = SyntaxAnalizer::getInstance();
  Dispacher::init(*analizer);
  Dispacher* dispacher = Dispacher::getInstance();
  Parser* parser = Parser::getInstance();

  // tests area
  test_parser_properties(*parser);
  test_parser_args(*parser);
  test_syntaxChecker(*analizer);
  test_dispacher(*dispacher);

  // free memory
  delete dispacher;
  delete parser;
  delete analizer;
  return 0;
}
