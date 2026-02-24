#include <windows.h>

void SetSupernovaePriority() {
    DWORD processId;
    HWND windowHandle = FindWindowA("osu!", NULL);
    if (windowHandle) {
        GetWindowThreadProcessId(windowHandle, &processId);
        HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
        if (processHandle) {
            SetPriorityClass(processHandle, HIGH_PRIORITY_CLASS);
            CloseHandle(processHandle);
        }
    }
}

void CleanSystemMemory() {
    SetProcessWorkingSetSize(GetCurrentProcess(), (SIZE_T)-1, (SIZE_T)-1);
}

// WinMain elimina la necesidad de una terminal negra
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
    CleanSystemMemory();
    SetSupernovaePriority();
    return 0;
}