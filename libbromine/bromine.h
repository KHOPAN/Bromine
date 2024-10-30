#pragma once

#include "bromine_bromine.h"

#define BROMINE_CLASS L"BromineDrawingSurface"

#ifdef __cplusplus
extern "C" {
#endif
BROMINEERROR BromineInitialize();
BROMINEERROR BromineCleanup();
#ifdef __cplusplus
}
#endif
