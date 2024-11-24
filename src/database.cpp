#include "../include/database.h"
#include "../include/main.h"
#include "../include/log.h"

sqlite3* db;

bool doesFileExist(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int initDB(const std::string& dbFilename) {
    if (doesFileExist(dbFilename)) {
        return 0;
    }

    logMessage("[WARN][SQL] Database not found.");
    logMessage("[INFO][SQL] Creating new database.");

    char* errMessage = 0;
    int projDB = sqlite3_open(dbFilename.c_str(), &db);
    if (projDB) {
        std::string err = sqlite3_errmsg(db);
        std::cerr << "[ERROR][SQL] " << err << std::endl;
        logMessage("[ERROR][SQL] " + err);
        return 1;
    }

    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS Projects (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            PROJECT TEXT,
            PATH TEXT,
            FAVORITE BOOLEAN,
            TAGS TEXT
        );
    )";

    projDB = sqlite3_exec(db, sql, 0, 0, &errMessage);
    if (projDB != SQLITE_OK) {
        std::cerr << "[ERROR][SQL] " << sqlite3_errmsg(db) << std::endl;
        if (errMessage) {
            std::string err = errMessage;
            std::cerr << "[ERROR][SQL] " << err << std::endl;
            logMessage("[ERROR][SQL] " + err);
            sqlite3_free(errMessage);
        }
        sqlite3_close(db);
        return 1;
    }
    else {
        logMessage("[INFO][SQL] DATABASE CREATED");
    }

    return 0;
}
