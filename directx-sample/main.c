#include <stdio.h>
#include "graphics.h"

#define CLASS_NAME L"DirectXSampleClass"

LRESULT CALLBACK procedure(_In_ HWND window, _In_ UINT message, _In_ WPARAM wparam, _In_ LPARAM lparam) {
	switch(message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProcW(window, message, wparam, lparam);
}

int main(int argc, char** argv) {
	HINSTANCE instance = GetModuleHandleW(NULL);
	WNDCLASSEXW windowClass = {0};
	windowClass.cbSize = sizeof(WNDCLASSEXW);
	windowClass.lpfnWndProc = procedure;
	windowClass.hInstance = instance;
	windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
	windowClass.lpszClassName = CLASS_NAME;

	if(!RegisterClassExW(&windowClass)) {
		printf("RegisterClassExW() failed: %lu\n", GetLastError());
		return 1;
	}

	HWND window = CreateWindowExW(0, CLASS_NAME, L"DirectX Sample", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, instance, NULL);

	if(!window) {
		printf("CreateWindowExW() failed: %lu\n", GetLastError());
		goto unregisterClass;
	}

	void* data;

	if(!GraphicsInitialize(window, &data)) {
		goto unregisterClass;
	}

	ShowWindow(window, SW_NORMAL);
	MSG message;

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}

	GraphicsUninitialize(data);
unregisterClass:
	UnregisterClassW(CLASS_NAME, instance);
	return 0;
}
