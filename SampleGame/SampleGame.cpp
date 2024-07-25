#include "SampleGame.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    MainGame winApp;

    winApp.Initialize(hInstance, 1024, 768);
    winApp.Run();
    winApp.Finalize();

    return EXIT_SUCCESS;
}