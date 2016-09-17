LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := NdkTest

FILE_LIST := $(wildcard $(LOCAL_PATH)/dynamic/*.cpp) \
 $(wildcard $(LOCAL_PATH)/static/*.cpp) \
 $(wildcard $(LOCAL_PATH)/util/*.cpp)

#方法一
#LOCAL_SRC_FILES := static/StaticBind.cpp
#LOCAL_SRC_FILES += dynamic/DynamicBind.cpp
#LOCAL_SRC_FILES += dynamic/DynamicBind2.cpp
#LOCAL_SRC_FILES += util/JniHelper.cpp
#LOCAL_SRC_FILES += util/JniDebug.cpp

#方法二
FILE_LIST := $(wildcard $(LOCAL_PATH)/dynamic/*.cpp) \
 $(wildcard $(LOCAL_PATH)/static/*.cpp) \
 $(wildcard $(LOCAL_PATH)/util/*.cpp)
LOCAL_SRC_FILES :=$(FILE_LIST:$(LOCAL_PATH)/%=%)


LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)