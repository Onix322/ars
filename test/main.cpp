#include <distribution.h>

#include <cstdio>
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

void test_syntaxChecker() {}

void test_distribuiton() {
  const char* input[] = {"FRST_SKIPPED", "-path", "path/to/file",
                         "--Desktop_Entry::Terminal=True"};
  std::string name = "TEST distribution.cpp";

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
}

int main() {
  test_distribuiton();
  return 0;
}
