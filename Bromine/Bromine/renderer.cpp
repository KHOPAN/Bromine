#include "renderer.h"
#include <gdiplus.h>

DWORD InitializeRenderSystem(void** token) {
	Gdiplus::GdiplusStartupInput input;
	return Gdiplus::GdiplusStartup(reinterpret_cast<ULONG_PTR*>(token), &input, NULL);
}

void ShutdownRenderSystem(void* token) {
	Gdiplus::GdiplusShutdown(reinterpret_cast<ULONG_PTR>(token));
}

LONG_PTR InitializeRenderer(HDC context) {
	return reinterpret_cast<LONG_PTR>(new Gdiplus::Graphics(context));
}

void DestroyRenderer(LONG_PTR handle) {
	delete ((Gdiplus::Graphics*) handle);
}
