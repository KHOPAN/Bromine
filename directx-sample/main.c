#include <stdio.h>
#include <Windows.h>

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

	if(!CreateWindowExW(0, CLASS_NAME, L"DirectX Sample", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, instance, NULL)) {
		printf("CreateWindowExW() failed: %lu\n", GetLastError());
		goto unregisterClass;
	}

	MSG message;

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
unregisterClass:
	UnregisterClassW(CLASS_NAME, instance);
	return 0;
}
