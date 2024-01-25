#include <iostream>
#include <filesystem>
#include <curl/curl.h>

class GitignoreClient
{
    std::string url;
    std::string language;

    static size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *response)
    {
        size_t totalSize = size * nmemb;
        response->append(static_cast<char *>(contents), totalSize);
        return totalSize;
    }

public:
    GitignoreClient(std::string l)
    {
        url = "https://www.toptal.com/developers/gitignore/api/" + l;
        language = l;
    }
    int get(std::string *response_body)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cout << "Error happened when initialiazing curl" << std::endl;
        }

        CURLcode res;
        char err_buf[CURL_ERROR_SIZE];
        const char *url_c_tring = url.c_str();

        curl_easy_setopt(curl, CURLOPT_URL, url_c_tring);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buf);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &GitignoreClient::write_callback);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            size_t len = strlen(err_buf);
            if (len > 0)
            {
                std::cout << err_buf << std::endl;
            };

            curl_easy_cleanup(curl);
            return -1;
        }

        long http_status_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status_code);

        if (http_status_code != 200)
        {
            std::cout << language << " is undefined." << std::endl;
            return -1;
        }

        curl_easy_cleanup(curl);
        return 0;
    }
};

class LocalCache
{
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: gitignore <language>" << std::endl;
        return 1;
    }

    GitignoreClient client(argv[1]);
    std::string response_body;
    int res = client.get(&response_body);

    if (res == -1)
    {
        return 1;
    }

    std::cout << response_body << std::endl;
    return 0;
}