# FILE AUTOMATICALLY CREATED BY MSVS 2022

cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("QSPM")

add_executable (QSPM "src/main.cpp" "include/main.hpp" "lib/sqlite3/sqlite3.c" "include/database.hpp" "include/log.hpp" "src/database.cpp" "src/log.cpp")

include_directories("lib/sqlite3")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QSPM PROPERTY CXX_STANDARD 20)
endif()
