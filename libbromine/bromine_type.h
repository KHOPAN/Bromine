#pragma once

#include <Windows.h>

typedef struct {
	LONG x;
	LONG y;
	LONG width;
	LONG height;
} BOUNDS, *PBOUNDS;

typedef struct {
	BOOL(CALLBACK* function) (const ROOTBROMINE bromine, const LPVOID parameter);
	LPVOID parameter;
} BROMINECREATEPARAMETER, *PBROMINECREATEPARAMETER;
