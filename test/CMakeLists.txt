
cmake_minimum_required(VERSION 3.22)

project(MyProjectTest VERSION 1.0 LANGUAGES CXX)

include(FetchContent)

# Source files
include_directories(../include)

set(SRC_FILES 
  "../src/com/distribution.cpp"
  "../src/com/syntaxChecker.cpp"
  "../src/com/syntaxFormatter.cpp"
  "../src/com/ArgsData.cpp"
)

file(GLOB_RECURSE SOURCES 
  "./*.cpp" 
)

# Executable
add_executable(myapptest 
  ${SOURCES} 
  ${SRC_FILES}
) 

set_target_properties(myapptest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(json)

target_link_libraries(myapptest PRIVATE nlohmann_json::nlohmann_json)

target_compile_features(myapptest PRIVATE cxx_std_20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

