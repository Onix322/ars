#include "JsonReader.h"
#include "common.h"
Path toPath(const String& configFilePath) {
  return configFilePath;
}

int main(int argc, char* argv[]) {
  if (argc != 2) return 128;
  Path configPath = toPath(argv[1]);
  JsonReader jsonReader;
  Json json = jsonReader.readFile(configPath);

  cout << json.dump(2);
  return 0;
}
