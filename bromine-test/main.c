#include <stdio.h>
#include <bromine.h>

#define PRINT_ERROR printf("Bromine Error: %ws\n", BromineGetErrorMessage(error))

int main(int argc, char** argv) {
	BROMINEERROR error = BromineInitialize();

	if(BROMINE_FAILED(error)) {
		PRINT_ERROR;
		return 1;
	}

	int codeExit = 1;
	codeExit = 0;
cleanup:
	error = BromineCleanup();

	if(BROMINE_FAILED(error)) {
		PRINT_ERROR;
		codeExit = 1;
	}

	return codeExit;
}
