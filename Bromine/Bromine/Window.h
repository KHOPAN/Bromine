#pragma once

#include <jni.h>

void WindowRegisterNatives(JNIEnv* const environment);
void Window_show(JNIEnv* const environment, const jobject windowInstance);
void Window_loop(JNIEnv* const environment, const jobject windowInstance);
void Window_buildWindow(JNIEnv* const environment, const jobject windowInstance, const jstring className, const jint x, const jint y, const jint width, const jint height);
