#include "QSPM.h"

using namespace std;

int main() {
    sqlite3 *db;
    char *errMessage = 0;

    // Open or create a database
    int rc = sqlite3_open("projects.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return(0);
    }

    // SQL statement for creating the table
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS Projects (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            PROJECT TEXT,
            PATH TEXT,
            FAVORITE BOOLEAN,
            TAGS TEXT
        );
    )";

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, &errMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    } else {
        std::cout << "Table created successfully or already exists." << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);
    
    return 0;
}