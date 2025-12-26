#include <filesystem>
#include <mutex>
#include <vector>

#include "Parser.h"
class FileWritter {
 public:
  static FileWritter* getInstance();
  FileWritter(const FileWritter& obj) = delete;

  bool write(std::filesystem::path& target, std::vector<Property>& propeties);

 private:
  static std::mutex mtx;
  static FileWritter* instancePtr;
  FileWritter() {};
};
