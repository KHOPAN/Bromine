#include <Windows.h>
#include "Window.h"

void Window_messageLoop(JNIEnv* const environment, const jobject windowInstance) {
	jclass windowClass = (*environment)->GetObjectClass(environment, windowInstance);

	if(!windowClass) {
		return;
	}

	jfieldID handleField = (*environment)->GetFieldID(environment, windowClass, "handle", "J");

	if(!handleField) {
		return;
	}

	HWND window = (HWND) (*environment)->GetLongField(environment, windowInstance, handleField);
	MSG message;

	while(GetMessageW(&message, window, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
}
