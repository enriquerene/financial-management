#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <map>

class CLI {
    public:
        static std::vector<std::string> argvIntoVector(int argc, char **argv);

        static std::map<std::string, std::string> getFlags(std::vector<std::string> arguments);

        static std::vector<std::string> getCommands(std::vector<std::string> arguments);
};

#endif
