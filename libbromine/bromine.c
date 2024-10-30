#include "bromine.h"

typedef struct {
	ROOTBROMINE bromine;
} BROMINEDATA, *PBROMINEDATA;

static int initializeBromine(const HWND window, const PBROMINECREATEPARAMETER parameter) {
	PBROMINEDATA data = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(BROMINEDATA));

	if(!data) {
		return -1;
	}

	SetWindowLongPtrW(window, GWLP_USERDATA, (LONG_PTR) data);
	BROMINEERROR error = BromineNewBromine((PBROMINE) &data->bromine, TRUE);

	if(BROMINE_FAILED(error)) {
		goto freeData;
	}

	return parameter->function(data->bromine, parameter->parameter) ? 0 : -1;
freeData:
	HeapFree(GetProcessHeap(), 0, data);
	return -1;
}

static LRESULT CALLBACK procedure(_In_ HWND window, _In_ UINT message, _In_ WPARAM wparam, _In_ LPARAM lparam) {
	if(message == WM_CREATE) {
		return initializeBromine(window, (PBROMINECREATEPARAMETER) ((LPCREATESTRUCTW) lparam)->lpCreateParams);
	}

	PBROMINEDATA data = (PBROMINEDATA) GetWindowLongPtrW(window, GWLP_USERDATA);

	if(!data) {
		return DefWindowProcW(window, message, wparam, lparam);
	}

	PAINTSTRUCT paintStruct = {0};
	RECT bounds;
	HDC context;

	switch(message) {
	case WM_CLOSE:
		BromineFreeBromine((BROMINE) data->bromine);
		HeapFree(GetProcessHeap(), 0, data);
		SetWindowLongPtrW(window, GWLP_USERDATA, 0);
		break;
	case WM_PAINT:
		GetClientRect(window, &bounds);
		context = BeginPaint(window, &paintStruct);

		if(data->bromine->bromine.renderer) {
			data->bromine->bromine.renderer((BROMINE) data->bromine, context, &bounds);
		}

		EndPaint(window, &paintStruct);
		return 0;
	}

	return DefWindowProcW(window, message, wparam, lparam);
}

BROMINEERROR BromineInitialize() {
	WNDCLASSEXW windowClass = {0};
	windowClass.cbSize = sizeof(WNDCLASSEXW);
	windowClass.lpfnWndProc = procedure;
	windowClass.lpszClassName = BROMINE_CLASS;
	return RegisterClassExW(&windowClass) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}

BROMINEERROR BromineCleanup() {
	return UnregisterClassW(BROMINE_CLASS, NULL) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}
