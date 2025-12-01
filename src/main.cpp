#include <ArgsData.h>

#include <iostream>
#include <optional>

ArgsData distribution(int argc, char* argv[]) {
  ArgsData ad;
  std::optional<std::string> argReminderOp;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == '-') {
      ad.getProperties().push_back(argv[i]);
      std::cout << "prop:" << argv[i] << std::endl;

    } else if (argv[i][0] == '-') {
      ad.getArgs().insert({argv[i], ""});
      std::cout << "arg:" << argv[i] << std::endl;
      argReminderOp = argv[i];

    } else {
      if (!argReminderOp.has_value()) continue;
      ad.getArgs().insert_or_assign(argReminderOp.value(), argv[i]);
      argReminderOp.reset();
    }
  }

  return ad;
}

int main(int argc, char* argv[]) {
  distribution(argc, argv);
  return 0;
}
