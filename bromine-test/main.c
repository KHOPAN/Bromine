#include <stdio.h>
#include <bromine.h>

#define PRINT_ERROR printf("Bromine Error: %ws\n", BromineGetErrorMessage(error))

static void CALLBACK customRenderer(const BROMINE bromine, const HDC context, const PRECT bounds) {
	SetDCBrushColor(context, 0x0000FF);
	HBRUSH brush = GetStockObject(DC_BRUSH);
	FillRect(context, bounds, brush);
}

static BOOL CALLBACK bromineInitialize(const ROOTBROMINE bromine, const LPVOID parameter) {
	printf("Initialize: %p\n", bromine);
	BROMINE panel;
	BROMINEERROR error = BromineNewBromine(&panel, FALSE);

	if(BROMINE_FAILED(error)) {
		return FALSE;
	}

	panel->renderer = customRenderer;
	panel->bounds.x = 200;
	panel->bounds.y = 200;
	panel->bounds.width = 200;
	panel->bounds.height = 200;
	error = BromineAddBromine(bromine, panel);

	if(BROMINE_FAILED(error)) {
		BromineFreeBromine(panel);
		return FALSE;
	}

	return TRUE;
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
