#pragma once

#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

// Aliases
namespace fs = std::filesystem;
using String = std::string;
using Path = fs::path;
using Json = nlohmann::json;
using std::cout;
