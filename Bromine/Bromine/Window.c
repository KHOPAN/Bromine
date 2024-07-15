#include "Window.h"

static JNINativeMethod NativeMethods[] = {
	{"showWindow",  "()V",                   (void*) &Window_showWindow},
	{"buildWindow", "(Ljava/lang/String;)V", (void*) &Window_buildWindow},
	{"messageLoop", "()V",                   (void*) &Window_messageLoop}
};

void WindowRegisterNatives(JNIEnv* const environment) {
	jclass windowClass = (*environment)->FindClass(environment, "com/khopan/bromine/Window");

	if(!windowClass) {
		return;
	}

	(*environment)->RegisterNatives(environment, windowClass, NativeMethods, sizeof(NativeMethods) / sizeof(NativeMethods[0]));
}
