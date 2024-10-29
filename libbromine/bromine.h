#pragma once

#include "bromine_error.h"

#define BROMINE_CLASS L"BromineDrawSurface"

typedef void(CALLBACK* BROMINECREATEFUNCTION) (const LPVOID parameter);

typedef struct {
	BROMINECREATEFUNCTION function;
	LPVOID parameter;
} BROMINECREATEPARAMETER, *PBROMINECREATEPARAMETER;

#ifdef __cplusplus
extern "C" {
#endif
BROMINEERROR BromineInitialize();
BROMINEERROR BromineCleanup();
#ifdef __cplusplus
}
#endif
