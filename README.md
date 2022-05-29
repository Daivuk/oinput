# oinput
Stands for "onut input". Orignally made into the OakNut engine (onut). Handles Keyboard/Mouse using DirectInput or SDL. Handles GamePads and Joysticks

NOTE: Not all files from onut were brought yet. Only those necessary for WIN32. Currently GamePad and Joystick are placeholders. Code not imported yet.

## Usage

```cpp
#include <oinput/Input.h>

...

// Create input system in your initialization code
auto pInput = oinput::Input(yourWindowHandle);

...

// Main loop, check for inputs
if (pInput->isJustDown(OMouse1)) shoot();
if (pInput->isDown(OKeyW)) moveForward();

...

```

## First Person mouse control

Simple call `` to toggle between UI or first person camera control.

```cpp
pInput->setFpsMouse(true);

...

cameraYaw += pInput->mouseDelta[0];
cameraPitch += pInput->mouseDelta[1];

...

// Open in-game menu with Escape key, take back control of the mouse
if (pInput->isJustDown(OKeyEscape))
{
    pInput->setFpsMouse(false);
    ...
}

```
