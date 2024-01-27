#ifndef GITIGNORE_H
#define GITIGNORE_H

#include <string>
#include <filesystem>

#include "Temp.h"
#include "Client.h"

class Gitignore
{
    std::filesystem::path current_path;
    std::string language;
    Client client;
    std::string output;

public:
    Gitignore(std::string language) : language(language), client(Client(language)), current_path(std::filesystem::current_path())
    {
        Temp::init();
    }
    int run();
};

#endif