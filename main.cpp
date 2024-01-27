#include "Gitignore.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: gitignore <language>" << std::endl;
        return 1;
    }

    Gitignore app(argv[1]);
    return app.run();
}