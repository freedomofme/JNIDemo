//
// Created by CodeYel on 16/9/17.
//

#include "jnicourse_hhx_com_jnidemo_StaticTest.h"


JNIEXPORT jint JNICALL Java_jnicourse_hhx_com_jnidemo_StaticTest_doAdd
        (JNIEnv *env, jobject object, jint param1, jint param2) {
    return param1 + param2;
}
