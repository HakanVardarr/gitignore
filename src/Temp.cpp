#include "Temp.h"

#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

namespace Temp
{

    void init()
    {
        fs::path dir_path = fs::path("gitignore");

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

    bool check_file(std::string language)
    {

        fs::path file_path = fs::path(fs::current_path() / language);

        if (fs::exists(file_path))
        {
            return true;
        }

        return false;
    }

    bool read_file(std::string &file_content, std::string language)
    {
        fs::path file_path = fs::path(fs::current_path() / language);
        std::ifstream temp_file(file_path);

        if (temp_file.is_open())
        {
            temp_file.seekg(0, std::ios::end);
            std::streamsize file_size = temp_file.tellg();
            temp_file.seekg(0, std::ios::beg);
            file_content.resize(static_cast<std::size_t>(file_size));

            temp_file.read(&file_content[0], file_size);

            temp_file.close();
        }
        else
        {
            std::cout << "[ERROR]: Error happened when opening file" << std::endl;
            return false;
        }

        return true;
    }
    bool write_file(std::string &file_content, std::string language)
    {
        fs::path file_path = fs::path(fs::current_path() / language);
        std::ofstream temp_file(file_path);

        if (temp_file.is_open())
        {
            temp_file << file_content;
            temp_file.close();
        }
        else
        {
            std::cout << "[ERROR]: Error happened when opening file for writing" << std::endl;
            return false;
        }

        return true;
    }
}