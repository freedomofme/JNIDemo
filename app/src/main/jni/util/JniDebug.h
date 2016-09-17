

#ifndef JNIDEMO_JNIDEBUG_H
#define JNIDEMO_JNIDEBUG_H
#include "jni.h"
#include "stdio.h"
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

void JniDebug(const char format[], ...);

#ifdef __cplusplus
}
#endif


#endif //JNIDEMO_JNIDEBUG_H
