#include "Window.h"

static JNINativeMethod NativeMethods[] = {
	{"show",              "()V",                                               (void*) &Window_show},
	{"loop",              "()V",                                               (void*) &Window_loop},
	{"buildWindow",       "(Ljava/lang/String;IIII)V",                         (void*) &Window_buildWindow},
	{"dispatchRendering", "(J[Lcom/khopan/bromine/render/PaintInstruction;)V", (void*) &Window_dispatchRendering}
};

void WindowRegisterNatives(JNIEnv* const environment) {
	jclass windowClass = (*environment)->FindClass(environment, "com/khopan/bromine/Window");

	if(!windowClass) {
		return;
	}

	(*environment)->RegisterNatives(environment, windowClass, NativeMethods, sizeof(NativeMethods) / sizeof(NativeMethods[0]));
}
