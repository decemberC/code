#include <windows.h>

#define WINDOW_CLASS_NAME "WINCLASS1"

LRESULT CALLBACK Wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam) {
	PAINTSTRUCT ps;
	HDC hDC;
	switch (msg)
	{
	case WM_CREATE:
		return(0);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return(0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return(0);
		break;
	default:
		return(DefWindowProc(hwnd, msg, wParam, IParam));
		break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR szCmdLine,int ICmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = Wndproc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);
	wc.hCursor = LoadCursor(NULL, IDI_EXCLAMATION);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = LoadIcon(NULL, IDI_EXCLAMATION);
	if (!RegisterClassEx(&wc)) {
		return(0);
	}
	if (!(hwnd = CreateWindowEx(NULL, WINDOW_CLASS_NAME, "Advance C++ and Graphics Programming(Chong Wang Ho)", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 600, 500, NULL, NULL, hInstance, NULL))) {
		return(0);
	}
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	while (TRUE) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} 
	}
	return((int)msg.wParam);
}