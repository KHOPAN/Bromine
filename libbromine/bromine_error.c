#include "bromine_error.h"

LPCWSTR BromineGetErrorMessage(const BROMINEERROR error) {
	switch(error) {
	case BROMINE_ERROR_SUCCESS:
		return L"An operation completed successfully";
	case BROMINE_ERROR_FUNCTION_FAILED:
		return L"Function cannot be completed";
	case BROMINE_ERROR_WIN32:
		return L"Win32 error occurred";
	}

	return L"Unknown or undefined error occurred";
}
