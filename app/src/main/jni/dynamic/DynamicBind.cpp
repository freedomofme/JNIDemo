//
// Created by CodeYel on 16/9/17.
//

#include "jnicourse_hhx_com_jnidemo_DynamicTest.h"
#include "jnicourse_hhx_com_jnidemo_DynamicTest2.h"
#include "util/JniDebug.h"

#ifdef __cplusplus
extern "C" {
#endif


static const char *className = "jnicourse/hhx/com/jnidemo/DynamicTest";

static JNINativeMethod gJni_Methods_DynamicTest[] = {
        {"doTwo", "(II)I", (void*)addTwoNumber},
};

JNIEXPORT jint JNICALL addTwoNumber(JNIEnv *env, jobject, jint param1, jint param2) {
//    __android_log_print(ANDROID_LOG_INFO, "JNIMsg", " Log Content ");
    JniDebug("addTwoNumber\n");
    return 1000 * (param1 + param2);

}


static int jniRegisterNativeMethods(JNIEnv* env, const char* className, const JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;

    clazz = (env)->FindClass( className);
    if (clazz == NULL) {

        return -1;
    }
    int result = 0;
    if ((env)->RegisterNatives(clazz, gMethods, numMethods) < 0) {

        result = -1;
    }
    (env)->DeleteLocalRef(clazz);
    return result;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved){

    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    //动态注册一
    JniDebug("动态注册一");
    jniRegisterNativeMethods(env, className, gJni_Methods_DynamicTest, sizeof(gJni_Methods_DynamicTest) / sizeof(JNINativeMethod));

    //动态注册二, 依赖JniHelper进行注册
    JniDebug("动态注册二");
    register_DT2(env);


    return JNI_VERSION_1_4;
}

#ifdef __cplusplus
}
#endif