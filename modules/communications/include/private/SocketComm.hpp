#ifndef SOCKET_COMMUNICATION_H
#define SOCKET_COMMUNICATION_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <sys/socket.h>
#include <chrono>
#include <vector>

class SocketCommunication {
private:
    int socket_fd;
    struct sockaddr_in address;
    int port;
    std::string ip;
    std::mutex socket_mutex;  // For thread-safe access to the socket

public:
    SocketCommunication(const std::string& ip_addr, int port_no);
    ~SocketCommunication();

    bool startServer();
    bool connectToServer();
    bool sendMessage(const std::string& message);
    std::string receiveMessage();
    void setSocketTimeout(int seconds);
    void closeConnection();
};

#endif