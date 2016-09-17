
#include "JniHelper.h"


//#include "JniDebug.h"


#include <stdlib.h>

/**
 * Equivalent to ScopedLocalRef, but for C_JNIEnv instead. (And slightly more powerful.)
 */
template<typename T>
class scoped_local_ref {
public:
    scoped_local_ref(C_JNIEnv* env, T localRef = NULL)
            : mEnv(env), mLocalRef(localRef)
    {
    }

    ~scoped_local_ref() {
        reset();
    }

    void reset(T localRef = NULL) {
        if (mLocalRef != NULL) {
            (*mEnv)->DeleteLocalRef(reinterpret_cast<JNIEnv*>(mEnv), mLocalRef);
            mLocalRef = localRef;
        }
    }

    T get() const {
        return mLocalRef;
    }

private:
    C_JNIEnv* mEnv;
    T mLocalRef;

    // Disallow copy and assignment.
    scoped_local_ref(const scoped_local_ref&);
    void operator=(const scoped_local_ref&);
};

static jclass findClass(C_JNIEnv* env, const char* className) {
    JNIEnv* e = reinterpret_cast<JNIEnv*>(env);
    return (*env)->FindClass(e, className);
}

extern "C" int jniRegisterNativeMethods(C_JNIEnv* env, const char* className,
                                        const JNINativeMethod* gMethods, int numMethods)
{
    JNIEnv* e = reinterpret_cast<JNIEnv*>(env);

//    JniDebug("Registering %s natives", className);

    scoped_local_ref<jclass> c(env, findClass(env, className));
    if (c.get() == NULL) {
//        JniDebug("Native registration unable to find class '%s', aborting", className);
        abort();
    }

    if ((*env)->RegisterNatives(e, c.get(), gMethods, numMethods) < 0) {
//        JniDebug("RegisterNatives failed for '%s', aborting", className);
        abort();
    }

    return 0;
}