#pragma once

#include "../defines.h"
#include <string>
#include "../application.h"

#if defined ENABLE_ASSERTIONS == 1

OX_API void report_assertion(const char* expression, std::string message, std::string file, uint line);

// variants of assertions with and without messages

#define OX_ASSERT_MESSAGE(expr, message)            \
{                                                   \
    if (!(expr)) {                                  \
        report_assertion(#expr, message, __FILE__, __LINE__); \
        shutdownProgram();                          \
        exit(0);                                    \
    }                                               \
}

#define OX_ASSERT(expr)                             \
{                                                   \
    if (!(expr)) {                                  \
        report_assertion(#expr, "", __FILE__, __LINE__);      \
        shutdownProgram();                          \
        exit(0);                                    \
    }                                               \
}

#endif