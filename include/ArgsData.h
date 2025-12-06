#include <map>
#include <string>
#include <vector>
class ArgsData {
 public:
  std::vector<std::string>& getProperties();
  std::map<std::string, std::string>& getArgs();
  void setProperties(std::vector<std::string> properties);
  void setArgs(std::map<std::string, std::string> args);
  void addProperty(std::string property);
  void addArg(std::string key, std::string value);

 private:
  std::vector<std::string> properties;
  std::map<std::string, std::string> args;
};
