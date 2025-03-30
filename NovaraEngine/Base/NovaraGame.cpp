
#include "NovaraGame.h"

// Simple Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int NovaraGame::Run(HINSTANCE hInstance)
{
    const wchar_t CLASS_NAME[] = L"MainGameWindowClass";

    // Describe and register the window class
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    RegisterClassW(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,                          // Optional window styles
        CLASS_NAME,                 // Window class
        L"T",          // Window text
        WS_OVERLAPPEDWINDOW,        // Window style

        // Position and size
        CW_USEDEFAULT, CW_USEDEFAULT, 1200, 600, // <--- Wider window

        nullptr,       // Parent window    
        nullptr,       // Menu
        hInstance,     // Instance handle
        nullptr        // Additional application data
    );

    if (!hwnd)
    {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);

    // Run the message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}
