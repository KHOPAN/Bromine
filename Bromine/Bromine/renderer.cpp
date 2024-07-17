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

void RendererFillRectangle(LONG_PTR handle, COLORREF color, int x, int y, int width, int height) {
	Gdiplus::SolidBrush blackBrush(Gdiplus::Color((color >> 24) & 0xFF, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF));
	((Gdiplus::Graphics*) handle)->FillRectangle(&blackBrush, x, y, width, height);
}
