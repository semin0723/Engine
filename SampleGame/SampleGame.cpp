#include "SampleGame.h"

void SampleGame::Initialize(HINSTANCE hInstance, int width, int height)
{
    __super::Initialize(hInstance, width, height);

    //EC::Initialize();
}

void SampleGame::FixedUpdate()
{
    //Engine->FixedUpdate();
}

void SampleGame::Update(float dt)
{
    //Engine->Update(dt);
}

void SampleGame::Render()
{
}

void SampleGame::Finalize()
{
    //EC::Finalize();

    __super::Finalize();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    SampleGame winApp;

    winApp.Initialize(hInstance, 1024, 768);
    winApp.Run();
    winApp.Finalize();

    return EXIT_SUCCESS;
}