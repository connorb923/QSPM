#ifndef DATABASE_H
#define DATABASE_H

#include "main.hpp"

bool doesFileExist(const std::string& filename);
int initDB(const std::string& dbFilename);

#endif