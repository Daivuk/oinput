#pragma once

#include <string>

namespace oinput
{
    class Joystick
    {
    public:
        enum class Type
        {
            Stick = 0,
            Throttle = 1,
            Other = 2
        };

        static Joystick *create(int index);

        virtual ~Joystick();

        virtual void update() = 0;
        virtual bool isPressed(int button) const = 0;
        virtual bool isJustPressed(int button) const = 0;
        virtual bool isJustReleased(int button) const = 0;
        virtual float getAxis(int id) const = 0;
        virtual int getAxisCount() const = 0;
        virtual int getButtonCount() const = 0;
        virtual int getHatButtonBase() const = 0;
        virtual int getAxisButtonBase() const = 0;

        Type getType() const;
        int getIndex() const;
        const std::string& getName() const;
        std::string getTypeName() const;
        virtual std::string getAxisName(int id) const;
        virtual std::string getButtonName(int button) const;

    protected:
        Joystick(int index);

        int m_index = 0;
        Type m_type = Type::Other;
        std::string m_name;
    };
}
