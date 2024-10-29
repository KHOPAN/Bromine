#pragma once

#include "bromine_error.h"

#define BROMINE_CLASS L"BromineClass"

#ifdef __cplusplus
extern "C" {
#endif
BROMINEERROR BromineInitialize();
BROMINEERROR BromineCleanup();
#ifdef __cplusplus
}
#endif
