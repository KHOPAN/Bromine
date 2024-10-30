#include <stdio.h>
#include <bromine.h>

#define PRINT_ERROR printf("Bromine Error: %ws\n", BromineGetErrorMessage(error))

static void CALLBACK bromineInitialize(const ROOTBROMINE bromine, const LPVOID parameter) {
	printf("Initialize: %p\n", bromine);
}

int main(int argc, char** argv) {
	BROMINEERROR error = BromineInitialize();

	if(BROMINE_FAILED(error)) {
		PRINT_ERROR;
		return 1;
	}

	BROMINECREATEPARAMETER parameter = {0};
	parameter.function = bromineInitialize;
	HWND window = CreateWindowExW(0, BROMINE_CLASS, L"Bromine", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 400, 400, NULL, NULL, NULL, &parameter);
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
