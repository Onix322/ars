
#include <fmt/base.h>
#include <fmt/core.h>

#include <filesystem>
#include <iostream>

using std::cout;
using String = std::string;
using Path = std::filesystem::path;

Path toPath(String configFilePath);

int main(int argc, char* argv[]) {
  if (argc < 2) return 128;

  String configFile = argv[1];
  Path path = toPath(configFile);

  fmt::print("I love Beatrice <3");
  cout << path << path.extension();
  return 0;
}

Path toPath(String configFilePath) {
  Path* path = new Path(configFilePath);
  return *path;
}
