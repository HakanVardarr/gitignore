#include "Gitignore.h"

#include <curl/curl.h>
#include <iostream>

namespace Gitignore
{
    Client::Client(STRING language) : language(language)
    {
        url = "https://www.toptal.com/developers/gitignore/api/" + language;
    }

    int Client::get(STRING *response_body)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cout << "Error happened when initialiazing curl" << std::endl;
            return -1;
        }

        CURLcode res;
        char err_buf[CURL_ERROR_SIZE];
        const char *url_c_tring = url.c_str();

        curl_easy_setopt(curl, CURLOPT_URL, url_c_tring);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buf);
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Client::write_callback);

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
}