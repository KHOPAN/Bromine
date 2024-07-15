#include "Window.h"

static JNINativeMethod NativeMethods[] = {
	{"buildWindow",      "(Ljava/lang/String;)V", (void*) &Window_buildWindow},
	{"showWindow",       "()V",                   (void*) &Window_showWindow},
	{"startMessageLoop", "()V",                   (void*) &Window_startMessageLoop}
};

void WindowRegisterNatives(JNIEnv* const environment) {
	jclass windowClass = (*environment)->FindClass(environment, "com/khopan/bromine/Window");

	if(!windowClass) {
		return;
	}

	(*environment)->RegisterNatives(environment, windowClass, NativeMethods, sizeof(NativeMethods) / sizeof(NativeMethods[0]));
}
