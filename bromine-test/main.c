#include <stdio.h>
#include <bromine.h>

#define PRINT_ERROR printf("Bromine Error: %ws\n", BromineGetErrorMessage(error))

int main(int argc, char** argv) {
	BROMINEERROR error = BromineInitialize();

	if(BROMINE_FAILED(error)) {
		PRINT_ERROR;
		return 1;
	}

	HWND window = CreateWindowExW(0, BROMINE_CLASS, L"Bromine", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 400, 400, NULL, NULL, NULL, NULL);
	int codeExit = 1;

	if(!window) {
		printf("CreateWindowExW() failed: %lu\n", GetLastError());
		goto cleanup;
	}

	MSG message;

	while(GetMessageW(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}

	codeExit = 0;
cleanup:
	error = BromineCleanup();

	if(BROMINE_FAILED(error)) {
		PRINT_ERROR;
		codeExit = 1;
	}

	return codeExit;
}
