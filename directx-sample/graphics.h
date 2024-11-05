#pragma once

#include <Windows.h>
#include <d2d1.h>

#ifdef __cplusplus
extern "C" {
#endif
BOOL GraphicsInitialize(const HWND window, const void** data);
void GraphicsRender(void* data);
void GraphicsUninitialize(void* data);
#ifdef __cplusplus
}
#endif
