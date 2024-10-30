#pragma once

typedef struct _ROOTBROMINE RAWROOTBROMINE, *ROOTBROMINE, **PROOTBROMINE;
typedef struct _BROMINE RAWBROMINE, *BROMINE, **PBROMINE;

#include "bromine_error.h"
#include "bromine_type.h"

#define ROOT_BROMINE_CAPACITY 8

struct _BROMINE {
	BOOL rootBromine;
	BOUNDS bounds;
};

struct _ROOTBROMINE {
	RAWBROMINE bromine;
	PBROMINE child;
	ULONG childCount;
	ULONG childCapacity;
};

#ifdef __cplusplus
extern "C" {
#endif
BROMINEERROR BromineNewBromine(const PBROMINE bromine, const BOOL rootBromine);
BROMINEERROR BromineFreeBromine(const BROMINE bromine);
BROMINEERROR BromineAddBromine(const ROOTBROMINE bromine, const BROMINE child);
#ifdef __cplusplus
}
#endif
