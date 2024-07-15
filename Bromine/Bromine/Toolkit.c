#include "Toolkit.h"

static JNINativeMethod NativeMethods[] = {
	{"getScreenSize", "()Lcom/khopan/bromine/unit/Size;", (void*) &Toolkit_getScreenSize},
};

void ToolkitRegisterNatives(JNIEnv* const environment) {
	jclass windowClass = (*environment)->FindClass(environment, "com/khopan/bromine/Toolkit");

	if(!windowClass) {
		return;
	}

	(*environment)->RegisterNatives(environment, windowClass, NativeMethods, sizeof(NativeMethods) / sizeof(NativeMethods[0]));
}
