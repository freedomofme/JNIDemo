/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

/* Header for class jnicourse_hhx_com_jnidemo_DynamicTest2 */

#ifndef _Included_jnicourse_hhx_com_jnidemo_DynamicTest2
#define _Included_jnicourse_hhx_com_jnidemo_DynamicTest2
#ifdef __cplusplus
extern "C" {
#endif
jint register_DT2(JNIEnv * env);

/*
 * Class:     jnicourse_hhx_com_jnidemo_DynamicTest2
 * Method:    doTwo
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL addTwoNumber2(JNIEnv *, jobject, jint, jint);

static JNINativeMethod gJni_Methods_DynamicTest2[] = {
        {"doTwo", "(II)I", (void*)addTwoNumber2},
};

#ifdef __cplusplus
}
#endif
#endif
