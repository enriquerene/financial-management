#include "../src/cli.cpp"

SCENARIO("History command", "[cli]") {
    GIVEN("No arguments") {
        THEN("display last 50 expenses entries") {
            std::vector<std::string> inputFromCLI = CLI::argvIntoVector(2, "app history");
            REQUIRE(CLI::getCommands(inputFromCLI) == "help");
        }
    }

    GIVEN("no commands and any flags given") {
        THEN("runs the help command") {
            std::vector<std::string> inputFromCLI = CLI::argvIntoVector(2, "app --flag=any");
            REQUIRE(CLI::getCommands(inputFromCLI) == "help");
        }
    }
}
