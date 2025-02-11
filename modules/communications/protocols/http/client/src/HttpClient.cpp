#include "HttpClient.hpp"
#include <stdexcept>
#include <curl/curl.h>

// A helper structure to initialize and cleanup libcurl globally.
namespace {
    struct CurlGlobalInitializer {
        CurlGlobalInitializer() {
            if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
                throw std::runtime_error("Failed to initialize libcurl");
            }
        }
        ~CurlGlobalInitializer() {
            curl_global_cleanup();
        }
    };
    // Create a static instance to ensure libcurl is initialized once.
    static CurlGlobalInitializer curlInitializer;
}

HttpClient::HttpClient() {}

HttpClient::~HttpClient() {}

size_t HttpClient::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* response = static_cast<std::string*>(userp);
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

std::string HttpClient::get(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to create CURL handle");
    }
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpClient::WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("GET request failed: " + std::string(curl_easy_strerror(res)));
    }
    curl_easy_cleanup(curl);
    return response;
}

std::string HttpClient::post(const std::string& url, const std::string& data) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to create CURL handle");
    }
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpClient::WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("POST request failed: " + std::string(curl_easy_strerror(res)));
    }
    curl_easy_cleanup(curl);
    return response;
}
