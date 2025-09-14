#include <windows.h>
#include <mmsystem.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;
HWND playButton, stopButton;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"MusicPlayer";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    CreateWindowW(L"MusicPlayer", L"Simple Music Player", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 300, 200, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            playButton = CreateWindow("BUTTON", "Play", WS_VISIBLE | WS_CHILD,
                                      50, 50, 80, 30, hWnd, (HMENU)1, NULL, NULL);
            stopButton = CreateWindow("BUTTON", "Stop", WS_VISIBLE | WS_CHILD,
                                      150, 50, 80, 30, hWnd, (HMENU)2, NULL, NULL);
            break;
        case WM_COMMAND:
            if (LOWORD(wp) == 1) {
                PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC);
            } else if (LOWORD(wp) == 2) {
                PlaySound(NULL, NULL, 0); // Stop music
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}
