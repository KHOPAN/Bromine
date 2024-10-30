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

	parameter->function(data->bromine, parameter->parameter);
	return 0;
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

	switch(message) {
	case WM_CLOSE:
		BromineFreeBromine((BROMINE) data->bromine);
		HeapFree(GetProcessHeap(), 0, data);
		SetWindowLongPtrW(window, GWLP_USERDATA, 0);
		break;
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
