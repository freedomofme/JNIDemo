//
// Created by CodeYel on 16/9/17.
//

#include "jnicourse_hhx_com_jnidemo_DynamicTest2.h"
#include "util/JniHelper.h"

#ifdef __cplusplus
extern "C" {
#endif

static const char *className2 = "jnicourse/hhx/com/jnidemo/DynamicTest2";

jint register_DT2(JNIEnv * env) {
    return jniRegisterNativeMethods(env, className2, gJni_Methods_DynamicTest2, NELEM(gJni_Methods_DynamicTest2));
}


JNIEXPORT jint JNICALL addTwoNumber2(JNIEnv *env, jobject, jint param1, jint param2) {
//    __android_log_print(ANDROID_LOG_INFO, "JNIMsg", " Log Content ");
    return 10 * (param1 + param2);
}

#ifdef __cplusplus
}
#endif

