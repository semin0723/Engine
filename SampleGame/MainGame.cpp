#include "MainGame.h"
#include "Hierarchy.h"

bool MainGame::Initialize(HINSTANCE hInstance, int width, int height)
{
    __super::Initialize(hInstance, width, height);

    //initial
    bool res = Engine->Initialize();
    if (res == false) {
        return false;
    }
    // add map
    EntityId map1 = Map1();
    Engine->AddMapEntity(map1);

    EntityId ui1 = UItestGroup();
    Engine->AddUIEntity(ui1);

    Engine->InitializeObject();

    //begin
    Engine->Begin();

    return true;
}