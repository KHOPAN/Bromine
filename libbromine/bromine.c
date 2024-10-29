#include "bromine.h"

static LRESULT CALLBACK procedure(_In_ HWND window, _In_ UINT message, _In_ WPARAM wparam, _In_ LPARAM lparam) {
	switch(message) {
	case WM_CREATE: {
		PBROMINECREATEPARAMETER parameter = ((LPCREATESTRUCTW) lparam)->lpCreateParams;
		parameter->function(parameter->parameter);
		return 0;
	}
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
