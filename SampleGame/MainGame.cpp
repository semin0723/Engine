#include "MainGame.h"
#include "Hierarchy.h"

void MainGame::Initialize(HINSTANCE hInstance, int width, int height)
{
    __super::Initialize(hInstance, width, height);

    // add map
    EntityId map1 = Map1();
    Engine->AddMapEntity(map1);

    //initial
    Engine->Initialize();

    //begin
    Engine->Begin();
}