#pragma once
#include <ArgsData.h>

#include <mutex>
class Dispacher {
 private:
  static Dispacher* instancePtr;

  static std::mutex mtx;

  Dispacher() {};

 public:
  Dispacher(const Dispacher& obj) = delete;

  static Dispacher* getInstance();
  ArgsData dispach(int argc, char* argv[]);
};
