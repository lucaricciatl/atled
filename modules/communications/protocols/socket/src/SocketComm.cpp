#include "SocketCommunication.hpp"

// Constructor initializes the IP and port
SocketCommunication::SocketCommunication(const std::string& ip_addr, int port_no) : ip(ip_addr), port(port_no) {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        std::cerr << "Socket creation failed!" << std::endl;
    }
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &address.sin_addr);
}

// Destructor closes the socket connection
SocketCommunication::~SocketCommunication() {
    closeConnection();
}

// Method to start the server and listen for connections
bool SocketCommunication::startServer() {
    if (bind(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Binding failed!" << std::endl;
        return false;
    }

    if (listen(socket_fd, 3) < 0) {
        std::cerr << "Listening failed!" << std::endl;
        return false;
    }

    std::cout << "Server is listening on port " << port << std::endl;

    int new_socket;
    int addrlen = sizeof(address);
    if ((new_socket = accept(socket_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Accepting connection failed!" << std::endl;
        return false;
    }

    socket_fd = new_socket;
    return true;
}

// Method to connect to a server
bool SocketCommunication::connectToServer() {
    if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Connection to server failed!" << std::endl;
        return false;
    }

    std::cout << "Connected to server!" << std::endl;
    return true;
}

// Method to send a message with error handling and mutex protection
bool SocketCommunication::sendMessage(const std::string& message) {
    std::lock_guard<std::mutex> lock(socket_mutex);  // Ensure thread safety

    ssize_t sent_bytes = send(socket_fd, message.c_str(), message.length(), 0);
    if (sent_bytes < 0) {
        std::cerr << "Sending message failed: " << strerror(errno) << std::endl;
        return false;
    }

    std::cout << "Message sent: " << message << std::endl;
    return true;
}

// Method to receive a message with error handling and timeout
std::string SocketCommunication::receiveMessage() {
    std::lock_guard<std::mutex> lock(socket_mutex);  // Ensure thread safety

    std::vector<char> buffer(1024);
    ssize_t bytes_read = recv(socket_fd, buffer.data(), buffer.size(), 0);

    if (bytes_read == 0) {
        std::cerr << "Connection closed by the other party." << std::endl;
        return "";
    } else if (bytes_read < 0) {
        if (errno == EWOULDBLOCK || errno == EAGAIN) {
            std::cerr << "Receive timeout reached." << std::endl;
        } else {
            std::cerr << "Receiving message failed: " << strerror(errno) << std::endl;
        }
        return "";
    }

    return std::string(buffer.begin(), buffer.begin() + bytes_read);
}

// Method to set a timeout for socket operations
void SocketCommunication::setSocketTimeout(int seconds) {
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = 0;

    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        std::cerr << "Failed to set receive timeout." << std::endl;
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
        std::cerr << "Failed to set send timeout." << std::endl;
    }
}

// Method to close the socket connection
void SocketCommunication::closeConnection() {
    std::lock_guard<std::mutex> lock(socket_mutex);  // Ensure thread safety
    if (socket_fd != -1) {
        close(socket_fd);
        socket_fd = -1;
        std::cout << "Socket connection closed." << std::endl;
    }
}