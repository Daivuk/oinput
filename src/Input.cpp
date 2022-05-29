#include "oinput/Input.h"
#include "oinput/GamePad.h"
#include "oinput/Joystick.h"
#include <algorithm>
#include <cassert>

namespace oinput
{
    Input::Input()
    {
        m_prevStates = new InputState[STATE_COUNT];
        m_curStates = new InputState[STATE_COUNT];
        m_states = new InputState[STATE_COUNT];
        m_statesRestore = new InputState[STATE_COUNT];
        m_frameId = 1;

        for (int i = 0; i < GAME_PAD_COUNT; ++i)
        {
            m_gamePads[i] = GamePad::create(i);
        }
    }

    Input::~Input()
    {
        for (int i = 0; i < GAME_PAD_COUNT; ++i)
        {
            delete m_gamePads[i];
        }
        for (auto pJoystick : m_joysticks)
        {
            delete pJoystick;
        }
        m_joysticks.clear();

        delete[] m_prevStates;
        delete[] m_curStates;
        delete[] m_states;
        delete[] m_statesRestore;
    }

    void Input::setStateDown(State in_stateId)
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        auto& state = m_states[static_cast<int>(in_stateId)];
        m_statesRestore[static_cast<int>(in_stateId)].isDown = true;
        if (state.frameId != m_frameId)
        {
            state.isDown = true;
            state.frameId = m_frameId;
        }
    }

    void Input::setStateUp(State in_stateId)
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        auto& state = m_states[static_cast<int>(in_stateId)];
        m_statesRestore[static_cast<int>(in_stateId)].isDown = false;
        if (state.frameId != m_frameId)
        {
            state.isDown = false;
            state.frameId = m_frameId;
        }
    }

    void Input::setStateValue(State in_stateId, float in_value)
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        m_statesRestore[static_cast<int>(in_stateId)].value = in_value;
        m_states[static_cast<int>(in_stateId)].value = in_value;
    }

    bool Input::isStateDown(State in_stateId) const
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        return m_curStates[static_cast<int>(in_stateId)].isDown;
    }

    bool Input::isStateUp(State in_stateId) const
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        return !m_curStates[static_cast<int>(in_stateId)].isDown;
    }

    bool Input::isStateJustDown(State in_stateId) const
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        return (!m_prevStates[static_cast<int>(in_stateId)].isDown && m_curStates[static_cast<int>(in_stateId)].isDown);
    }

    bool Input::isStateJustUp(State in_stateId) const
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        return (m_prevStates[static_cast<int>(in_stateId)].isDown && !m_curStates[static_cast<int>(in_stateId)].isDown);
    }

    float Input::getStateValue(State in_stateId) const
    {
        assert(static_cast<int>(in_stateId) >= 0 && static_cast<int>(in_stateId) < STATE_COUNT && "Invalid Input State");
        return m_states[static_cast<int>(in_stateId)].value;
    }

    void Input::update(int width, int height)
    {
        m_resolution[0] = width;
        m_resolution[1] = height;

        updateInternal();

        for (auto& gamePad : m_gamePads)
        {
            gamePad->update();
        }

        for (auto& joystick : m_joysticks)
        {
            joystick->update();
        }

        memcpy(m_prevStates, m_curStates, sizeof(InputState) * STATE_COUNT);
        memcpy(m_curStates, m_states, sizeof(InputState) * STATE_COUNT);
        memcpy(m_states, m_statesRestore, sizeof(InputState) * STATE_COUNT);

        if (m_fpsMouse)
        {
            mouseDelta[0] = mousePos[0] - m_resolution[0] / 2;
            mouseDelta[1] = mousePos[1] - m_resolution[1] / 2;
            setMousePos(m_resolution[0] / 2, m_resolution[1] / 2);
        }
        else
        {
            mouseDelta[0] = 0;
            mouseDelta[1] = 0;
        }

        ++m_frameId;
        m_lastDoubleClicked = m_doubleClicked;
        m_doubleClicked = false;
    }

    GamePad *Input::getGamePad(int index) const
    {
        if (index < 0 || index >= 4) return nullptr;
        return m_gamePads[index];
    }

    Joystick *Input::getJoystick(int index) const
    {
        if (index < 0 || index >= (int)m_joysticks.size()) return nullptr;
        return m_joysticks[index];
    }

    int Input::getJoystickCount() const
    {
        return (int)m_joysticks.size();
    }

    bool Input::getDoubleClicked() const
    {
        return m_lastDoubleClicked;
    }

    void Input::onDoubleClicked()
    {
        m_doubleClicked = true;
    }

    void Input::activateJoystick(int index)
    {
        m_joysticks.push_back(Joystick::create(index));
        std::sort(m_joysticks.begin(), m_joysticks.end(), [](Joystick *a, Joystick *b)
        {
            return (int)a->getType() < (int)b->getType();
        });
    }

    void Input::deactivateJoystick(int index)
    {
        for (auto it = m_joysticks.begin(); it != m_joysticks.end(); ++it)
        {
            auto pJoystick = *it;
            if (pJoystick->getIndex() == index)
            {
                m_joysticks.erase(it);
                return;
            }
        }
    }

    void Input::setMouseVisible(bool isCursorVisible)
    {
        if (m_isCursorVisible != isCursorVisible)
        {
            setMouseVisibleInternal(isCursorVisible);
            m_isCursorVisible = isCursorVisible;
        }
    }

    void Input::setFpsMouse(bool fpsMouse)
    {
        if (m_fpsMouse != fpsMouse)
        {
            if (fpsMouse)
            {
                m_mousePosOnFPSStart[0] = mousePos[0];
                m_mousePosOnFPSStart[1] = mousePos[1];
                setMouseVisible(false);
                setMousePos(m_resolution[0] / 2, m_resolution[1] / 2);
                mouseDelta[0] = 0;
                mouseDelta[1] = 0;
            }
            else
            {
                setMouseVisible(true);
                setMousePos(m_mousePosOnFPSStart[0], m_mousePosOnFPSStart[1]);
            }
            m_fpsMouse = fpsMouse;
        }
    }

    void Input::setMouseIcon(const uint8_t *pDataRGBA, int width, int height, int hotSpotX, int hotSpotY)
    {
        setMouseIconInternal(pDataRGBA, width, height, hotSpotX, hotSpotY);
    }

    void Input::unsetMouseIcon()
    {
        unsetMouseIconInternal();
    }

    void Input::setMousePos(int x, int y)
    {
        setMousePosInternal(x, y);
    }
}
