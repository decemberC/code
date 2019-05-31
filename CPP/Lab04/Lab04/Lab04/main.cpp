/*  Filename:       main.cpp
    Description:    Solution - MET4335 - Lab04
*/

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <iostream>
#include <stdlib.h>

#define WINDOW_CLASS_NAME "WINCLASS"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

// GLOBALS
// *** Task-B ***
HANDLE g_hImage;
// *** Task-B ***
FLOAT MX, MY;
RECT rect;
HWND        g_hWnd = NULL;                  // global main window handler


// *** Task-A ***
void ShowMouseCoord(HDC hdc,int x,int y) {
	char outStr[100] = "";
	SetTextColor(hdc, RGB(255, 0, 0));
	sprintf(outStr, "Mouse at(x:%d,Y:%d)", x, y);
	TextOut(hdc, x, y, outStr, strlen(outStr));
}
// *** Task-A ***


// *** Task-B ***
void Game_Main() {
	HDC hDC = GetDC(g_hWnd);
	HDC hImageDC = CreateCompatibleDC(hDC);
	BITMAP Bitmap;
	GetObject(g_hImage, sizeof(BITMAP), &Bitmap);
	int w = Bitmap.bmWidth;
	int h = Bitmap.bmHeight;
	SelectObject(hImageDC, g_hImage);
	BitBlt(hDC, MX-w/2, MY-h/2, w, h, hImageDC, 0, 0, SRCCOPY);
	DeleteDC(hImageDC);
	ReleaseDC(g_hWnd, hDC);
}
void Game_Shutdown() {
	DeleteObject(g_hWnd);
}
// *** Task-B ***


/*  This is the main message handler of the system.
*/
LRESULT CALLBACK WndProc( HWND hWnd, 
                          UINT msg, 
                          WPARAM wParam, 
                          LPARAM lParam ) {
    PAINTSTRUCT     ps;             // used in WM_PAINT
    HDC             hDC;            // handle to a device context

    switch (msg) {
        case WM_CREATE :
			hDC = GetDC(hWnd);
			GetWindowRect(hWnd,&rect);

			g_hImage = LoadImage(NULL, "images/picture1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			FillRect(hDC, &rect, (HBRUSH)CreateSolidBrush(RGB(0, 0, 0)));// do initialization stuff here
            return(0);
            break;
        case WM_PAINT :             // simply validate the window
            hDC = BeginPaint(hWnd, &ps);     
            EndPaint(hWnd, &ps);
            return(0);
            break;
        case WM_DESTROY :           // send a WM_QUIT message
            PostQuitMessage(0);
			
            return(0);
            break;

// *** Task-A ***
		case WM_MOUSEMOVE:
			hDC = GetDC(hWnd);
			FillRect(hDC, &rect, (HBRUSH)CreateSolidBrush(RGB(0, 0, 0)));
			Game_Main();
			ShowMouseCoord(hDC, LOWORD(lParam), HIWORD(lParam));
			
			MX = LOWORD(lParam);
			MY = HIWORD(lParam);
		
			ReleaseDC(hWnd, hDC);
			return(0);
			break;
// *** Task-A ***

// *** Task-C ***
		case WM_KEYDOWN: {
			int virtual_code = (int) wParam;
			int key_state = (int) lParam;
			switch (virtual_code) {
			case VK_RETURN:
				g_hImage = LoadImage(NULL, "images/picture2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				Game_Main();
				break;
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			case 'C': {
				hDC = GetDC(hWnd);
				FillRect(hDC, &rect, (HBRUSH)CreateSolidBrush(RGB(0, 0, 0)));
				ReleaseDC(g_hWnd, hDC);
				break;
			}
			default:
				break;
			}
			return(0);
			break;
		}

// *** Task-C ***

        default :
            return(DefWindowProc(hWnd, msg, wParam, lParam));
            break;
     }
} // end WndProc


/*  This is the main program.
*/
int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR szCmdLine,
                    int iCmdShow ) {
    WNDCLASSEX      wc;                 // window class
    MSG             msg;                // generic message

    // setup window class values
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc      = WndProc;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;
    wc.hInstance        = hInstance;
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW); 
    wc.hbrBackground    = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = WINDOW_CLASS_NAME;
    wc.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))          // register the window class
        return(0);

    // create the window
    if (!(g_hWnd =  CreateWindowEx(NULL,                // extended style
                    WINDOW_CLASS_NAME,                  // class
                    "Windows Graphics Progamming III",  // title
                    WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                    0, 0,                               // initial x,y
                    WINDOW_WIDTH,                       // initial width
                    WINDOW_HEIGHT,                      // initial height
                    NULL,                               // handle to parent 
                    NULL,                               // handle to menu
                    hInstance,                          // instance of this application
                    NULL)))                             // extra creation parms
        return(0);

    ShowWindow(g_hWnd, SW_SHOWDEFAULT);     // display the new window
    UpdateWindow(g_hWnd);                   // update client area

// *** Task-B ***
	
// *** Task-B ***

    // enter main event loop
    while (TRUE) {
         // cheak message queue
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)     // test a quit
                break;
            TranslateMessage(&msg);         // translate keys
            DispatchMessage(&msg);          // send message to the WndProc()
        }
		
        Sleep(1000/30);
		// lock time to 30fps
    } // end while

// *** Task-B ***
	Game_Shutdown();
// *** Task-B ***

    return(msg.wParam);                     // return to Windows
} // end WinMain
