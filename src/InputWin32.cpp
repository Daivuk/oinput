#include "InputWin32.h"
#include "Utils.h"
#include <cassert>

#if defined(WIN32)
// Reference: https://www.codeproject.com/articles/5220/creating-a-color-cursor-from-a-bitmap
static void GetMaskBitmaps(HBITMAP hSourceBitmap,
                           COLORREF clrTransparent,
                           HBITMAP &hAndMaskBitmap,
                           HBITMAP &hXorMaskBitmap)
{
    HDC hDC = ::GetDC(NULL);
    HDC hMainDC = ::CreateCompatibleDC(hDC);
    HDC hAndMaskDC = ::CreateCompatibleDC(hDC);
    HDC hXorMaskDC = ::CreateCompatibleDC(hDC);

    //Get the dimensions of the source bitmap
    BITMAP bm;
    ::GetObject(hSourceBitmap, sizeof(BITMAP), &bm);

    hAndMaskBitmap = ::CreateCompatibleBitmap(hDC, bm.bmWidth, bm.bmHeight);
    hXorMaskBitmap = ::CreateCompatibleBitmap(hDC, bm.bmWidth, bm.bmHeight);

    //Select the bitmaps to DC
    HBITMAP hOldMainBitmap = (HBITMAP)::SelectObject(hMainDC, hSourceBitmap);
    HBITMAP hOldAndMaskBitmap = (HBITMAP)::SelectObject(hAndMaskDC,
                                                        hAndMaskBitmap);
    HBITMAP hOldXorMaskBitmap = (HBITMAP)::SelectObject(hXorMaskDC,
                                                        hXorMaskBitmap);

    //Scan each pixel of the souce bitmap and create the masks
    COLORREF MainBitPixel;
    for (int x = 0; x<bm.bmWidth; ++x)
    {
        for (int y = 0; y<bm.bmHeight; ++y)
        {
            MainBitPixel = ::GetPixel(hMainDC, x, y);
            if (MainBitPixel == clrTransparent)
            {
                ::SetPixel(hAndMaskDC, x, y, RGB(255, 255, 255));
                ::SetPixel(hXorMaskDC, x, y, RGB(0, 0, 0));
            }
            else
            {
                ::SetPixel(hAndMaskDC, x, y, RGB(0, 0, 0));
                ::SetPixel(hXorMaskDC, x, y, MainBitPixel);
            }
        }
    }

    ::SelectObject(hMainDC, hOldMainBitmap);
    ::SelectObject(hAndMaskDC, hOldAndMaskBitmap);
    ::SelectObject(hXorMaskDC, hOldXorMaskBitmap);

    ::DeleteDC(hXorMaskDC);
    ::DeleteDC(hAndMaskDC);
    ::DeleteDC(hMainDC);

    ::ReleaseDC(NULL, hDC);
}

static HBITMAP createHBitmapFromData(const uint8_t* pngData, int w, int h)
{
    HDC hDC = ::GetDC(NULL);
    HDC bDC = ::CreateCompatibleDC(hDC);
    HBITMAP b = ::CreateCompatibleBitmap(hDC, w, h);
    HBITMAP oldB = (HBITMAP)::SelectObject(bDC, b);

    auto len = w * h;
    std::vector<uint8_t> bitmapData(len * 3, 0);
    for (auto i = 0; i < len; ++i)
    {
        if (pngData[i * 4 + 3] < 128)
        {
            ::SetPixel(bDC, i % w, i / w, RGB(255, 0, 255));
        }
        else
        {
            ::SetPixel(bDC, i % w, i / w, RGB(pngData[i * 4 + 0], pngData[i * 4 + 1], pngData[i * 4 + 2]));
        }
    }

    ::SelectObject(bDC, oldB);
    ::DeleteDC(bDC);
    ::ReleaseDC(NULL, hDC);

    return b;
}

static HCURSOR pngToCursor(const uint8_t *pDataRGBA, int width, int height, int centerX, int centerY)
{
    auto b = createHBitmapFromData(pDataRGBA, width, height);
    HBITMAP hAndMask = NULL, hXorMask = NULL;
    GetMaskBitmaps(b, RGB(255, 0, 255), hAndMask, hXorMask);

    ICONINFO iconinfo = {0};
    iconinfo.fIcon = FALSE;
    iconinfo.xHotspot = centerX;
    iconinfo.yHotspot = centerY;
    iconinfo.hbmMask = hAndMask;
    iconinfo.hbmColor = hXorMask;

    HCURSOR hCursor = ::CreateIconIndirect(&iconinfo);

    DeleteObject(hAndMask);
    DeleteObject(hXorMask);
    DeleteObject(b);

    return hCursor;
}
#endif

namespace oinput
{
    Input *Input::create(void *window)
    {
        return new InputWin32((HWND)window);
    }

    InputWin32::InputWin32(HWND windowHandle)
        : m_windowHandle(windowHandle)
    {
        unsetMouseIcon();
        HRESULT result;
        auto handle = m_windowHandle;

        // Initialize DirectInput
        // Initialize the main direct input interface.
        result = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, NULL);
        if (FAILED(result))
        {
            OINPUT_FATAL("DirectInput8Create");
        }

        // Initialize the direct input interface for the keyboard.
        result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
        if (FAILED(result))
        {
            OINPUT_FATAL("CreateDevice GUID_SysKeyboard");
        }

        // Set the data format.  In this case since it is a keyboard we can use the predefined data format.
        result = keyboard->SetDataFormat(&c_dfDIKeyboard);
        if (FAILED(result))
        {
            OINPUT_FATAL("keyboard SetDataFormat");
        }

        // Set the cooperative level of the keyboard to not share with other programs.
        result = keyboard->SetCooperativeLevel(handle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
        if (FAILED(result))
        {
            OINPUT_FATAL("keyboard SetCooperativeLevel");
        }

        // Initialize the direct input interface for the mouse.
        result = directInput->CreateDevice(GUID_SysMouse, &mouse, NULL);
        if (FAILED(result))
        {
            OINPUT_FATAL("CreateDevice GUID_SysMouse");
        }

        // Set the data format for the mouse using the pre-defined mouse data format.
        result = mouse->SetDataFormat(&c_dfDIMouse);
        if (FAILED(result))
        {
            OINPUT_FATAL("mouse SetDataFormat");
        }

        // Set the cooperative level of the mouse to share with other programs.
        result = mouse->SetCooperativeLevel(handle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
        if (FAILED(result))
        {
            OINPUT_FATAL("mouse SetCooperativeLevel");
        }

        memset(&mouseState, 0, sizeof(DIMOUSESTATE));
        memset(keyboardState, 0, 256);
        memset(previousKeyboardState, 0, 256);
    }

    InputWin32::~InputWin32()
    {
        if (mouse) mouse->Release();
        if (keyboard) keyboard->Release();
        if (directInput) directInput->Release();
    }

    void InputWin32::updateInternal()
    {
        POINT cur;
        GetCursorPos(&cur);
        ScreenToClient(m_windowHandle, &cur);
        mousePos[0] = cur.x;
        mousePos[1] = cur.y;
        mousePosf[0] = static_cast<float>(cur.x);
        mousePosf[1] = static_cast<float>(cur.y);

        readKeyboard();
        readMouse();
    }
    
    void InputWin32::readKeyboard()
    {
        HRESULT result;

        // Read the keyboard device.
        result = keyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);
        if (FAILED(result))
        {
            // If the keyboard lost focus or was not acquired then try to get control back.
            if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
            {
                result = keyboard->Acquire();
                if (FAILED(result))
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }

        for (int i = 0; i < 256; ++i)
        {
            if (!(previousKeyboardState[i] & 0x80) && (keyboardState[i] & 0x80))
            {
                setStateDown(static_cast<State>(i));
            }
            else if ((previousKeyboardState[i] & 0x80) && !(keyboardState[i] & 0x80))
            {
                setStateUp(static_cast<State>(i));
            }
        }
        memcpy(previousKeyboardState, keyboardState, 256);
    }

    void InputWin32::readMouse()
    {
        HRESULT result;

        // Read the mouse device.
        result = mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
        if (FAILED(result))
        {
            // If the mouse lost focus or was not acquired then try to get control back.
            if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
            {
                result = mouse->Acquire();
                if (FAILED(result))
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            if (!(previousMouseState.rgbButtons[i] & 0x80) && (mouseState.rgbButtons[i] & 0x80))
            {
                setStateDown(static_cast<State>(static_cast<int>(State::Mouse1)+i));
            }
            else if ((previousMouseState.rgbButtons[i] & 0x80) && !(mouseState.rgbButtons[i] & 0x80))
            {
                setStateUp(static_cast<State>(static_cast<int>(State::Mouse1)+i));
            }
        }

        memcpy(&previousMouseState, &mouseState, sizeof(DIMOUSESTATE));
        setStateValue(State::MouseX, (float)mouseState.lX);
        setStateValue(State::MouseY, (float)mouseState.lY);
        setStateValue(State::MouseZ, (float)mouseState.lZ);
    }

    void InputWin32::setMouseVisibleInternal(bool isCursorVisible)
    {
        ShowCursor(isCursorVisible ? TRUE : FALSE);
    }

    void InputWin32::setMouseIconInternal(const uint8_t *pDataRGBA, int width, int height, int hotSpotX, int hotSpotY)
    {
        auto it = m_cursors.find(pDataRGBA);
        if (it == m_cursors.end())
        {
            auto hCursor = pngToCursor(pDataRGBA, width, height, hotSpotX, hotSpotY);
            if (hCursor)
            {
                m_cursors[pDataRGBA] = hCursor;
                m_cursor = hCursor;
                SetCursor(hCursor);
            }
        }
        else
        {
            m_cursor = it->second;
            SetCursor(it->second);
        }
    }

    void InputWin32::setMousePosInternal(int x, int y)
    {
        POINT cur;
        cur.x = x;
        cur.y = y;
        ClientToScreen(m_windowHandle, &cur);
        SetCursorPos(cur.x, cur.y);
        mousePos[0] = x;
        mousePos[1] = y;
        mousePosf[0] = static_cast<float>(x);
        mousePosf[1] = static_cast<float>(y);
    }

    void InputWin32::unsetMouseIconInternal()
    {
        if (m_cursor)
        {
            m_cursor = NULL;
            SetCursor(LoadCursor(nullptr, IDC_ARROW));
        }
    }

    HCURSOR InputWin32::getCursor() const
    {
        return m_cursor;
    }

    void InputWin32::setCursor(HCURSOR cursor)
    {
        m_cursor = cursor;
        SetCursor(cursor);
    }
}
