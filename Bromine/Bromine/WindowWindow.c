#include <stdio.h>
#include <Windows.h>
#include "Window.h"
#include "exception.h"

typedef struct {
	LPCWSTR className;
} HBROMINE;

extern HINSTANCE globalInstance;

static LRESULT CALLBACK windowProcedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {
	switch(message) {
	case WM_CLOSE:
		DestroyWindow(window);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProcW(window, message, wparam, lparam);
}

void Window_buildWindow(JNIEnv* const environment, const jobject windowInstance, const jstring className) {
	LPCWSTR classNameNative;
	jint length;

	if(className && (length = (*environment)->GetStringLength(environment, className)) && (classNameNative = (*environment)->GetStringChars(environment, className, NULL))) {
		size_t totalLength = (length + 1) * sizeof(WCHAR);
		LPWSTR buffer = LocalAlloc(LMEM_FIXED, totalLength);

		if(!buffer) {
			BromineThrowWin32Error(environment, L"LocalAlloc");
			(*environment)->ReleaseStringChars(environment, className, classNameNative);
			return;
		}

		memcpy(buffer, classNameNative, totalLength);
		buffer[length] = 0;
		(*environment)->ReleaseStringChars(environment, className, classNameNative);
		classNameNative = buffer;
	} else {
		LPWSTR buffer = LocalAlloc(LMEM_FIXED, sizeof(WCHAR) * 14);

		if(!buffer) {
			BromineThrowWin32Error(environment, L"LocalAlloc");
			return;
		}

		buffer[0] = L'B';
		buffer[1] = L'r';
		buffer[2] = L'o';
		buffer[3] = L'm';
		buffer[4] = L'i';
		buffer[5] = L'n';
		buffer[6] = L'e';
		buffer[7] = L'W';
		buffer[8] = L'i';
		buffer[9] = L'n';
		buffer[10] = L'd';
		buffer[11] = L'o';
		buffer[12] = L'w';
		buffer[13] = 0;
		classNameNative = buffer;
	}

	printf("Class Name: %ws\n", classNameNative);
	LocalFree(classNameNative);
	/*WNDCLASSW windowClass = {0};
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

	(*environment)->SetLongField(environment, windowInstance, handleField, (jlong) window);*/
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

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
}
