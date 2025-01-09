#include "pch.h"
#include "GameEngine.h"
#include "ResourceSystem.h"
#include "ECMain.h"

bool GameEngine::Initialize(HINSTANCE hInstance, int width, int height)
{
    WNDCLASS wcex;

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInstance;
    wcex.hIcon = nullptr;//LoadIcon(_hInstance, MAKEINTRESOURCE(IDI_D2DENGINE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"Template";

    RegisterClass(&wcex);

    RECT winRect = { 0, 0, width, height };
    ::AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, false);

    _hWnd = CreateWindowW(L"Template", L"Template", WS_OVERLAPPED | WS_SYSMENU,
        CW_USEDEFAULT, 0, width, height, nullptr, nullptr, _hInstance, nullptr);

    ShowWindow(_hWnd, SW_SHOWNORMAL);
    UpdateWindow(_hWnd);

    _time.Initialize();
    _d2dRender.Initialize(_hWnd);
    ResourceSystem::GetInstance()->Initialize(_d2dRender.GetRenderTarget());


    // Engine Initialize
    EC::Initialize();

    return true;
}

void GameEngine::Run()
{
    MSG msg;

    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) break;
            else {
                DispatchMessage(&msg);
            }
        }
        else {
            _d2dRender.GetRenderTarget()->BeginDraw();
            _d2dRender.GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::White));

            _time.Update();
            _timer += _time.GetDeltaTime();

            if (_timer >= 0.02f) {
                _timer -= 0.02f;
                Engine->FixedUpdate();
            }
            Engine->Update(_time.GetDeltaTime());
            Engine->Render(_d2dRender.GetRenderTarget());

            _d2dRender.GetRenderTarget()->EndDraw();

            SetWindowText(_hWnd, std::to_wstring(_time.GetFrameRate()).c_str());
        }
    }
}

void GameEngine::Finalize()
{
    Engine->End();
    EC::Finalize();
    ResourceSystem::GetInstance()->DeleteInstance();
    _d2dRender.Finalize();
}

void GameEngine::SetWindowSize(int width, int height)
{
}

LRESULT CALLBACK GameEngine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}