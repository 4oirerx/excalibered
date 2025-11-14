#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main(int argc, TCHAR *argv[])
{
	WNDCLASS wc = {};
	MSG msg     = {};

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = GetModuleHandle(0);
	wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor       = LoadCursor(0, IDI_APPLICATION);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = "D3DWindowClass";
	
	RegisterClass(&wc);

	HWND hWnd = CreateWindow(wc.lpszClassName, "Hello DirectX", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, 800, 800, NULL, NULL, 
				wc.hInstance, NULL);
	if(hWnd == NULL) return 1;
	
	ShowWindow(hWnd, SW_SHOW);

	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

