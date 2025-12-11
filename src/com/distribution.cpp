#include <ArgsData.h>
#include <syntaxChecker.h>

#include <optional>

ArgsData distribution(int argc, char* argv[]) {
  ArgsData ad;
  std::optional<std::string> argReminderOp;

  for (int i = 1; i < argc; i++) {
    if (((std::string)argv[i]).size() < 1) continue;

    if (((std::string)argv[i]).starts_with("--")) {
      // Properties
      if (!checkDesktopPropSyntaxSafe(argv[i])) continue;
      ad.addProperty(argv[i]);
    } else if (((std::string)argv[i])[0] == '-' &&
               ((std::string)argv[i])[1] != '-') {
      // Args
      ad.addArg(argv[i], "");
      argReminderOp = argv[i];
    } else {
      // Values for args
      if (!argReminderOp.has_value()) continue;
      ad.getArgs().insert_or_assign(argReminderOp.value(), argv[i]);
      ad.addArg(argReminderOp.value(), argv[i]);
      argReminderOp.reset();
    }
  }

  return ad;
}
