#include <stdio.h>
#include "graphics.h"

#define RANDOM_COLOR_FLOAT (((float)(rand()%255))/255.0f)

typedef struct {
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* target;
	ID2D1SolidColorBrush* brush;
} GRAPHICSDATA, *PGRAPHICSDATA;

BOOL GraphicsInitialize(const HWND window, const void** data) {
	if(!data) {
		return FALSE;
	}

	PGRAPHICSDATA graphics = static_cast<PGRAPHICSDATA>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(GRAPHICSDATA)));

	if(!graphics) {
		printf("HeapAlloc() failed\n");
		return FALSE;
	}

	if(FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &graphics->factory))) {
		printf("D2D1CreateFactory() failed\n");
		goto freeGraphics;
	}

	RECT bounds;
	GetClientRect(window, &bounds);

	if(FAILED(graphics->factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(window, D2D1::SizeU(bounds.right - bounds.left, bounds.bottom - bounds.top)), &graphics->target))) {
		printf("ID2D1Factory::CreateHwndRenderTarget() failed\n");
		goto releaseFactory;
	}

	if(FAILED(graphics->target->CreateSolidColorBrush(D2D1::ColorF(0x000000), &graphics->brush))) {
		printf("ID2D1HwndRenderTarget::CreateSolidColorBrush() failed\n");
		graphics->target->Release();
		goto releaseFactory;
	}

	*data = graphics;
	return TRUE;
releaseFactory:
	graphics->factory->Release();
freeGraphics:
	HeapFree(GetProcessHeap(), 0, graphics);
	return FALSE;
}

void GraphicsRender(void* data) {
	PGRAPHICSDATA graphics = reinterpret_cast<PGRAPHICSDATA>(data);

	if(!graphics) {
		return;
	}

	graphics->target->BeginDraw();
	graphics->brush->SetColor(D2D1::ColorF(RANDOM_COLOR_FLOAT, RANDOM_COLOR_FLOAT, RANDOM_COLOR_FLOAT));
	graphics->target->FillEllipse(D2D1::Ellipse(D2D1::Point2F(200.0f, 200.0f), 50.0f, 50.0f), graphics->brush);

	if(FAILED(graphics->target->EndDraw())) {
		printf("ID2D1HwndRenderTarget::EndDraw() failed\n");
	}
}

void GraphicsUninitialize(void* data) {
	PGRAPHICSDATA graphics = reinterpret_cast<PGRAPHICSDATA>(data);

	if(!graphics) {
		return;
	}

	graphics->target->Release();
	graphics->factory->Release();
	HeapFree(GetProcessHeap(), 0, graphics);
}
