#pragma once
#include "MainGame.h"

#include <Windows.h>

int wmain(int argc, wchar_t* argv[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);

#pragma warning(push)
#pragma warning(disable: 6387)
    wWinMain(GetModuleHandle(nullptr), nullptr, nullptr, SW_SHOW);
#pragma warning(pop)

    return 0;
}

#pragma warning(push)
#pragma warning(disable: 28251 6387)
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR /*pCmdLine*/, int /*nCmdShow*/)
{
    const auto pGame = new MainGame();
    auto result = pGame->Run(hInstance);
    UNREFERENCED_PARAMETER(result);
    delete pGame;

    return 0;
}
#pragma warning(pop)