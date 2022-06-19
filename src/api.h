#ifndef API_H
#define API_H

#include <string>
#include <vector>

class API {
    private:
        /**
         * 0 - help
         * 1 - insert
         * 2 - read
         * 3 - update
         * 4 - delete
         */
        std::map<std::string, int> APIRef = {
            {"help", 0},
            {"insert", 1},
            {"inserir", 1},
            {"history", 2},
            {"historico", 2}
        };

        std::vector<std::string> commands;

        std::map<std::string, std::string> flags;

    public:
        API (std::vector<std::string> commands, std::map<std::string, std::string> flags);

        std::string run ();
};

#endif
