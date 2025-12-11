#include <distribution.h>
#include <syntaxChecker.h>

#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>
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

void test_syntaxFormatter() {}

void test_syntaxChecker() {
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
    if (checkDesktopPropSyntax(prop)) {
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

void test_distribuiton() {
  const char* input[] = {"FRST_SKIPPED", "-path", "path/to/file",
                         "--Desktop_Entry::Terminal=True"};
  std::string name = "1. TEST distribution.cpp";

  ArgsData providedData = distribution(4, const_cast<char**>(input));

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
  test_syntaxChecker();
  test_distribuiton();
  return 0;
}
