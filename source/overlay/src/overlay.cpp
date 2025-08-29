#include "overlay.h"

LRESULT CALLBACK OverlayWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(255, 0, 0));
        TextOutA(hdc, 50, 50, "Test", 15);
        EndPaint(hwnd, &ps);
        return 0;
    }
    return DefWindowProcA(hwnd, msg, wParam, lParam);
}

DWORD WINAPI OverlayThread(LPVOID) {
    WNDCLASSA wc = { 0 };
    wc.lpfnWndProc = OverlayWndProc;
    wc.hInstance = GetModuleHandleA(NULL);
    wc.lpszClassName = "OverlayWindowClass";
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(
        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST,
        "OverlayWindowClass", NULL, WS_POPUP,
        0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
        NULL, NULL, wc.hInstance, NULL);

    SetLayeredWindowAttributes(hwnd, RGB(0,0,0), 0, LWA_COLORKEY);
    ShowWindow(hwnd, SW_SHOW);

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    return 0;
}

void StartOverlay() {
    CreateThread(NULL, 0, OverlayThread, NULL, 0, NULL);
}