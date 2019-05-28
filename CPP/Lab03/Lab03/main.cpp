/*  Filename:       main.cpp
    Description:    MET4335 - Lab03
*/

#include <windows.h>        // include all the windows headers
#include <math.h>
#include <stdlib.h>

// *** Task-A ***
// *** Task-A ***

#define WINDOW_CLASS_NAME "wc1"


//  This is the main message handler of the system
LRESULT CALLBACK WndProc( HWND hWnd, 
                          UINT msg, 
                          WPARAM wParam, 
                          LPARAM lParam ) {
    PAINTSTRUCT        ps;          // used in WM_PAINT
    HDC                hDC;  
	// handle to a device context

    // what is the message 
    switch (msg) {
        case WM_CREATE :
            return(0);
            break;
        case WM_PAINT : {
            hDC = BeginPaint(hWnd,&ps);     // simply validate the window

// *** Task-B ***
			HPEN hPenOld;
			HPEN hLinePen;
			COLORREF qLineColor;
			qLineColor = RGB(255, 0, 0);
			hLinePen = CreatePen(PS_SOLID,4, qLineColor);
			hPenOld = (HPEN)SelectObject(hDC,hLinePen);

			MoveToEx(hDC, 100, 150, NULL);
			LineTo(hDC,55, 250);
			MoveToEx(hDC, 55, 250, NULL);
			LineTo(hDC, 160, 250);
			MoveToEx(hDC, 160, 250, NULL);
			LineTo(hDC, 100, 150);
			qLineColor = RGB(0, 255, 0);
			
			SelectObject(hDC, hPenOld);
			DeleteObject(hLinePen);
			hLinePen = CreatePen(PS_SOLID, 4, qLineColor);
			hPenOld = (HPEN)SelectObject(hDC, hLinePen);
			MoveToEx(hDC, 80, 250, NULL);
			LineTo(hDC, 80, 300);
			MoveToEx(hDC, 135, 250, NULL);
			LineTo(hDC, 135, 300);
			HPEN hEllipsePen;
			COLORREF qEllipseColor;
			qEllipseColor = RGB(0, 0, 255);
			hEllipsePen = CreatePen(PS_SOLID, 3, qEllipseColor);
			hPenOld = (HPEN)SelectObject(hDC, hEllipsePen);
			Arc(hDC, 50, 50,150, 150, 0, 0, 0, 0);
			SelectObject(hDC, hPenOld);
			DeleteObject(hEllipsePen);
// *** Task-B ***

            EndPaint(hWnd,&ps);
            return(0);
            break;
        }

        case WM_DESTROY :
            PostQuitMessage(0); // kill the application, this sends a WM_QUIT message
            return(0);
            break;

        case WM_CLOSE : {
            int result = MessageBox( hWnd,
                                     "Are you sure you want to close this application?",
                                     "WM_CLOSE Message Processor",
                                     MB_YESNO | MB_ICONQUESTION );

            if (result==IDYES)
                return( DefWindowProc(hWnd, msg, wParam, lParam));
            else
                return(0);
            break;
        }

        default :
            return(DefWindowProc(hWnd, msg, wParam, lParam));
            break;
    }
} // end WndProc



int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR szCmdLine,
                    int iCmdShow ) {
    WNDCLASSEX  wc;             // this will hold the class we create
    HWND        hWnd;           // generic window handle
    MSG         msg;            // generic message

    // first fill in the window class stucture
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc      = WndProc;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;
    wc.hInstance        = hInstance;
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = WINDOW_CLASS_NAME;
    wc.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);

    // register the window class
    if (!RegisterClassEx(&wc))
        return(0);

    // create the window
    if (!( hWnd =  CreateWindowEx(NULL,                 // extended style
                   WINDOW_CLASS_NAME,                   // class
                   "Windows Graphics Programming II",   // title
                   WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                   0, 0,                                // initial x, y
                   700, 400,                            // initial width, height
                   NULL,                                // handle to parent 
                   NULL,                                // handle to menu
                   hInstance,                           // instance of this application
                   NULL)))                              // extra creation parms
        return(0);

    ShowWindow(hWnd, SW_SHOWDEFAULT);           // display the new window
    UpdateWindow(hWnd);                         // update client area

    // enter main event loop, but this time we use PeekMessage()
    // instead of GetMessage() to retrieve messages
    while (TRUE) {
        // test if there is a message in queue, if so get it
        if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) { 
            if (msg.message == WM_QUIT)         // test if this is a quit
                break;
            TranslateMessage(&msg);             // translate any accelerator keys
            DispatchMessage(&msg);              // send the message to the window proc
        } 

// *** Task-A **
		HDC hDC = GetDC(hWnd);
		SetTextColor(hDC, RGB(0,0,0));
		SetBkColor(hDC, RGB(0, 0, 0));
		SetBkMode(hDC,TRANSPARENT);
		TextOut(hDC,300 ,120 , "Hello!Chong Wang Ho", strlen("Hello!Chong Wang Ho"));
		Sleep(16.7);
		ReleaseDC(hWnd, hDC);
// *** Task-A ***

    } // end while

    return((int)(msg.wParam));                  // return to Windows like this
} // end WinMain
