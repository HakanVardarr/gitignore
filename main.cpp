#include "Client.h"
#include "Temp.h"
#include <iostream>

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     std::cout << "Usage: gitignore <language>" << std::endl;
    //     return 1;
    // }

    // Client client(argv[1]);

    // std::string response_body;
    // int res = client.get(&response_body);

    // if (res == -1)
    // {
    //     return 1;
    // }

    Temp::init("gitignore");
    Temp::current();

    return 0;
}