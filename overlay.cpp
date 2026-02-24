#include <windows.h>
#include <string>
#include <chrono>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

int frameCount = 0;
int lastFPS = 0;
auto lastTime = std::chrono::high_resolution_clock::now();

void CalculateFPS() {
    frameCount++;
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - lastTime;
    if (elapsed.count() >= 1.0) {
        lastFPS = frameCount;
        frameCount = 0;
        lastTime = currentTime;
    }
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 1. LIMPIEZA TOTAL: Dibujamos un fondo negro sólido para borrar lo anterior
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        // 2. TEXTO ESTILIZADO
        SetTextColor(hdc, RGB(0, 255, 0)); // Verde neón
        SetBkMode(hdc, TRANSPARENT);
        
        CalculateFPS();
        int dummyPing = 12 + (rand() % 4); // Ping dinámico que cambia levemente
        
        // Espaciado extra para que no se amontone
        std::string texto = "FPS: " + std::to_string(lastFPS) + "   |   PING: " + std::to_string(dummyPing) + "ms";
        
        TextOutA(hdc, 10, 10, texto.c_str(), (int)texto.length());

        EndPaint(hwnd, &ps);
        return 0;
    }
    if (msg == WM_DESTROY) { PostQuitMessage(0); return 0; }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = "OverlayRitmico";
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // Fondo negro para la clase
    RegisterClassA(&wc);

    // Ventana más grande para que no corte el texto
    HWND hwnd = CreateWindowExA(
        WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT,
        "OverlayRitmico", NULL, WS_POPUP,
        30, 30, 350, 60, NULL, NULL, hInst, NULL);

    // TRUCO MAGICO: El color negro (0,0,0) se vuelve invisible
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    
    ShowWindow(hwnd, SW_SHOW);

    MSG msg;
    while (true) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        InvalidateRect(hwnd, NULL, TRUE); // Fuerza el redibujo limpio
        Sleep(5); // Súper rápido para que el contador sea fluido
    }
    return 0;
}