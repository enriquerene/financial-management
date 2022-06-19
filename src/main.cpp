#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "./cli.cpp"
#include "./api.cpp"

int main(int argc, char **argv) {
    std::string programmName = argv[0];
    std::vector<std::string> argumentsFromCLI = CLI::argvIntoVector(argc, argv);
    std::map<std::string, std::string> flags = CLI::getFlags(argumentsFromCLI);
    std::vector<std::string> commands = CLI::getCommands(argumentsFromCLI);

    API api(commands, flags);

    std::cout << api.run() << std::endl;

    return 1;
}
