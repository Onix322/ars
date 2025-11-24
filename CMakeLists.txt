cmake_minimum_required(VERSION 3.15)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# C++ VERSION
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Executable
add_executable(myapp ${SOURCES})
# Modules
target_compile_options(myapp PRIVATE -fmodules-ts)
# Link libs 
file(GLOB EXTERNAL_LIBS RELATIVE ${CMAKE_SOURCE_DIR}/external ${CMAKE_SOURCE_DIR}/external/*)

foreach(lib ${EXTERNAL_LIBS})
    if(EXISTS ${CMAKE_SOURCE_DIR}/external/${lib}/CMakeLists.txt)
        add_subdirectory(external/${lib})
        target_link_libraries(myapp PRIVATE ${lib}::${lib})
    endif()
endforeach()
