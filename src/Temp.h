#ifndef GITIGNORE_TEMP_H
#define GITIGNORE_TEMP_H

#include <string>

namespace Temp
{
    void init();
    void current();
    bool check_file(std::string language);
    bool read_file(std::string &file_content, std::string language);
    bool write_file(std::string &file_conten, std::string language);
}

#endif