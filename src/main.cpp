#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(int argc, TCHAR *argv[])
{
	const TCHAR CLASS_NAME[] = "Sample Window Class";
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.hInstance = GetModuleHandle(0);
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hWnd = CreateWindowEx(
		0, CLASS_NAME,
		"Windows can suck my nards",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 720, 480,
		NULL, NULL,
		wc.hInstance,
		NULL
	);
	
	if(hWnd == NULL)
		return 0;

	ShowWindow(hWnd, SW_SHOWDEFAULT);

	MSG msg = {};
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}	

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
				EndPaint(hWnd, &ps);
			}
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}