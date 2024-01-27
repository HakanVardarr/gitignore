#include "Client.h"
#include "Temp.h"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: gitignore <language>" << std::endl;
        return 1;
    }

    Temp::init();
    Client client(argv[1]);
    std::string gitignore_content;

    bool b_temp_file = Temp::check_file(argv[1]);
    if (b_temp_file)
    {
        Temp::read_file(gitignore_content, argv[1]);
    }
    else
    {
        int res = client.get(&gitignore_content);
        if (res == -1)
        {
            return 1;
        }
    }

    return 0;
}