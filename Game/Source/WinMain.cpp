#include "Framework.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    fw::FWCore* pFramework = new fw::FWCore();

    pFramework->Init(600, 600);
    pFramework->Run();
    pFramework->Shutdown();

    delete pFramework;
}