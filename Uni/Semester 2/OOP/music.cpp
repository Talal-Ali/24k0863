#include <windows.h>
#include <commctrl.h>  // For progress bar
#include <mmsystem.h>  // For PlaySound

#pragma comment(lib, "winmm.lib")  // Link WinMM for audio
#pragma comment(lib, "comctl32.lib") // Link Common Controls

// Global Variables
HINSTANCE hInst;
HWND hPlayButton, hProgressBar, hGif;
bool isPlaying = false;
const wchar_t* songPath = L"song.wav"; // Ensure this file is in the same directory

// Function to update the progress bar (simulated)
DWORD WINAPI UpdateProgress(LPVOID lpParam) {
    for (int i = 0; i <= 100; i++) {
        SendMessage(hProgressBar, PBM_SETPOS, i, 0);
        Sleep(100); // Simulating progress
    }
    return 0;
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE: {
            // Load GIF (simulated with BMP)
            hGif = CreateWindowW(L"STATIC", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 
                                50, 10, 200, 100, hWnd, (HMENU)1, hInst, NULL);
            HBITMAP hBmp = (HBITMAP)LoadImageW(NULL, L"animation.bmp", IMAGE_BITMAP, 200, 100, LR_LOADFROMFILE | LR_DEFAULTSIZE);
            SendMessage(hGif, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);

            // Play Button
            hPlayButton = CreateWindowW(L"BUTTON", L"Play", WS_VISIBLE | WS_CHILD,
                                        100, 130, 80, 30, hWnd, (HMENU)2, hInst, NULL);

            // Progress Bar
            InitCommonControls();
            hProgressBar = CreateWindowW(PROGRESS_CLASS, NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH,
                                         50, 180, 200, 20, hWnd, (HMENU)3, hInst, NULL);
            SendMessage(hProgressBar, PBM_SETRANGE, 0, MAKELPARAM(0, 100)); // Set range 0-100
            break;
        }

        case WM_COMMAND: {
            if (LOWORD(wp) == 2) { // Button ID is 2
                if (!isPlaying) {
                    PlaySound(songPath, NULL, SND_FILENAME | SND_ASYNC);
                    isPlaying = true;
                    CreateThread(NULL, 0, UpdateProgress, NULL, 0, NULL); // Start progress bar
                }
            }
            break;
        }

        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

// WinMain Entry Point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    hInst = hInstance;
    
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MusicPlayer";
    wc.lpfnWndProc = WndProc;

    if (!RegisterClassW(&wc)) return -1;

    CreateWindowW(L"MusicPlayer", L"Simple Music Player", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 300, 250, NULL, NULL, hInstance, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}