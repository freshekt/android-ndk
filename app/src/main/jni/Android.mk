LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := CPPExample
LOCAL_SRC_FILES := CPPExample.cpp
include $(BUILD_SHARED_LIBRARY)