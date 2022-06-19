#include "./cli.h"

std::vector<std::string> CLI::argvIntoVector(int argc, char **argv) {
    std::vector<std::string> arguments;
    for (int i = 1; i < argc; ++i) {
        arguments.push_back(argv[i]);
    }
    return arguments;
}

std::map<std::string, std::string> CLI::getFlags(std::vector<std::string> arguments) {
    std::map<std::string, std::string> flags;
    for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); ++it) {
        std::string arg = *it;
        std::string key;
        std::string value = "";
        if (arg.substr(0, 2) == "--") {
            size_t pos = arg.find("=");
            if (pos != std::string::npos) {
                key = arg.substr(2, pos - 2);
                value = arg.substr(pos + 1);
            } else {
                key = arg.substr(2);
            }

            flags.insert({key, value});
        }
    }

    return flags;
}

std::vector<std::string> CLI::getCommands(std::vector<std::string> arguments) {
    std::vector<std::string> commands;
    for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); ++it) {
        std::string arg = *it;
        if (arg.substr(0, 2) != "--") {
            commands.push_back(arg);
        }
    }

    return commands;
}
