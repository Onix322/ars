#include <ArgsData.h>

#include <optional>

ArgsData distribution(int argc, char* argv[]) {
  ArgsData ad;
  std::optional<std::string> argReminderOp;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == '-') {
      ad.addProperty(argv[i]);
    } else if (argv[i][0] == '-') {
      ad.addArg(argv[i], "");
      argReminderOp = argv[i];
    } else {
      if (!argReminderOp.has_value()) continue;
      ad.getArgs().insert_or_assign(argReminderOp.value(), argv[i]);
      argReminderOp.reset();
    }
  }

  return ad;
}
