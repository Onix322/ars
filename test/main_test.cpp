#include <distribution.h>

#include <iostream>
#include <string>
#include <vector>
template <typename T>
void expect_equals(const T& input, const T& expected, std::string& test_name) {
  if (input == expected) {
    std::cout << "TEST PASSED: " << test_name;
  } else {
    std::cerr << "TEST FAILED: " << test_name;
  };
}

void test_syntaxFormatter() {}

void test_syntaxChecker() {}

void test_distribuitor() {
  // prep
  std::string testName = "DISTRIBUTION";
  char* input[] = {"./out/myapp", "-path", "path/to/text.txt",
                   "--Desktop_Entry::Terminal=True"};

  ArgsData dataProvided = distribution(4, input);
  ArgsData& refDataProvided = dataProvided;

  ArgsData expected;
  expected.setArgs({"-path", "path/to/text.txt"});
  expected.setProperties({"--Desktop_Entry::Terminal=True"});
  ArgsData& refExpected = expected;
  // run
  expect_equals(refDataProvided, refExpected, testName);
}

int main() {
  std::cout << "FROM TEST FILE";
  return 0;
}
