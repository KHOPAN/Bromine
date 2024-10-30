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

	if(rootBromine) {
		buffer->child = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(BROMINE) * ROOT_BROMINE_CAPACITY);

		if(!buffer->child) {
			HeapFree(GetProcessHeap(), 0, buffer);
			SetLastError(ERROR_FUNCTION_FAILED);
			return BROMINE_ERROR_WIN32;
		}

		buffer->childCapacity = ROOT_BROMINE_CAPACITY;
	}

	*bromine = (BROMINE) buffer;
	return BROMINE_ERROR_SUCCESS;
}

BROMINEERROR BromineFreeBromine(const BROMINE bromine) {
	if(!bromine) {
		return BROMINE_ERROR_INVALID_PARAMETER;
	}

	if(bromine->rootBromine && !HeapFree(GetProcessHeap(), 0, ((ROOTBROMINE) bromine)->child)) {
		return BROMINE_ERROR_WIN32;
	}

	return HeapFree(GetProcessHeap(), 0, bromine) ? BROMINE_ERROR_SUCCESS : BROMINE_ERROR_WIN32;
}

BROMINEERROR BromineAddBromine(const ROOTBROMINE bromine, const BROMINE child) {
	if(!bromine || !child) {
		return BROMINE_ERROR_INVALID_PARAMETER;
	}

	if(bromine->childCount >= bromine->childCapacity) {
		ULONG capacity = bromine->childCapacity * 2;
		PBROMINE buffer = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(BROMINE) * capacity);

		if(!buffer) {
			SetLastError(ERROR_FUNCTION_FAILED);
			return BROMINE_ERROR_WIN32;
		}

		for(size_t i = 0; i < bromine->childCapacity; i++) {
			buffer[i] = bromine->child[i];
		}

		HeapFree(GetProcessHeap(), 0, bromine->child);
		bromine->child = buffer;
		bromine->childCapacity = capacity;
	}

	bromine->child[bromine->childCount] = child;
	bromine->childCount++;
	return BROMINE_ERROR_SUCCESS;
}
