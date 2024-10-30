#include "bromine_bromine.h"

BROMINEERROR BromineNewBromine(const PBROMINE bromine, const BOOL rootBromine) {
	if(!bromine) {
		return BROMINE_ERROR_INVALID_PARAMETER;
	}

	ROOTBROMINE buffer = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, rootBromine ? sizeof(RAWROOTBROMINE) : sizeof(RAWBROMINE));

	if(!buffer) {
		SetLastError(ERROR_FUNCTION_FAILED);
		return BROMINE_ERROR_WIN32;
	}

	buffer->bromine.rootBromine = rootBromine ? TRUE : FALSE;
	*bromine = (BROMINE) buffer;
	return BROMINE_ERROR_SUCCESS;
}

BROMINEERROR BromineFreeBromine(const BROMINE bromine) {
	if(!bromine) {
		return BROMINE_ERROR_INVALID_PARAMETER;
	}

	return HeapFree(GetProcessHeap(), 0, bromine) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}

BROMINEERROR BromineAddBromine(const ROOTBROMINE bromine, const BROMINE child) {
	if(!bromine) {
		return BROMINE_ERROR_INVALID_PARAMETER;
	}

	return BROMINE_ERROR_SUCCESS;
}
