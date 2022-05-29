#include "GamePadWin32.h"

namespace oinput
{
    GamePad *GamePad::create(int index)
    {
        return new GamePadWin32(index);
    }

    GamePadWin32::GamePadWin32(int index)
    {
    }

    GamePadWin32::~GamePadWin32()
    {
    }

    void GamePadWin32::update()
    {
    }
}
