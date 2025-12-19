#pragma once
#include <ArgsData.h>

#include <mutex>

#include "syntaxAnalizer.h"
class Dispacher {
 private:
  static Dispacher* instancePtr;
  static std::mutex mtx;
  Dispacher(SyntaxAnalizer& syntaxAnalizer) {};

  SyntaxAnalizer* syntaxAnalizer;

 public:
  Dispacher(const Dispacher& obj) = delete;

  static void init(SyntaxAnalizer& analizer);

  static Dispacher* getInstance();

  ArgsData dispach(int argc, char* argv[]);
};
