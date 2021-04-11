#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>
#include "vision/Network.hpp"
#include "vision/Config.hpp"

using namespace std;

bool Network::Sender::
sendCameraInfo(const int &cameraID, const int &people) {
    CURL *curl_handle;
    CURLcode res;
    curl_handle = curl_easy_init();
    if(curl_handle) {
        char curl_fields[] = "{\"cameraId\":\"%d\", \"people\":\"%d\"}";
        snprintf(curl_fields, sizeof(curl_fields), "{\"cameraId\":%d, \"people\":%d}", cameraID, people);


        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "charset: utf-8");

        curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl_handle, CURLOPT_URL, SERVER_URL.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_POST, 1);
        curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, curl_fields);

        res = curl_easy_perform(curl_handle);

        if(res != CURLE_OK) {
            fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl_handle);
        return res != CURLE_OK;
    }

    return false;
}