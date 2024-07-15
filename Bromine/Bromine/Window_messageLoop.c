#include <Windows.h>
#include "Window.h"

void Window_messageLoop(JNIEnv* const environment, const jobject windowInstance) {
	MSG message;

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
}
