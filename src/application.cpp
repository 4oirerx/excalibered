#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(int argc, TCHAR *argv[])
{
	WNDCLASS wc = {};
	MSG msg     = {};

	wc.lpfnWndProc   = WndProc;
	wc.hInstance     = GetModuleHandle(0);
	wc.lpszClassName = "D3DWindowClass";	
	RegisterClass(&wc);

	HWND hWnd = CreateWindow(wc.lpszClassName, "Hello DirectX", WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, 1080, 720, NULL, NULL, 
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

LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC dc = BeginPaint(hWnd, &ps);
			FillRect(dc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
			EndPaint(hWnd, &ps);
		}
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);

}
