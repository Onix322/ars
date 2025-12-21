#include "FileWriter.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "Parser.h"
FileWriter* FileWriter::instancePtr = nullptr;
std::mutex FileWriter::mtx;

FileWriter* FileWriter::getInstance() {
  if (instancePtr == nullptr) {
    std::lock_guard<std::mutex> lock(mtx);
    if (instancePtr == nullptr) {
      instancePtr = new FileWriter();
    }
  }
  return instancePtr;
}

bool FileWriter::write(std::filesystem::path& target,
                       std::vector<Property>& properties) {
  std::map<std::string, std::vector<Property>> sections;

  for (auto prop : properties) {
    sections[prop.section].push_back(prop);
  }

  std::ofstream targetFile(target);

  for (auto section : sections) {
    std::string newS = section.first;  // copie
    std::replace(newS.begin(), newS.end(), '_', ' ');
    targetFile << '[' << newS << ']' << std::endl;
    for (auto val : section.second) {
      targetFile << val.key << "=" << val.value << std::endl;
    }
  }

  targetFile.close();
  return 0;
}
