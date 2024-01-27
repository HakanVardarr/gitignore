#include "Gitignore.h"

#include <fstream>
#include <iostream>

int Gitignore::run()
{
    bool b_temp_file = Temp::check_file(language);
    if (b_temp_file)
    {
        Temp::read_file(output, language);
    }
    else
    {
        int res = client.get(&output);
        if (res == -1)
        {
            return 1;
        }
        Temp::write_file(output, language);
    }

    std::filesystem::path file_path = std::filesystem::path(current_path / ".gitignore");
    std::cout << file_path << std::endl;

    std::ofstream gitignore_file(file_path);

    if (gitignore_file.is_open())
    {
        gitignore_file << output;
        gitignore_file.close();
    }
    else
    {
        std::cout << "[ERROR]: Error happened when opening file for writing" << std::endl;
        return 1;
    }

    return 0;
}