#include <Windows.h>
#include "Window.h"
#include "exception.h"

extern HINSTANCE globalInstance;

static LRESULT CALLBACK windowProcedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {
	return DefWindowProcW(window, message, wparam, lparam);
}

void Window_buildWindow(JNIEnv* const environment, const jobject windowInstance, const jstring className) {
	WNDCLASSW windowClass = {0};
	windowClass.style = CS_VREDRAW | CS_HREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = globalInstance;
	windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
	const jchar* classNameNative = className ? (*environment)->GetStringChars(environment, className, NULL) : NULL;
	windowClass.lpszClassName = classNameNative ? classNameNative : L"BromineWindow";
	ATOM result = RegisterClassW(&windowClass);

	if(!result) {
		BromineThrowWin32Error(environment, L"RegisterClassW");

		if(classNameNative) {
			(*environment)->ReleaseStringChars(environment, className, classNameNative);
		}

		return;
	}

	HWND window = CreateWindowExW(0L, windowClass.lpszClassName, L"Bromine Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 200, 200, NULL, NULL, NULL, NULL);

	if(classNameNative) {
		(*environment)->ReleaseStringChars(environment, className, classNameNative);
	}

	if(!window) {
		BromineThrowWin32Error(environment, L"CreateWindowExW");
	}

	jclass classWindow = (*environment)->GetObjectClass(environment, windowInstance);

	if(!classWindow) {
		return;
	}

	jfieldID handleField = (*environment)->GetFieldID(environment, classWindow, "handle", "J");

	if(!handleField) {
		return;
	}

	(*environment)->SetLongField(environment, windowInstance, handleField, (jlong) window);
}

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
