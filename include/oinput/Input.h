#pragma once

#include <cinttypes>
#include <string>
#include <vector>

namespace oinput
{
    enum class State : int
    {
        None = 0,

#if defined(__APPLE__) || (defined(__unix__) && !defined(__rpi__)) || defined(ONUT_USE_SDL) // SDL2 scancode map
        KeyEscape = 41,
        Key1 = 30,
        Key2 = 31,
        Key3 = 32,
        Key4 = 33,
        Key5 = 34,
        Key6 = 35,
        Key7 = 36,
        Key8 = 37,
        Key9 = 38,
        Key0 = 39,
        KeyMinus = 45, /* - on main keyboard */
        KeyEquals = 46,
        KeyBackspace = 42, /* backspace */
        KeyTab = 43,
        KeyQ = 20,
        KeyW = 26,
        KeyE = 8,
        KeyR = 21,
        KeyT = 23,
        KeyY = 28,
        KeyU = 24,
        KeyI = 12,
        KeyO = 18,
        KeyP = 19,
        KeyLeftBracket = 47,
        KeyRightBracket = 48,
        KeyEnter = 40, /* Enter on main keyboard */
        KeyLeftControl = 224,
        KeyA = 4,
        KeyS = 22,
        KeyD = 7,
        KeyF = 9,
        KeyG = 10,
        KeyH = 11,
        KeyJ = 13,
        KeyK = 14,
        KeyL = 15,
        KeySemiColon = 51,
        KeyApostrophe = 52,
        KeyGrave = 53,    /* accent grave */
        KeyLeftShift = 225,
        KeyBackslash = 49,
        KeyZ = 29,
        KeyX = 27,
        KeyC = 6,
        KeyV = 25,
        KeyB = 5,
        KeyN = 17,
        KeyM = 16,
        KeyComma = 54,
        KeyPeriod = 55, /* . on main keyboard */
        KeySlash = 56, /* / on main keyboard */
        KeyRightShift = 229,
        KeyMultiply = 85, /* * on numeric keypad */
        KeyLeftAlt = 226, /* left Alt */
        KeySpaceBar = 44,
        KeyCapsLock = 57,
        KeyF1 = 58,
        KeyF2 = 59,
        KeyF3 = 60,
        KeyF4 = 61,
        KeyF5 = 62,
        KeyF6 = 63,
        KeyF7 = 64,
        KeyF8 = 65,
        KeyF9 = 66,
        KeyF10 = 67,
        KeyNumLock = 83,
        KeyScrollLock = 71, /* Scroll Lock */
        KeyNumPad7 = 95,
        KeyNumPad8 = 96,
        KeyNumPad9 = 97,
        KeyNumPadMinus = 86, /* - on numeric keypad */
        KeyNumPad4 = 92,
        KeyNumPad5 = 93,
        KeyNumPad6 = 94,
        KeyNumPadAdd = 87, /* + on numeric keypad */
        KeyNumPad1 = 89,
        KeyNumPad2 = 90,
        KeyNumPad3 = 91,
        KeyNumPad0 = 98,
        KeyNumPadPeriod = 99, /* . on numeric keypad */
        KeyF11 = 68,
        KeyF12 = 69,
        KeyF13 = 104, /* (NEC PC98) */
        KeyF14 = 105, /* (NEC PC98) */
        KeyF15 = 106, /* (NEC PC98) */
        KeyNumPadEquals = 103, /* = on numeric keypad (NEC PC98) */
        KeyPreviousTrack = 259, /* Previous Track (OINPUT_CIRCUMFLEX on Japanese keyboard) */
        KeyAt = 206, /* (NEC PC98) */
        KeyColon = 203, /* (NEC PC98) */
        KeyStop = 120, /* (NEC PC98) */
        KeyNextTrack = 258, /* Next Track */
        KeyNumPadEnter = 88, /* Enter on numeric keypad */
        KeyRightControl = 228,
        KeyMute = 262, /* Mute */
        KeyCalculator = 226, /* Calculator */
        KeyPlayPause = 261, /* Play / Pause */
        KeyMediaStop = 260, /* Media Stop */
        KeyVolumeDown = 129, /* Volume - */
        KeyVolumeUp = 128, /* Volume + */
        KeyWebHome = 269, /* Web home */
        KeyNumPadComma = 133, /* , on numeric keypad (NEC PC98) */
        KeyNumPadDivide = 84, /* / on numeric keypad */
        Key_SYSRQ = 154,
        KeyRightAlt = 230, /* right Alt */
        KeyAltCar = KeyRightAlt, /* right Alt */
        KeyPause = 72, /* Pause */
        KeyHome = 74, /* Home on arrow keypad */
        KeyUp = 82, /* UpArrow on arrow keypad */
        KeyPageUp = 75, /* PgUp on arrow keypad */
        KeyLeft = 80, /* LeftArrow on arrow keypad */
        KeyRight = 79, /* RightArrow on arrow keypad */
        KeyEnd = 77, /* End on arrow keypad */
        KeyDown = 81, /* DownArrow on arrow keypad */
        KeyPageDown = 78, /* PgDn on arrow keypad */
        KeyInsert = 73, /* Insert on arrow keypad */
        KeyDelete = 76, /* Delete on arrow keypad */
        KeyLeftWindows = 227, /* Left Windows key */
        KeyRightWindows = 231, /* Right Windows key */
        KeyAppMenu = 118, /* AppMenu key */
        KeyPower = 102, /* System Power */
        KeySleep = 282, /* System Sleep */
        KeyWebSearch = 268, /* Web Search */
        KeyWebFavorites = 112, /* Web Favorites */
        KeyWebRefresh = 273, /* Web Refresh */
        KeyWebStop = 272, /* Web Stop */
        KeyWebForward = 271, /* Web Forward */
        KeyWebBack = 270, /* Web Back */
        KeyMyComputer = 267, /* My Computer */
        KeyMailL = 265, /* Mail */
        KeyMediaSelect = 263, /* Media Select */

        /*
        *  Alternate names for keys originally not used on US keyboards.
        */
        KeyCircomflex = KeyPreviousTrack, /* Japanese keyboard */

        /*
        * X-Arcade
        */
        XArcadeLeftPaddle = Key3, /* Key3 */
        XArcadeRightPaddle = Key4, /* Key4 */

        XArcade1Player = Key1, /* Key1 */
        XArcade2Player = Key2, /* Key2 */

        XArcadeLJoyLeft = KeyNumPad4, /* KeyNumPad4 */
        XArcadeLJoyRight = KeyNumPad6, /* KeyNumPad6 */
        XArcadeLJoyUp = KeyNumPad8, /* KeyNumPad8 */
        XArcadeLJoyDown = KeyNumPad2, /* KeyNumPad2 */

        XArcadeRJoyLeft = KeyD, /* KeyD */
        XArcadeRJoyRight = KeyG, /* KeyG */
        XArcadeRJoyUp = KeyR, /* KeyR */
        XArcadeRJoyDown = KeyF, /* KeyF */

        XArcadeLButton1 = KeyLeftControl, /* KeyLeftControl */
        XArcadeLButton2 = KeyLeftAlt, /* KeyLeftAlt */
        XArcadeLButton3 = KeySpaceBar, /* KeySpaceBar */
        XArcadeLButton4 = KeyLeftShift, /* KeyLeftShift */
        XArcadeLButton5 = KeyZ, /* KeyZ */
        XArcadeLButton6 = KeyX, /* KeyX */
        XArcadeLButton7 = KeyC, /* KeyC */
        XArcadeLButton8 = Key5, /* Key5 */

        XArcadeRButton1 = KeyA, /* KeyA */
        XArcadeRButton2 = KeyS, /* KeyS */
        XArcadeRButton3 = KeyQ, /* KeyQ */
        XArcadeRButton4 = KeyW, /* KeyW */
        XArcadeRButton5 = KeyE, /* KeyE */
        XArcadeRButton6 = KeyLeftBracket, /* KeyLeftBracket */
        XArcadeRButton7 = KeyRightBracket, /* KeyRightBracket */
        XArcadeRButton8 = Key6, /* Key6 */

        /*
        * Mouse
        */
        Mouse1 = 285,
        Mouse2,
        Mouse3,
        Mouse4,
        MouseX,
        MouseY,
        MouseZ,
        MouseW,

        // ??? Those won't work with SDL because I don't know how to match their codes
        KeyOEM102,
        KeyKana, /* (Japanese keyboard) */
        KeyAbntC1, /* /? on Brazilian keyboard */
        KeyConvert, /* (Japanese keyboard) */
        KeyNoConvert, /* (Japanese keyboard) */
        KeyYen, /* (Japanese keyboard) */
        KeyAbntC2, /* Numpad . on Brazilian keyboard */
        KeyUnderline, /* (NEC PC98) */
        KeyKanji, /* (Japanese keyboard) */
        KeyAx, /* (Japan AX) */
        KeyUnlabeled, /* (J3100) */
        KeyWake, /* System Wake */
#else
        KeyEscape = 0x01,
        Key1 = 0x02,
        Key2 = 0x03,
        Key3 = 0x04,
        Key4 = 0x05,
        Key5 = 0x06,
        Key6 = 0x07,
        Key7 = 0x08,
        Key8 = 0x09,
        Key9 = 0x0A,
        Key0 = 0x0B,
        KeyMinus = 0x0C, /* - on main keyboard */
        KeyEquals = 0x0D,
        KeyBackspace = 0x0E, /* backspace */
        KeyTab = 0x0F,
        KeyQ = 0x10,
        KeyW = 0x11,
        KeyE = 0x12,
        KeyR = 0x13,
        KeyT = 0x14,
        KeyY = 0x15,
        KeyU = 0x16,
        KeyI = 0x17,
        KeyO = 0x18,
        KeyP = 0x19,
        KeyLeftBracket = 0x1A,
        KeyRightBracket = 0x1B,
        KeyEnter = 0x1C, /* Enter on main keyboard */
        KeyLeftControl = 0x1D,
        KeyA = 0x1E,
        KeyS = 0x1F,
        KeyD = 0x20,
        KeyF = 0x21,
        KeyG = 0x22,
        KeyH = 0x23,
        KeyJ = 0x24,
        KeyK = 0x25,
        KeyL = 0x26,
        KeySemiColon = 0x27,
        KeyApostrophe = 0x28,
        KeyGrave = 0x29,    /* accent grave */
        KeyLeftShift = 0x2A,
        KeyBackslash = 0x2B,
        KeyZ = 0x2C,
        KeyX = 0x2D,
        KeyC = 0x2E,
        KeyV = 0x2F,
        KeyB = 0x30,
        KeyN = 0x31,
        KeyM = 0x32,
        KeyComma = 0x33,
        KeyPeriod = 0x34, /* . on main keyboard */
        KeySlash = 0x35, /* / on main keyboard */
        KeyRightShift = 0x36,
        KeyMultiply = 0x37, /* * on numeric keypad */
        KeyLeftAlt = 0x38, /* left Alt */
        KeySpaceBar = 0x39,
        KeyCapsLock = 0x3A,
        KeyF1 = 0x3B,
        KeyF2 = 0x3C,
        KeyF3 = 0x3D,
        KeyF4 = 0x3E,
        KeyF5 = 0x3F,
        KeyF6 = 0x40,
        KeyF7 = 0x41,
        KeyF8 = 0x42,
        KeyF9 = 0x43,
        KeyF10 = 0x44,
        KeyNumLock = 0x45,
        KeyScrollLock = 0x46, /* Scroll Lock */
        KeyNumPad7 = 0x47,
        KeyNumPad8 = 0x48,
        KeyNumPad9 = 0x49,
        KeyNumPadMinus = 0x4A, /* - on numeric keypad */
        KeyNumPad4 = 0x4B,
        KeyNumPad5 = 0x4C,
        KeyNumPad6 = 0x4D,
        KeyNumPadAdd = 0x4E, /* + on numeric keypad */
        KeyNumPad1 = 0x4F,
        KeyNumPad2 = 0x50,
        KeyNumPad3 = 0x51,
        KeyNumPad0 = 0x52,
        KeyNumPadPeriod = 0x53, /* . on numeric keypad */
        KeyOEM102 = 0x56, /* <> or \| on RT 102-key keyboard (Non-U.S.) */
        KeyF11 = 0x57,
        KeyF12 = 0x58,
#if defined(__rpi__)
        KeyF13 = 183, /* (NEC PC98) */
        KeyF14 = 184, /* (NEC PC98) */
        KeyF15 = 185, /* (NEC PC98) */
        KeyKana = 90, /* (Japanese keyboard) */
        KeyAbntC1 = 0x73, /* /? on Brazilian keyboard */
        KeyConvert = 0x79, /* (Japanese keyboard) */
        KeyNoConvert = 0x7B, /* (Japanese keyboard) */
        KeyYen = 124, /* (Japanese keyboard) */
        KeyAbntC2 = 0x7E, /* Numpad . on Brazilian keyboard */
        KeyNumPadEquals = 117, /* = on numeric keypad (NEC PC98) */
        KeyPreviousTrack = 165, /* Previous Track (OINPUT_CIRCUMFLEX on Japanese keyboard) */
        KeyAt = 0x91, /* (NEC PC98) */
        KeyColon = 0x92, /* (NEC PC98) */
        KeyUnderline = 0x93, /* (NEC PC98) */
        KeyKanji = 0x94, /* (Japanese keyboard) */
        KeyStop = 128, /* (NEC PC98) */
        KeyAx = 0x96, /* (Japan AX) */
        KeyUnlabeled = 0x97, /* (J3100) */
        KeyNextTrack = 163, /* Next Track */
        KeyNumPadEnter = 96, /* Enter on numeric keypad */
        KeyRightControl = 97,
        KeyMute = 113, /* Mute */
        KeyCalculator = 140, /* Calculator */
        KeyPlayPause = 164, /* Play / Pause */
        KeyMediaStop = 166, /* Media Stop */
        KeyVolumeDown = 114, /* Volume - */
        KeyVolumeUp = 115, /* Volume + */
        KeyWebHome = 172, /* Web home */
        KeyNumPadComma = 121, /* , on numeric keypad (NEC PC98) */
        KeyNumPadDivide = 98, /* / on numeric keypad */
        Key_SYSRQ = 99,
        KeyRightAlt = 100, /* right Alt */
        KeyAltCar = KeyRightAlt, /* right Alt */
        KeyPause = 119, /* Pause */
        KeyHome = 102, /* Home on arrow keypad */
        KeyUp = 103, /* UpArrow on arrow keypad */
        KeyPageUp = 104, /* PgUp on arrow keypad */
        KeyLeft = 105, /* LeftArrow on arrow keypad */
        KeyRight = 106, /* RightArrow on arrow keypad */
        KeyEnd = 107, /* End on arrow keypad */
        KeyDown = 108, /* DownArrow on arrow keypad */
        KeyPageDown = 109, /* PgDn on arrow keypad */
        KeyInsert = 110, /* Insert on arrow keypad */
        KeyDelete = 111, /* Delete on arrow keypad */
        KeyLeftWindows = 0xDB, /* Left Windows key */
        KeyRightWindows = 0xDC, /* Right Windows key */
        KeyAppMenu = 0xDD, /* AppMenu key */
        KeyPower = 116, /* System Power */
        KeySleep = 142, /* System Sleep */
        KeyWake = 143, /* System Wake */
        KeyWebSearch = 217, /* Web Search */
        KeyWebFavorites = 0x16c, /* Web Favorites */
        KeyWebRefresh = 173, /* Web Refresh */
        KeyWebStop = 0xE8, /* Web Stop */
        KeyWebForward = 0x115, /* Web Forward */
        KeyWebBack = 0x116, /* Web Back */
        KeyMyComputer = 0xEB, /* My Computer */
        KeyMailL = 155, /* Mail */
        KeyMediaSelect = 0xED, /* Media Select */

        /*
        *  Alternate names for keys originally not used on US keyboards.
        */
        KeyCircomflex = KeyPreviousTrack, /* Japanese keyboard */
#else // __rpi__
        KeyF13 = 0x64, /* (NEC PC98) */
        KeyF14 = 0x65, /* (NEC PC98) */
        KeyF15 = 0x66, /* (NEC PC98) */
        KeyKana = 0x70, /* (Japanese keyboard) */
        KeyAbntC1 = 0x73, /* /? on Brazilian keyboard */
        KeyConvert = 0x79, /* (Japanese keyboard) */
        KeyNoConvert = 0x7B, /* (Japanese keyboard) */
        KeyYen = 0x7D, /* (Japanese keyboard) */
        KeyAbntC2 = 0x7E, /* Numpad . on Brazilian keyboard */
        KeyNumPadEquals = 0x8D, /* = on numeric keypad (NEC PC98) */
        KeyPreviousTrack = 0x90, /* Previous Track (OINPUT_CIRCUMFLEX on Japanese keyboard) */
        KeyAt = 0x91, /* (NEC PC98) */
        KeyColon = 0x92, /* (NEC PC98) */
        KeyUnderline = 0x93, /* (NEC PC98) */
        KeyKanji = 0x94, /* (Japanese keyboard) */
        KeyStop = 0x95, /* (NEC PC98) */
        KeyAx = 0x96, /* (Japan AX) */
        KeyUnlabeled = 0x97, /* (J3100) */
        KeyNextTrack = 0x99, /* Next Track */
        KeyNumPadEnter = 0x9C, /* Enter on numeric keypad */
        KeyRightControl = 0x9D,
        KeyMute = 0xA0, /* Mute */
        KeyCalculator = 0xA1, /* Calculator */
        KeyPlayPause = 0xA2, /* Play / Pause */
        KeyMediaStop = 0xA4, /* Media Stop */
        KeyVolumeDown = 0xAE, /* Volume - */
        KeyVolumeUp = 0xB0, /* Volume + */
        KeyWebHome = 0xB2, /* Web home */
        KeyNumPadComma = 0xB3, /* , on numeric keypad (NEC PC98) */
        KeyNumPadDivide = 0xB5, /* / on numeric keypad */
        Key_SYSRQ = 0xB7,
        KeyRightAlt = 0xB8, /* right Alt */
        KeyAltCar = KeyRightAlt, /* right Alt */
        KeyPause = 0xC5, /* Pause */
        KeyHome = 0xC7, /* Home on arrow keypad */
        KeyUp = 0xC8, /* UpArrow on arrow keypad */
        KeyPageUp = 0xC9, /* PgUp on arrow keypad */
        KeyLeft = 0xCB, /* LeftArrow on arrow keypad */
        KeyRight = 0xCD, /* RightArrow on arrow keypad */
        KeyEnd = 0xCF, /* End on arrow keypad */
        KeyDown = 0xD0, /* DownArrow on arrow keypad */
        KeyPageDown = 0xD1, /* PgDn on arrow keypad */
        KeyInsert = 0xD2, /* Insert on arrow keypad */
        KeyDelete = 0xD3, /* Delete on arrow keypad */
        KeyLeftWindows = 0xDB, /* Left Windows key */
        KeyRightWindows = 0xDC, /* Right Windows key */
        KeyAppMenu = 0xDD, /* AppMenu key */
        KeyPower = 0xDE, /* System Power */
        KeySleep = 0xDF, /* System Sleep */
        KeyWake = 0xE3, /* System Wake */
        KeyWebSearch = 0xE5, /* Web Search */
        KeyWebFavorites = 0xE6, /* Web Favorites */
        KeyWebRefresh = 0xE7, /* Web Refresh */
        KeyWebStop = 0xE8, /* Web Stop */
        KeyWebForward = 0xE9, /* Web Forward */
        KeyWebBack = 0xEA, /* Web Back */
        KeyMyComputer = 0xEB, /* My Computer */
        KeyMailL = 0xEC, /* Mail */
        KeyMediaSelect = 0xED, /* Media Select */

        /*
        *  Alternate names for keys originally not used on US keyboards.
        */
        KeyCircomflex = KeyPreviousTrack, /* Japanese keyboard */
#endif // else __rpi__

        /*
        * X-Arcade
        */
        XArcadeLeftPaddle = 4, /* Key3 */
        XArcadeRightPaddle = 5, /* Key4 */

        XArcade1Player = 2, /* Key1 */
        XArcade2Player = 3, /* Key2 */

        XArcadeLJoyLeft = 75, /* KeyNumPad4 */
        XArcadeLJoyRight = 77, /* KeyNumPad6 */
        XArcadeLJoyUp = 72, /* KeyNumPad8 */
        XArcadeLJoyDown = 80, /* KeyNumPad2 */

        XArcadeRJoyLeft = 32, /* KeyD */
        XArcadeRJoyRight = 34, /* KeyG */
        XArcadeRJoyUp = 19, /* KeyR */
        XArcadeRJoyDown = 33, /* KeyF */

        XArcadeLButton1 = 29, /* KeyLeftControl */
        XArcadeLButton2 = 56, /* KeyLeftAlt */
        XArcadeLButton3 = 57, /* KeySpaceBar */
        XArcadeLButton4 = 42, /* KeyLeftShift */
        XArcadeLButton5 = 44, /* KeyZ */
        XArcadeLButton6 = 45, /* KeyX */
        XArcadeLButton7 = 46, /* KeyC */
        XArcadeLButton8 = 6, /* Key5 */

        XArcadeRButton1 = 30, /* KeyA */
        XArcadeRButton2 = 31, /* KeyS */
        XArcadeRButton3 = 16, /* KeyQ */
        XArcadeRButton4 = 17, /* KeyW */
        XArcadeRButton5 = 18, /* KeyE */
        XArcadeRButton6 = 26, /* KeyLeftBracket */
        XArcadeRButton7 = 27, /* KeyRightBracket */
        XArcadeRButton8 = 7, /* Key6 */

        /*
        * Mouse
        */
        Mouse1 = 256,
        Mouse2 = 257,
        Mouse3 = 258,
        Mouse4 = 259,
        MouseX = 260,
        MouseY = 261,
        MouseZ = 262,
        MouseW = 263,
#endif // __APPLE__

        STATE_COUNT
    };

    static const int STATE_COUNT = static_cast<int>(State::STATE_COUNT);
    static const int GAME_PAD_COUNT = 4;

    class GamePad;
    class Joystick;

    class Input
    {
    public:
        /* Create an Input System */
        static Input *create(void *window); /* HWND, SDLWindow, etc. */

        virtual ~Input();

        /* 
        * Call this every frame
        * width and height is gameplay area resolution.
        */
        void update(int width, int height);

        void setStateDown(State state);
        void setStateUp(State state);
        void setStateValue(State state, float in_value);
        bool isStateDown(State state) const;
        bool isStateUp(State state) const;
        bool isStateJustDown(State state) const;
        bool isStateJustUp(State state) const;
        float getStateValue(State state) const;

        GamePad *getGamePad(int index) const;
        Joystick *getJoystick(int index) const;
        int getJoystickCount() const;
        bool getDoubleClicked() const;
        void onDoubleClicked();

        void activateJoystick(int index);
        void deactivateJoystick(int index);

        void setMouseVisible(bool isCursorVisible);
        /*
        * The icons will be cached internally using the pDataRGBA pointer as key.
        * You can free the image after calling this, but keep a reference on the pointer as identifier.
        */
        void setMouseIcon(const uint8_t *pDataRGBA, int width, int height, int hotSpotX, int hotSpotY);
        void unsetMouseIcon();
        void setMousePos(int x, int y);
        void setFpsMouse(bool fpsMouse);

        int mousePos[2] = {0, 0};
        float mousePosf[2] = {0.0f, 0.0f};
        int mouseDelta[2] = {0, 0};

    protected:
        Input();

        virtual void readKeyboard() = 0;
        virtual void readMouse() = 0;
        virtual void setMouseVisibleInternal(bool isCursorVisible) = 0;
        virtual void setMouseIconInternal(const uint8_t *pDataRGBA, int width, int height, int hotSpotX, int hotSpotY) = 0;
        virtual void unsetMouseIconInternal() = 0;
        virtual void setMousePosInternal(int x, int y) = 0;
        virtual void updateInternal() = 0;

        struct InputState
        {
            float value = 0;
            bool isDown = false;
            int frameId = 0;
        };

        int m_frameId = -1;
        InputState*	m_prevStates = nullptr;
        InputState*	m_curStates = nullptr;
        InputState*	m_states = nullptr;
        InputState*	m_statesRestore = nullptr;
        GamePad *m_gamePads[GAME_PAD_COUNT] = { nullptr };
        std::vector<Joystick *> m_joysticks;
        bool m_isCursorVisible = true;
        bool m_fpsMouse = false;
        bool m_doubleClicked = false;
        bool m_lastDoubleClicked = false;
        int m_mousePosOnFPSStart[2] = { 0, 0 };
        int m_resolution[2] = { 0, 0 };
    };
}

// Shortcuts to make things easier

#define OKeyEscape oinput::State::KeyEscape
#define OKey1 oinput::State::Key1
#define OKey2 oinput::State::Key2
#define OKey3 oinput::State::Key3
#define OKey4 oinput::State::Key4
#define OKey5 oinput::State::Key5
#define OKey6 oinput::State::Key6
#define OKey7 oinput::State::Key7
#define OKey8 oinput::State::Key8
#define OKey9 oinput::State::Key9
#define OKey0 oinput::State::Key0
#define OKeyMinus oinput::State::KeyMinus /* - on main keyboard */
#define OKeyEquals oinput::State::KeyEquals
#define OKeyBackspace oinput::State::KeyBackspace /* backspace */
#define OKeyTab oinput::State::KeyTab
#define OKeyQ oinput::State::KeyQ
#define OKeyW oinput::State::KeyW
#define OKeyE oinput::State::KeyE
#define OKeyR oinput::State::KeyR
#define OKeyT oinput::State::KeyT
#define OKeyY oinput::State::KeyY
#define OKeyU oinput::State::KeyU
#define OKeyI oinput::State::KeyI
#define OKeyO oinput::State::KeyO
#define OKeyP oinput::State::KeyP
#define OKeyLeftBracket oinput::State::KeyLeftBracket
#define OKeyRightBracket oinput::State::KeyRightBracket
#define OKeyEnter oinput::State::KeyEnter /* Enter on main keyboard */
#define OKeyLeftControl oinput::State::KeyLeftControl
#define OKeyA oinput::State::KeyA
#define OKeyS oinput::State::KeyS
#define OKeyD oinput::State::KeyD
#define OKeyF oinput::State::KeyF
#define OKeyG oinput::State::KeyG
#define OKeyH oinput::State::KeyH
#define OKeyJ oinput::State::KeyJ
#define OKeyK oinput::State::KeyK
#define OKeyL oinput::State::KeyL
#define OKeySemiColon oinput::State::KeySemiColon
#define OKeyApostrophe oinput::State::KeyApostrophe
#define OKeyGrave oinput::State::KeyGrave /* accent grave */
#define OKeyLeftShift oinput::State::KeyLeftShift
#define OKeyBackslash oinput::State::KeyBackslash
#define OKeyZ oinput::State::KeyZ
#define OKeyX oinput::State::KeyX
#define OKeyC oinput::State::KeyC
#define OKeyV oinput::State::KeyV
#define OKeyB oinput::State::KeyB
#define OKeyN oinput::State::KeyN
#define OKeyM oinput::State::KeyM
#define OKeyComma oinput::State::KeyComma
#define OKeyPeriod oinput::State::KeyPeriod /* . on main keyboard */
#define OKeySlash oinput::State::KeySlash /* / on main keyboard */
#define OKeyRightShift oinput::State::KeyRightShift
#define OKeyMultiply oinput::State::KeyMultiply /* * on numeric keypad */
#define OKeyLeftAlt oinput::State::KeyLeftAlt /* left Alt */
#define OKeySpaceBar oinput::State::KeySpaceBar
#define OKeyCapsLock oinput::State::KeyCapsLock
#define OKeyF1 oinput::State::KeyF1
#define OKeyF2 oinput::State::KeyF2
#define OKeyF3 oinput::State::KeyF3
#define OKeyF4 oinput::State::KeyF4
#define OKeyF5 oinput::State::KeyF5
#define OKeyF6 oinput::State::KeyF6
#define OKeyF7 oinput::State::KeyF7
#define OKeyF8 oinput::State::KeyF8
#define OKeyF9 oinput::State::KeyF9
#define OKeyF10 oinput::State::KeyF10
#define OKeyNumLock oinput::State::KeyNumLock
#define OKeyScrollLock oinput::State::KeyScrollLock /* Scroll Lock */
#define OKeyNumPad7 oinput::State::KeyNumPad7
#define OKeyNumPad8 oinput::State::KeyNumPad8
#define OKeyNumPad9 oinput::State::KeyNumPad9
#define OKeyNumPadMinus oinput::State::KeyNumPadMinus /* - on numeric keypad */
#define OKeyNumPad4 oinput::State::KeyNumPad4
#define OKeyNumPad5 oinput::State::KeyNumPad5
#define OKeyNumPad6 oinput::State::KeyNumPad6
#define OKeyNumPadAdd oinput::State::KeyNumPadAdd /* + on numeric keypad */
#define OKeyNumPad1 oinput::State::KeyNumPad1
#define OKeyNumPad2 oinput::State::KeyNumPad2
#define OKeyNumPad3 oinput::State::KeyNumPad3
#define OKeyNumPad0 oinput::State::KeyNumPad0
#define OKeyNumPadPeriod oinput::State::KeyNumPadPeriod /* . on numeric keypad */
#define OKeyOEM102 oinput::State::KeyOEM102 /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define OKeyF11 oinput::State::KeyF11
#define OKeyF12 oinput::State::KeyF12
#define OKeyF13 oinput::State::KeyF13 /* (NEC PC98) */
#define OKeyF14 oinput::State::KeyF14 /* (NEC PC98) */
#define OKeyF15 oinput::State::KeyF15 /* (NEC PC98) */
#define OKeyKana oinput::State::KeyKana /* (Japanese keyboard) */
#define OKeyAbntC1 oinput::State::KeyAbntC1 /* /? on Brazilian keyboard */
#define OKeyConvert oinput::State::KeyConvert /* (Japanese keyboard) */
#define OKeyNoConvert oinput::State::KeyNoConvert /* (Japanese keyboard) */
#define OKeyYen oinput::State::KeyYen /* (Japanese keyboard) */
#define OKeyAbntC2 oinput::State::KeyAbntC2 /* Numpad . on Brazilian keyboard */
#define OKeyNumPadEquals oinput::State::KeyNumPadEquals /* = on numeric keypad (NEC PC98) */
#define OKeyPreviousTrack oinput::State::KeyPreviousTrack /* Previous Track (OINPUT_CIRCUMFLEX on Japanese keyboard) */
#define OKeyAt oinput::State::KeyAt /* (NEC PC98) */
#define OKeyColon oinput::State::KeyColon /* (NEC PC98) */
#define OKeyUnderline oinput::State::KeyUnderline /* (NEC PC98) */
#define OKeyKanji oinput::State::KeyKanji /* (Japanese keyboard) */
#define OKeyStop oinput::State::KeyStop /* (NEC PC98) */
#define OKeyAx oinput::State::KeyAx /* (Japan AX) */
#define OKeyUnlabeled oinput::State::KeyUnlabeled /* (J3100) */
#define OKeyNextTrack oinput::State::KeyNextTrack /* Next Track */
#define OKeyNumPadEnter oinput::State::KeyNumPadEnter /* Enter on numeric keypad */
#define OKeyRightControl oinput::State::KeyRightControl
#define OKeyMute oinput::State::KeyMute /* Mute */
#define OKeyCalculator oinput::State::KeyCalculator /* Calculator */
#define OKeyPlayPause oinput::State::KeyPlayPause /* Play / Pause */
#define OKeyMediaStop oinput::State::KeyMediaStop /* Media Stop */
#define OKeyVolumeDown oinput::State::KeyVolumeDown /* Volume - */
#define OKeyVolumeUp oinput::State::KeyVolumeUp /* Volume + */
#define OKeyWebHome oinput::State::KeyWebHome /* Web home */
#define OKeyNumPadComma oinput::State::KeyNumPadComma /* on numeric keypad (NEC PC98) */
#define OKeyNumPadDivide oinput::State::KeyNumPadDivide /* / on numeric keypad */
#define OKey_SYSRQ oinput::State::Key_SYSRQ
#define OKeyRightAlt oinput::State::KeyRightAlt /* right Alt */
#define OKeyAltCar oinput::State::KeyAltCar /* right Alt */
#define OKeyPause oinput::State::KeyPause /* Pause */
#define OKeyHome oinput::State::KeyHome /* Home on arrow keypad */
#define OKeyUp oinput::State::KeyUp /* UpArrow on arrow keypad */
#define OKeyPageUp oinput::State::KeyPageUp /* PgUp on arrow keypad */
#define OKeyLeft oinput::State::KeyLeft /* LeftArrow on arrow keypad */
#define OKeyRight oinput::State::KeyRight /* RightArrow on arrow keypad */
#define OKeyEnd oinput::State::KeyEnd /* End on arrow keypad */
#define OKeyDown oinput::State::KeyDown /* DownArrow on arrow keypad */
#define OKeyPageDown oinput::State::KeyPageDown /* PgDn on arrow keypad */
#define OKeyInsert oinput::State::KeyInsert /* Insert on arrow keypad */
#define OKeyDelete oinput::State::KeyDelete /* Delete on arrow keypad */
#define OKeyLeftWindows oinput::State::KeyLeftWindows /* Left Windows key */
#define OKeyRightWindows oinput::State::KeyRightWindows /* Right Windows key */
#define OKeyAppMenu oinput::State::KeyAppMenu /* AppMenu key */
#define OKeyPower oinput::State::KeyPower /* System Power */
#define OKeySleep oinput::State::KeySleep /* System Sleep */
#define OKeyWake oinput::State::KeyWake /* System Wake */
#define OKeyWebSearch oinput::State::KeyWebSearch /* Web Search */
#define OKeyWebFavorites oinput::State::KeyWebFavorites /* Web Favorites */
#define OKeyWebRefresh oinput::State::KeyWebRefresh /* Web Refresh */
#define OKeyWebStop oinput::State::KeyWebStop /* Web Stop */
#define OKeyWebForward oinput::State::KeyWebForward /* Web Forward */
#define OKeyWebBack oinput::State::KeyWebBack /* Web Back */
#define OKeyMyComputer oinput::State::KeyMyComputer /* My Computer */
#define OKeyMailL oinput::State::KeyMailL /* Mail */
#define OKeyMediaSelect oinput::State::KeyMediaSelect /* Media Select */

/*
*  Alternate names for keys originally not used on US keyboards.
*/
#define OKeyCircomflex oinput::State::KeyCircomflex /* Japanese keyboard */

/*
* X-Arcade
*/
#define OXArcadeLeftPaddle oinput::State::XArcadeLeftPaddle
#define OXArcadeRightPaddle oinput::State::XArcadeRightPaddle
#define OXArcade1Player oinput::State::XArcade1Player
#define OXArcade2Player oinput::State::XArcade2Player
#define OXArcadeLJoyLeft oinput::State::XArcadeLJoyLeft
#define OXArcadeLJoyRight oinput::State::XArcadeLJoyRight
#define OXArcadeLJoyUp oinput::State::XArcadeLJoyUp
#define OXArcadeLJoyDown oinput::State::XArcadeLJoyDown
#define OXArcadeRJoyLeft oinput::State::XArcadeRJoyLeft
#define OXArcadeRJoyRight oinput::State::XArcadeRJoyRight
#define OXArcadeRJoyUp oinput::State::XArcadeRJoyUp
#define OXArcadeLButton1 oinput::State::XArcadeLButton1
#define OXArcadeLButton2 oinput::State::XArcadeLButton2
#define OXArcadeLButton3 oinput::State::XArcadeLButton3
#define OXArcadeLButton4 oinput::State::XArcadeLButton4
#define OXArcadeLButton5 oinput::State::XArcadeLButton5
#define OXArcadeLButton6 oinput::State::XArcadeLButton6
#define OXArcadeLButton7 oinput::State::XArcadeLButton7
#define OXArcadeLButton8 oinput::State::XArcadeLButton8
#define OXArcadeRButton1 oinput::State::XArcadeRButton1
#define OXArcadeRButton2 oinput::State::XArcadeRButton2
#define OXArcadeRButton3 oinput::State::XArcadeRButton3
#define OXArcadeRButton4 oinput::State::XArcadeRButton4
#define OXArcadeRButton5 oinput::State::XArcadeRButton5
#define OXArcadeRButton6 oinput::State::XArcadeRButton6
#define OXArcadeRButton7 oinput::State::XArcadeRButton7
#define OXArcadeRButton8 oinput::State::XArcadeRButton8

/*
* Mouse
*/
#define OMouse1 oinput::State::Mouse1
#define OMouse2 oinput::State::Mouse2
#define OMouse3 oinput::State::Mouse3
#define OLeftMouse oinput::State::Mouse1
#define ORightMouse oinput::State::Mouse2
#define OMiddleMouse oinput::State::Mouse3
#define OMouse4 oinput::State::Mouse4
#define OMouseX oinput::State::MouseX
#define OMouseY oinput::State::MouseY
#define OMouseZ oinput::State::MouseZ
#define OMouseW oinput::State::MouseW
