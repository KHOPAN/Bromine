#pragma once

#include <jni.h>

void WindowRegisterNatives(JNIEnv* const environment);
void Window_buildWindow(JNIEnv* const environment, const jobject windowInstance, const jstring className);
void Window_showWindow(JNIEnv* const environment, const jobject windowInstance);
void Window_startMessageLoop(JNIEnv* const environment, const jobject windowInstance);
