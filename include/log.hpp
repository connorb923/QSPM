#ifndef LOG_H
#define LOG_H

#include "main.hpp"

int initLog(const std::string& logFilename);
void logMessage(const std::string& message);
void closeLog();

#endif