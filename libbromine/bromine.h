#pragma once

#include <Windows.h>
#include "bromine_error.h"

#define BROMINE_CLASS L"BromineClass"

#ifdef __cplusplus
extern "C" {
#endif

DWORD BromineInitialize();
DWORD BromineCleanup();

#ifdef __cplusplus
}
#endif
