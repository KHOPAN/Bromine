#include <Windows.h>
#include "Window.h"
#include "Toolkit.h"

HINSTANCE globalInstance;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* virtualMachine, void* reserved) {
	JNIEnv* environment = NULL;

	if((*virtualMachine)->GetEnv(virtualMachine, (void**) &environment, JNI_VERSION_21) || !environment) {
		return JNI_ABORT;
	}

	WindowRegisterNatives(environment);
	ToolkitRegisterNatives(environment);
	return JNI_VERSION_21;
}
