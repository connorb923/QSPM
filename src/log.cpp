#include "../include/database.hpp"
#include "../include/main.hpp"
#include "../include/log.hpp"

std::ofstream logFile;

int initLog(const std::string& logFilename) {
    logFile.open(logFilename, std::ios::app);
    if (!logFile.is_open()) {
        return 1;
    }
    else {
        logMessage("[ACCESS][LOG] Program ran");
        return 0;
    }
}

#ifdef _WIN32

std::string getCurrentTime() {
    std::time_t timeStamp = std::time(0);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&timeStamp));
    return std::string(buffer);
}

#else

std::string getCurrentTime() {
    std::time_t now = std::time(0);
    char buffer[80];
    std::tm* timeinfo = std::localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo); // Use strftime without std::
    return std::string(buffer);
}

#endif

void logMessage(const std::string& message) {
    if (logFile.is_open()) {
        logFile << getCurrentTime() << " - " << message << std::endl;
    }
    else {
        std::cerr << "[ERROR][LOG] Log file is not open!" << std::endl;
    }
}

void closeLog() {
    if (logFile.is_open()) {
        logMessage("[INFO][LOG] Log file closed.");
        logFile.close();
    }
}