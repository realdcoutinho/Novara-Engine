#pragma once
#include "EnginePCH.h"

class NovaraGame
{
public:
    NovaraGame() = default;
    virtual ~NovaraGame() = default;

    int Run(HINSTANCE hInstance);
};
