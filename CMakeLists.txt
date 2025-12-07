
cmake_minimum_required(VERSION 4.2)
project(MyProject VERSION 1.0 LANGUAGES CXX)

include(FetchContent)
# C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# Source files
include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(myapp ${SOURCES})


# ---------------------------
# nlohmann JSON (header-only)
# ---------------------------

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)
target_link_libraries(myapp PRIVATE nlohmann_json::nlohmann_json)

# Optional compile features
target_compile_features(myapp PRIVATE cxx_std_20)
