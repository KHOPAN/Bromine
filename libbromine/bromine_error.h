#pragma once

#include <Windows.h>

typedef enum {
	BROMINE_ERROR_SUCCESS,
	BROMINE_ERROR_UNKNOWN,
	BROMINE_ERROR_FUNCTION_FAILED,
	BROMINE_ERROR_INVALID_PARAMETER,
	BROMINE_ERROR_WIN32,
} BROMINEERROR;

#define BROMINE_SUCCESS(x) (((BROMINEERROR)x)==BROMINE_ERROR_SUCCESS)
#define BROMINE_FAILED(x)  (((BROMINEERROR)x)!=BROMINE_ERROR_SUCCESS)

#ifdef __cplusplus
extern "C" {
#endif
LPCWSTR BromineGetErrorMessage(const BROMINEERROR error);
#ifdef __cplusplus
}
#endif
