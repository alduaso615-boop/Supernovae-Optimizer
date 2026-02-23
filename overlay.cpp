#include <windows.h>
#include <iostream>
#include <string>

// --- ESTO ES LO QUE TE FALTABA (La "L" dentro del código) ---
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "dwmapi.lib")

// Función para simular FPS (aquí luego pondremos el contador real)
int GetFPS() { return 144; } 

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Color Verde Neón y fondo transparente
            SetTextColor(hdc, RGB(0, 255, 0));
            SetBkMode(hdc, TRANSPARENT);

            std::string texto = "FPS: " + std::to_string(GetFPS()) + " | PING: 15ms";
            TextOutA(hdc, 5, 5, texto.c_str(), (int)texto.length());

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY: PostQuitMessage(0); break;
        default: return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int main() {
    // 1. OCULTAR LA CONSOLA (Para que no se vea nada negro)
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // 2. REGISTRAR LA VENTANA INVISIBLE
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "OverlayRitmico";
    RegisterClass(&wc);

    // 3. CREAR VENTANA (Transparente y siempre encima de los juegos)
    HWND hwnd = CreateWindowEx(
        WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,
        "OverlayRitmico", NULL, WS_POPUP,
        10, 10, 300, 50, // Posición y tamaño en pantalla
        NULL, NULL, wc.hInstance, NULL
    );

    // 4. HACER QUE EL FONDO SEA INVISIBLE
    SetLayeredWindowAttributes(hwnd, 0, 255, LWA_COLORKEY);
    ShowWindow(hwnd, SW_SHOW);

    // 5. BUCLE DE ACTUALIZACIÓN
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        DispatchMessage(&msg);
        InvalidateRect(hwnd, NULL, TRUE); // Refresca el texto
        Sleep(100); // No gasta CPU
    }
    return 0;
}