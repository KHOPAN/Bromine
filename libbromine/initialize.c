#include "bromine.h"

DWORD BromineInitialize() {
	WNDCLASSEXW windowClass = {0};
	windowClass.cbSize = sizeof(WNDCLASSEXW);
	return RegisterClassExW(&windowClass) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}

DWORD BromineCleanup() {
	return BROMINE_ERROR_FUNCTION_FAILED;
}
