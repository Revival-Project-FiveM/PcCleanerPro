#include "Main.h"
//#include "functions.h"

#define LOADER_BRAND "PC Cleaner Pro"
#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 350


// Main code
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, LOADER_BRAND, NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, LOADER_BRAND, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);

    // Setup Dear ImGui context
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; //crutial for not leaving the imgui.ini file
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - WINDOW_WIDTH) / 2.f;
    auto y = float(screen_rect.bottom - WINDOW_HEIGHT) / 2.f;

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT));
            ImGui::SetNextWindowBgAlpha(1.0f);

            ImGui::Begin(LOADER_BRAND, &loader_active, window_flags);
            {
                static int switchTabs = 3;
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

                if (ImGui::Button("Basic", ImVec2(100, 45)))
                    switchTabs = 0;
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 15);

                if (ImGui::Button("Advenced", ImVec2(100, 45)))
                    switchTabs = 1;
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 15);

                if (ImGui::Button("Info", ImVec2(100, 45)))
                    switchTabs = 2;
                switch (switchTabs) {
                case 0:
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 175);
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 125);
                    ImGui::Columns(1);
                    ImGui::NextColumn();
                    if (ImGui::Button("Fast Clean", ImVec2(100, 50))) {
                        // code for clean from functions.h i too lazy to do this XD
                    }
                    break;
                case 1:
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 175);
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 117);
                    ImGui::Columns(1);
                    ImGui::NextColumn();

                    if (ImGui::Button("Clear Win Temp", ImVec2(115, 50))) {

                    }
                    ImGui::SameLine(0, 10);
                    if (ImGui::Button("Clear App Temp", ImVec2(115, 50))) {

                    }
                    ImGui::SameLine(0, 10);

                    if (ImGui::Button("Clear Prefetch", ImVec2(115, 50))) {

                    }
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 117);
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 7);


                    if (ImGui::Button("Clear Cookies", ImVec2(115, 50))) {

                    }
                    ImGui::SameLine(0, 10);
                    if (ImGui::Button("Clear Win History", ImVec2(115, 50))) {

                    }
                    ImGui::SameLine(0, 10);
                    if (ImGui::Button("Clear Brave Temp", ImVec2(115, 50))) {

                    }

                        break;

                case 2:
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 175);
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 115);
                    ImGui::Text("Program Developed by P0LI3H");
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 115);
                    ImGui::Text("IDK what is this but i make it for fun XD");
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 115);
                    ImGui::Text("TODO :");
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 115);
                    ImGui::Text("- add functions from functions.h for buttons");
                        break;

                case 3:
                    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 125);
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 185);
                    ImGui::Text("Please select the tab first");
                    break;

                }
            }
            ImGui::End();
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!loader_active) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}