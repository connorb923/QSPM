#include "../include/database.h"
#include "../include/main.h"
#include "../include/log.h"

int main() {
    const std::string dbFilename = "projects.db";
    const std::string logFilename = "QSPM-LOG.log";

    int logReturn = initLog(logFilename);
    if (logReturn != 0) {
        std::cerr << "[ERROR] Could not open log file!" << std::endl;
        return logReturn;
    }

    int initResult = initDB(dbFilename);
    if (initResult != 0) {
        logMessage("[ERROR] DATABASE FAILED TO CREATE");
        sqlite3_close(db);
        closeLog();
        return initResult;
    }

    logMessage("[INFO] Database initialized successfully.");
    sqlite3_close(db);

    closeLog();

    return 0;
}
