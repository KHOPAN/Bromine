#include "bromine.h"

BROMINEERROR BromineInitialize() {
	WNDCLASSEXW windowClass = {0};
	windowClass.cbSize = sizeof(WNDCLASSEXW);
	windowClass.lpfnWndProc = DefWindowProcW;
	windowClass.lpszClassName = BROMINE_CLASS;
	return RegisterClassExW(&windowClass) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}

BROMINEERROR BromineCleanup() {
	return UnregisterClassW(BROMINE_CLASS, NULL) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}
