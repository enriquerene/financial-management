#include "./api.h"

API::API(std::vector<std::string> commands, std::map<std::string, std::string> flags) {
    this->commands = commands;
    this->flags = flags;
};

std::string API::run () {
    return "running API commands...";
};
