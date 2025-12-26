#include "FileWritter.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "Parser.h"
FileWritter* FileWritter::instancePtr = nullptr;
std::mutex FileWritter::mtx;

FileWritter* FileWritter::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new FileWritter();
    }
  }
  return instancePtr;
}

bool FileWritter::write(std::filesystem::path& target,
                        std::vector<Property>& properties) {
  std::map<std::string, std::vector<Property>> sections;

  // order
  for (auto prop : properties) {
    sections[prop.section].push_back(prop);
  }

  std::ofstream targetFile(target);

  for (auto section : sections) {
    // format
    std::string newS = section.first;
    std::replace(newS.begin(), newS.end(), '_', ' ');
    // write
    targetFile << '[' << newS << ']' << std::endl;
    for (auto val : section.second) {
      targetFile << val.key << "=" << val.value << std::endl;
    }
  }

  targetFile.close();
  return 0;
}
