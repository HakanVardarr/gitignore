#ifndef GITIGNORE_CLIENT_H
#define GITIGNORE_CLIENT_H

#include <string>

namespace Gitignore
{

#define STRING std::string

    class Client
    {
        STRING url;
        STRING language;

        static size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *response)
        {
            size_t totalSize = size * nmemb;
            response->append(static_cast<char *>(contents), totalSize);
            return totalSize;
        }

    public:
        Client(STRING language);
        int get(STRING *response_body);
    };
}

#endif