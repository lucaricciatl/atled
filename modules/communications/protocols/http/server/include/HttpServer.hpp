#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <string>
#include <functional>

class HttpServer {
public:
    // The RequestHandler receives the request line and returns a response body.
    using RequestHandler = std::function<std::string(const std::string& request)>;

    // Construct an HTTP server that listens on the specified port.
    HttpServer(unsigned short port);
    ~HttpServer();

    // Set the function that will handle incoming HTTP requests.
    void setRequestHandler(RequestHandler handler);

    // Start the server (non-blocking).
    void start();

    // Stop the server.
    void stop();

private:
    // PIMPL idiom to hide implementation details.
    class Impl;
    Impl* impl;
};

#endif // HTTP_SERVER_HPP
