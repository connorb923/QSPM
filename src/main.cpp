#include "QSPM.h"

sqlite3* db;

bool doesFileExist(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int initDB(const std::string& dbFilename) {
    if (doesFileExist(dbFilename)) {
        return 0;
    }

    std::cout << "[INFO] Inital Setup" << std::endl;
    std::cout << "[INFO] Creating Projects Database" << std::endl;

    char* errMessage = 0;

    int projDB = sqlite3_open(dbFilename.c_str(), &db);
    if (projDB) {
        std::cerr << "[ERROR][SQL] " << sqlite3_errmsg(db) << std::endl;
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
            std::cerr << "[ERROR][SQL] " << errMessage << std::endl;
            sqlite3_free(errMessage);
        }
        sqlite3_close(db);
        return 1;
    }
    else {
        std::cout << "[SQL] DATABASE CREATED" << std::endl;
    }

    return 0;
}

int main() {
    const std::string dbFilename = "projects.db";

    int result = initDB(dbFilename);
    if (result != 0) {
        sqlite3_close(db);
        std::cerr << "[ERROR][SQL] DATABASE FAILED TO CREATE";
        return result;
    }

    sqlite3_close(db);
    return 0;
}