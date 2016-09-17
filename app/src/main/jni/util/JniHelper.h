
#ifndef ANDROID_JNITEST_MASTER_JNIHELPER_H
#define ANDROID_JNITEST_MASTER_JNIHELPER_H

#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Register one or more native methods with a particular class.
 * "className" looks like "java/lang/String". Aborts on failure.
 * TODO: fix all callers and change the return type to void.
 */
int jniRegisterNativeMethods(C_JNIEnv* env, const char* className, const JNINativeMethod* gMethods, int numMethods);

#ifdef __cplusplus
}
#endif

/*
 * For C++ code, we provide inlines that map to the C functions.  g++ always
 * inlines these, even on non-optimized builds.
 */
#if defined(__cplusplus)
inline int jniRegisterNativeMethods(JNIEnv* env, const char* className, const JNINativeMethod* gMethods, int numMethods) {
    return jniRegisterNativeMethods(&env->functions, className, gMethods, numMethods);
}
#endif

#define NATIVE_METHOD(className, functionName, signature) \
    { #functionName, signature, reinterpret_cast<void*>(className ## _ ## functionName) }

# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))


#endif //ANDROID_JNITEST_MASTER_JNIHELPER_H
