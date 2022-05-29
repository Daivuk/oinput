#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <Windows.h>
#include "oinput/Input.h"
#include <unordered_map>

namespace oinput
{
    class InputWin32 final : public Input
    {
    public:
        InputWin32(HWND handle);
        ~InputWin32();

        void setMouseVisibleInternal(bool isCursorVisible) override;
        void setMouseIconInternal(const uint8_t *pDataRGBA, int width, int height, int hotSpotX, int hotSpotY) override;
        void unsetMouseIconInternal() override;
        void setMousePosInternal(int x, int y) override;
        void updateInternal() override;

        HCURSOR getCursor() const;
        void setCursor(HCURSOR cursor);

        void readKeyboard() override;
        void readMouse() override;

    private:
        IDirectInput8* directInput = nullptr;
        IDirectInputDevice8* keyboard = nullptr;
        IDirectInputDevice8* mouse = nullptr;

        unsigned char keyboardState[256];
        unsigned char previousKeyboardState[256];

        DIMOUSESTATE mouseState;
        DIMOUSESTATE previousMouseState;

        HWND m_windowHandle = nullptr;

        HCURSOR m_cursor;
        std::unordered_map<const uint8_t *, HCURSOR> m_cursors;
    };
};
