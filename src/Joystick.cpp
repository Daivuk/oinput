#include "oinput/Joystick.h"

namespace oinput
{
    Joystick::Joystick(int index)
        : m_index(index)
        , m_name("Joystick")
    {
    }

    Joystick::~Joystick()
    {
    }

    Joystick::Type Joystick::getType() const
    {
        return m_type;
    }

    int Joystick::getIndex() const
    {
        return m_index;
    }

    const std::string& Joystick::getName() const
    {
        return m_name;
    }

    std::string Joystick::getTypeName() const
    {
        switch (m_type)
        {
            case Type::Stick:
                return "Stick";
            case Type::Throttle:
                return "Throttle";
            case Type::Other:
                return "Other";
        }
        return "Unknown";
    }

    std::string Joystick::getAxisName(int id) const
    {
        return "axis" + std::to_string(id);
    }

    std::string Joystick::getButtonName(int button) const
    {
        auto hatBase = getHatButtonBase();
        auto axisBase = getAxisButtonBase();
        if (button < hatBase)
        {
            return "btn" + std::to_string(button);
        }
        else if (button < axisBase)
        {
            auto hatId = (button - hatBase) / 4;
            auto hatDir = (button - hatBase) % 4;
            switch (hatDir)
            {
                case 0: return "hat" + std::to_string(hatId) + "_up";
                case 1: return "hat" + std::to_string(hatId) + "_right";
                case 2: return "hat" + std::to_string(hatId) + "_down";
                case 3: return "hat" + std::to_string(hatId) + "_left";
            }
            return "wat";
        }
        else
        {
            auto base = button - axisBase;
            return (base % 2 == 0 ? "-axis" : "+axis") + std::to_string(base / 2);
        }
    }
}
