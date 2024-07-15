#pragma once

#include <jni.h>

void ToolkitRegisterNatives(JNIEnv* const environment);
jobject Toolkit_getScreenSize(JNIEnv* const environment, const jclass toolkitClass);
