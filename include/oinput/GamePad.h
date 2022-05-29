#pragma once

namespace oinput
{
    class GamePad
    {
    public:
        static GamePad *create(int index);

        virtual ~GamePad() {}

        virtual void update() = 0;

    protected:
        GamePad() {};
    };
}
