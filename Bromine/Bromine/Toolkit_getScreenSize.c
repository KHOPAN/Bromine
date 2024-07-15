#include <Windows.h>
#include "Toolkit.h"

jobject Toolkit_getScreenSize(JNIEnv* const environment, const jclass toolkitClass) {
	jclass sizeClass = (*environment)->FindClass(environment, "com/khopan/bromine/unit/Size");

	if(!sizeClass) {
		return NULL;
	}

	jmethodID constructorSize = (*environment)->GetMethodID(environment, sizeClass, "<init>", "(II)V");

	if(!constructorSize) {
		return NULL;
	}

	return (*environment)->NewObject(environment, sizeClass, constructorSize, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
}
