#pragma once

#include "oinput/Joystick.h"

namespace oinput
{
    class JoystickWin32 final : public Joystick
    {
    public:
        JoystickWin32(int index);
        ~JoystickWin32();

        void update() override;

        bool isPressed(int button) const override;
        bool isJustPressed(int button) const override;
        bool isJustReleased(int button) const override;
        float getAxis(int id) const override;
        int getAxisCount() const override;
        int getButtonCount() const override;
        int getHatButtonBase() const override;
        int getAxisButtonBase() const override;
    };
}
