#include <filesystem>
#include <mutex>
#include <vector>

#include "Parser.h"
class FileWriter {
 public:
  static FileWriter* getInstance();
  FileWriter(const FileWriter& obj) = delete;

  bool write(std::filesystem::path& target, std::vector<Property>& propeties);

 private:
  static std::mutex mtx;
  static FileWriter* instancePtr;
  FileWriter() {};
};
