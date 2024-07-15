#include <stdio.h>
#include <Windows.h>
#include "Window.h"
#include "exception.h"

typedef struct {
	LPWSTR className;
	JNIEnv* environment;
	jobject windowInstance;
	jmethodID renderWindowMethod;
} HBROMINE, *PHBROMINE;

extern HINSTANCE globalInstance;

static LRESULT CALLBACK windowProcedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam) {
	PHBROMINE bromine = (PHBROMINE) GetWindowLongPtrW(window, GWLP_USERDATA);

	if(!bromine) {
		if(message != WM_CREATE) {
			return DefWindowProcW(window, message, wparam, lparam);
		}

		bromine = (PHBROMINE) (((CREATESTRUCT*) lparam)->lpCreateParams);
		SetWindowLongPtrW(window, GWLP_USERDATA, (LONG_PTR) bromine);
	}

	switch(message) {
	case WM_CLOSE:
		DestroyWindow(window);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT: {
		PAINTSTRUCT paintStruct;
		BeginPaint(window, &paintStruct);
		EndPaint(window, &paintStruct);
		(*bromine->environment)->CallVoidMethod(bromine->environment, bromine->windowInstance, bromine->renderWindowMethod);
		return 0;
	}
	}

	return DefWindowProcW(window, message, wparam, lparam);
}

void Window_buildWindow(JNIEnv* const environment, const jobject windowInstance, const jstring className) {
	jclass classWindow = (*environment)->GetObjectClass(environment, windowInstance);

	if(!classWindow) {
		return;
	}

	jclass itemClass = (*environment)->FindClass(environment, "com/khopan/bromine/Item");

	if(!itemClass) {
		return;
	}

	jmethodID renderWindowMethod = (*environment)->GetMethodID(environment, classWindow, "renderWindow", "()V");

	if(!renderWindowMethod) {
		return;
	}

	jfieldID handleField = (*environment)->GetFieldID(environment, classWindow, "handle", "J");

	if(!handleField) {
		return;
	}

	jfieldID titleField = (*environment)->GetFieldID(environment, classWindow, "title", "Ljava/lang/String;");

	if(!titleField) {
		return;
	}

	jfieldID xField = (*environment)->GetFieldID(environment, itemClass, "x", "I");

	if(!xField) {
		return;
	}

	jfieldID yField = (*environment)->GetFieldID(environment, itemClass, "y", "I");

	if(!yField) {
		return;
	}

	jfieldID widthField = (*environment)->GetFieldID(environment, itemClass, "width", "I");

	if(!widthField) {
		return;
	}

	jfieldID heightField = (*environment)->GetFieldID(environment, itemClass, "height", "I");

	if(!heightField) {
		return;
	}

	LPWSTR classNameNative;
	jint length;

	if(className && (length = (*environment)->GetStringLength(environment, className)) && (classNameNative = (LPWSTR) (*environment)->GetStringChars(environment, className, NULL))) {
		LPWSTR source = classNameNative;
		size_t totalLength = (((size_t) length) + 1) * sizeof(WCHAR);
		classNameNative = LocalAlloc(LMEM_FIXED, totalLength);

		if(!classNameNative) {
			BromineThrowWin32Error(environment, L"LocalAlloc");
			(*environment)->ReleaseStringChars(environment, className, source);
			return;
		}

		memcpy(classNameNative, source, totalLength);
		classNameNative[length] = 0;
		(*environment)->ReleaseStringChars(environment, className, source);
	} else {
		classNameNative = LocalAlloc(LMEM_FIXED, sizeof(WCHAR) * 14);

		if(!classNameNative) {
			BromineThrowWin32Error(environment, L"LocalAlloc");
			return;
		}

		classNameNative[0] = L'B';
		classNameNative[1] = L'r';
		classNameNative[2] = L'o';
		classNameNative[3] = L'm';
		classNameNative[4] = L'i';
		classNameNative[5] = L'n';
		classNameNative[6] = L'e';
		classNameNative[7] = L'W';
		classNameNative[8] = L'i';
		classNameNative[9] = L'n';
		classNameNative[10] = L'd';
		classNameNative[11] = L'o';
		classNameNative[12] = L'w';
		classNameNative[13] = 0;
	}

	PHBROMINE bromine = LocalAlloc(LMEM_FIXED, sizeof(HBROMINE));

	if(!bromine) {
		BromineThrowWin32Error(environment, L"LocalAlloc");
		LocalFree(classNameNative);
		return;
	}

	bromine->className = classNameNative;
	bromine->environment = environment;
	bromine->windowInstance = windowInstance;
	bromine->renderWindowMethod = renderWindowMethod;
	(*environment)->SetLongField(environment, windowInstance, handleField, (jlong) bromine);
	WNDCLASSW windowClass = {0};
	windowClass.style = CS_VREDRAW | CS_HREDRAW;
	windowClass.lpfnWndProc = windowProcedure;
	windowClass.hInstance = globalInstance;
	windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
	windowClass.lpszClassName = classNameNative;

	if(!RegisterClassW(&windowClass)) {
		BromineThrowWin32Error(environment, L"RegisterClassW");
		LocalFree(classNameNative);
		return;
	}

	jobject titleObject = (*environment)->GetObjectField(environment, windowInstance, titleField);
	const jchar* titleValue = titleObject ? (*environment)->GetStringChars(environment, titleObject, NULL) : NULL;
	HWND window = CreateWindowExW(0L, classNameNative, titleValue, WS_OVERLAPPEDWINDOW | WS_VISIBLE, (*environment)->GetIntField(environment, windowInstance, xField), (*environment)->GetIntField(environment, windowInstance, yField), (*environment)->GetIntField(environment, windowInstance, widthField), (*environment)->GetIntField(environment, windowInstance, heightField), NULL, NULL, NULL, bromine);

	if(titleValue) {
		(*environment)->ReleaseStringChars(environment, titleObject, titleValue);
	}

	if(!window) {
		BromineThrowWin32Error(environment, L"CreateWindowExW");
		LocalFree(classNameNative);
		return;
	}
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

	PHBROMINE bromine = (PHBROMINE) (*environment)->GetLongField(environment, windowInstance, handleField);
	MSG message;

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}

	if(!UnregisterClassW(bromine->className, globalInstance)) {
		BromineThrowWin32Error(environment, L"UnregisterClassW");
	}

	LocalFree(bromine->className);
	LocalFree(bromine);
}
