#include "JoystickWin32.h"

namespace oinput
{
    Joystick *Joystick::create(int index)
    {
        return new JoystickWin32(index);
    }

    JoystickWin32::JoystickWin32(int index)
        : Joystick(index)
    {
    }

    JoystickWin32::~JoystickWin32()
    {
    }

    void JoystickWin32::update()
    {
    }

    bool JoystickWin32::isPressed(int button) const
    {
        return false;
    }

    bool JoystickWin32::isJustPressed(int button) const
    {
        return false;
    }

    bool JoystickWin32::isJustReleased(int button) const
    {
        return false;
    }

    float JoystickWin32::getAxis(int id) const
    {
        return 0.f;
    }

    int JoystickWin32::getAxisCount() const
    {
        return 0;
    }

    int JoystickWin32::getButtonCount() const
    {
        return 0;
    }

    int JoystickWin32::getHatButtonBase() const
    {
        return 0;
    }

    int JoystickWin32::getAxisButtonBase() const
    {
        return 0;
    }
}
