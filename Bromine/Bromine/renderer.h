#pragma once

#include <Windows.h>

#ifdef __cplusplus
extern "C" {
#endif

DWORD InitializeRenderSystem(void** token);
void ShutdownRenderSystem(void* token);
LONG_PTR InitializeRenderer(HDC context);
void DestroyRenderer(LONG_PTR handle);
void RendererFillRectangle(LONG_PTR handle, COLORREF color, int x, int y, int width, int height);

#ifdef __cplusplus
}
#endif
