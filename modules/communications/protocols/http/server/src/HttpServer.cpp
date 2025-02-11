#include "HttpServer.hpp"
#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <iostream>
#include <sstream>

using boost::asio::ip::tcp;

class HttpServer::Impl {
public:
    Impl(unsigned short port)
        : io_context(),
          acceptor(io_context, tcp::endpoint(tcp::v4(), port)),
          is_running(false)
    {}

    ~Impl() {
        stop();
    }

    void setRequestHandler(HttpServer::RequestHandler handler) {
        request_handler = handler;
    }

    void start() {
        is_running = true;
        doAccept();
        // Run the I/O context in a separate thread.
        server_thread = std::thread([this]() {
            try {
                io_context.run();
            } catch (std::exception& e) {
                std::cerr << "Server encountered an error: " << e.what() << std::endl;
            }
        });
    }

    void stop() {
        if (is_running) {
            is_running = false;
            io_context.stop();
            if (server_thread.joinable()) {
                server_thread.join();
            }
        }
    }

private:
    void doAccept() {
        acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                // Handle each connection in its own thread.
                std::thread(&Impl::handleSession, this, std::move(socket)).detach();
            }
            if (is_running) {
                doAccept();
            }
        });
    }

    void handleSession(tcp::socket socket) {
        try {
            boost::asio::streambuf request_buf;
            // Read until the end of the HTTP header.
            boost::asio::read_until(socket, request_buf, "\r\n\r\n");

            std::istream request_stream(&request_buf);
            std::string request_line;
            std::getline(request_stream, request_line);
            std::cout << "Received request: " << request_line << std::endl;

            // Call the request handler if set.
            std::string response_body = "No handler set";
            if (request_handler) {
                response_body = request_handler(request_line);
            }

            // Build a simple HTTP response.
            std::ostringstream response_stream;
            response_stream << "HTTP/1.1 200 OK\r\n";
            response_stream << "Content-Length: " << response_body.size() << "\r\n";
            response_stream << "Content-Type: text/plain\r\n";
            response_stream << "\r\n";
            response_stream << response_body;

            boost::asio::write(socket, boost::asio::buffer(response_stream.str()));
        } catch (std::exception& e) {
            std::cerr << "Error handling session: " << e.what() << std::endl;
        }
    }

    boost::asio::io_context io_context;
    tcp::acceptor acceptor;
    std::thread server_thread;
    std::atomic<bool> is_running;
    HttpServer::RequestHandler request_handler;
};

HttpServer::HttpServer(unsigned short port)
    : impl(new Impl(port))
{}

HttpServer::~HttpServer() {
    delete impl;
}

void HttpServer::setRequestHandler(RequestHandler handler) {
    impl->setRequestHandler(handler);
}

void HttpServer::start() {
    impl->start();
}

void HttpServer::stop() {
    impl->stop();
}
