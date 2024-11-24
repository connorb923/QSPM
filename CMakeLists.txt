cmake_minimum_required (VERSION 3.8)

# Set C++ standard to 20 (for all compilers)
set(CMAKE_CXX_STANDARD 20)

# Project definition
project ("QSPM")

# Add executable with all source and header files
add_executable (QSPM 
    "src/main.cpp"
    "include/main.hpp"
    "lib/sqlite3/sqlite3.c"
    "include/database.hpp"
    "include/log.hpp"
    "src/database.cpp"
    "src/log.cpp"
)

# Include the sqlite3 directory for headers
include_directories("lib/sqlite3")

