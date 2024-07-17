#pragma once

#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

DWORD InitializeRenderSystem(void** token);
void ShutdownRenderSystem(void* token);
LONG_PTR InitializeRenderer(HDC context);
void DestroyRenderer(LONG_PTR handle);

#ifdef __cplusplus
}
#endif
