#pragma once

#include <Windows.h>
#include <jni.h>

void BromineThrowWin32Error(JNIEnv* const environment, const LPWSTR functionName);
