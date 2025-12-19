#include <mutex>
#include <string>

class SyntaxAnalizer {
 private:
  SyntaxAnalizer() {};
  static std::mutex mutex;
  static SyntaxAnalizer* instancePtr;

 public:
  SyntaxAnalizer(const SyntaxAnalizer& obj) = delete;
  static SyntaxAnalizer* getInstance();

  bool checkDesktopPropSyntaxSafe(std::string property);
  bool checkDesktopPropSyntax(std::string property);
};
