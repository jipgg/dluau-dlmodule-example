#ifndef DLMODULE_H
#define DLMODULE_H
#include <dluau.h>
#ifdef _MSC_VER // when compiled with windows-MSVC
    #ifdef DLMODULE_PROJECT_EXPORT
        #define DLMODULE_API extern "C" __declspec(dllexport)
    #else
        #define DLMODULE_API extern "C" __declspec(dllimport)
    #endif
#else // when compiled with other compilers
    #ifdef DLMODULE_PROJECT_EXPORT
        #define DLMODULE_API __attribute__((visibility("default")))
    #else
        #define DLMODULE_API
    #endif
#endif
#endif //DLMODULE_H
