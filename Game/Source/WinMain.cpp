#include "Framework.h"

#include "Game.h"

using namespace fw;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    FWCore* pFramework = new FWCore();
    Game* pGame = new Game();

    pFramework->Init(600, 600);
    pFramework->Run(pGame);
    pFramework->Shutdown();

    delete pFramework;
}