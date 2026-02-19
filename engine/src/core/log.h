#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

#include "../defines.h"

// set debug messages based on the version of the engine
#ifdef VERSION_RELEASE
#define ENABLE_DEBUG = 0
#else
#define ENABLE_DEBUG = 1
#endif

// types of log calls
enum LogType {
    TYPE_INFO = 0   ,
    TYPE_DEBUG = 1  ,
    TYPE_WARNING = 2,
    TYPE_ERROR = 3  ,
};

bool initializeLogger();

void shutdownLogger();

void insertIntoLogFile(std::string text);

// templates and exporting/importing functions isn't a option, but even without the prefix for export, 
// it still is seen by the application, so it can be used by it

template<typename ...argument>
void log(LogType type, argument... message) {
    std::string head[] = { "[INFO]: ", "[DEBUG]: ", "[WARN]: ", "[ERROR]: "};
    int colorID[] = { /* green */       32,
                      /* blue */        94,
                      /* yellow */      33, 
                      /* red */         91,
    };
    std::stringstream buffer;
    std::stringstream fileBuffer;
    std::string output;
    std::string fileOutput;

    // streaming the messages into one string
    if (type != TYPE_DEBUG) {
        buffer << "\033[" << colorID[type] << "m";
        buffer << head[type];
        ((buffer << message << " "), ...);
        buffer << "\033[0m\n";

        fileBuffer << head[type];
        ((fileBuffer << message << " "), ...);
        fileBuffer << '\n';
    }
    else {
        #if defined ENABLE_DEBUG == 1
        buffer << "\033[" << colorID[type] << "m";
        buffer << head[type];
        ((buffer << message << " "), ...);
        buffer << "\033[0m\n";

        fileBuffer << head[type];
        ((fileBuffer << message << " "), ...);
        fileBuffer << '\n';
        #endif
    }
    output = buffer.str();
    std::cout << output;

    fileOutput = fileBuffer.str();
    insertIntoLogFile(fileOutput);
}


// macros for shorter log calls
#define OX_ERROR(message, ...) log(TYPE_ERROR, message, ##__VA_ARGS__) 

#define OX_WARN(message, ...) log(TYPE_WARNING, message, ##__VA_ARGS__) 

#define OX_INFO(message, ...) log(TYPE_INFO, message, ##__VA_ARGS__) 

#define OX_DEBUG(message, ...) log(TYPE_DEBUG, message, ##__VA_ARGS__) 