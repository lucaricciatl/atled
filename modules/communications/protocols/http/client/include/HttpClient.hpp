#ifndef HTTP_CLIENT_HPP
#define HTTP_CLIENT_HPP

#include <string>

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    // Perform an HTTP GET request.
    std::string get(const std::string& url);

    // Perform an HTTP POST request with the given data.
    std::string post(const std::string& url, const std::string& data);

private:
    // Callback function used by libcurl to write incoming data.
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // HTTP_CLIENT_HPP
