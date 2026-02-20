#include "log.h"
#include "assert.h"

static std::ofstream logSaveFile;

bool initializeLogger() {
    logSaveFile.open("log.log");
    if(!logSaveFile.is_open()) {
        return false;
    }
    return true;
}

void shutdownLogger() {
    logSaveFile.close();
}

void report_assertion(const char* expression, std::string message, std::string file, uint line) {
    if (message.empty()) {
        log(TYPE_ERROR, "Faulty code:", expression, "in file:", file, "at line", line);
        return;
    } 
    log(TYPE_ERROR, message, "| Faulty code:", expression, "in file:", file, "at line", line);
}

void insertIntoLogFile(std::string text) {
    logSaveFile << text;
}