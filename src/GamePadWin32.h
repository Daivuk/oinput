#pragma once

#include "oinput/GamePad.h"

namespace oinput
{
    class GamePadWin32 final : public GamePad
    {
    public:
        GamePadWin32(int index);
        ~GamePadWin32();

        virtual void update() override;
    };
}
