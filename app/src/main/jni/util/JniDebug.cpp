#include "JniDebug.h"

#define LOG_TAG "Debug"

#ifdef __cplusplus
extern "C" {
#endif

void JniDebug(const char format[], ...) {
    va_list args;
    va_start(args, format);
    __android_log_vprint(ANDROID_LOG_DEBUG, LOG_TAG, format, args);
    va_end(args);
}

#ifdef __cplusplus
}
#endif