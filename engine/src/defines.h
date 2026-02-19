#pragma once

// Operating system check
#ifdef _WIN32
#define OS_WINDOWS_32
#elif _WIN64
#define OS_WINDOWS_64
#elif __unix || __unix__
#define OS_UNIX
#elif __APPLE__ || __MACH__
#define OS_MAC
#elif __linux__
#define OS_LINUX
#endif

// set allowance for logging and assertion systems
#define ENABLE_ASSERTIONS = 1
#define ENABLE_ERRORS = 1
#define ENABLE_WARNINGS = 1
#define ENABLE_INFO = 1
#define ENABLE_DEBUG = 1

// version of the build
#define VERSION_DEBUG
//#define VERSION_RELEASE

// shorter unsigned int types
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;

// exporting and importing functions from the engine library
#ifdef LIBRARY_EXPORTS
#define OX_API __declspec(dllexport)
#else
#define OX_API __declspec(dllimport)
#endif
