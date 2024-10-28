#include <Windows.h>
#include "bromine.h"

void BromineInitialize() {
	WNDCLASSEXW windowClass = {0};
	windowClass.cbSize = sizeof(WNDCLASSEXW);
	RegisterClassExW(&windowClass);
}

void BromineCleanup() {

}
