#include "Temp.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

namespace Temp
{
    void init(const char *file_path)
    {
        fs::path dir_path = fs::path(file_path);

        fs::current_path(fs::temp_directory_path());
        if (!fs::exists(dir_path))
        {
            fs::create_directories("gitignore");
        }

        fs::current_path(dir_path);
    }

    void current()
    {
        std::cout << "Current directory: " << fs::current_path() << std::endl;
    }
}