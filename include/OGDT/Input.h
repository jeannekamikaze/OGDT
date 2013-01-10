#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

/*
Class: Input
Handles keyboard and mouse input.
*/
class DECLDIR Input
{
    struct _impl;
    _impl* impl;

    Input (const Input&);
    Input& operator= (const Input&);

public:

    /*
    Enum: code
    Encodes keys and mouse buttons.

    LMB - Left mouse button
    RMB - Right mouse button
    MMB - Middle mouse button
    Space - Space
    Esc - Esc
    F1 - F1
    F2 - F2
    F3 - F3
    F4 - F4
    F5 - F5
    F6 - F6
    F7 - F7
    F8 - F8
    F9 - F9
    F10 - F10
    F11 - F11
    F12 - F12
    F13 - F13
    F14 - F14
    F15 - F15
    F16 - F16
    F17 - F17
    F18 - F18
    F19 - F19
    F20 - F20
    F21 - F21
    F22 - F22
    F23 - F23
    F24 - F24
    F25 - F25
    Up - Up arrow
    Down - Down arrow
    Left - Left arrow
    Right - Right arrow
    LShift - Left shift
    RShift - Right shift
    LCtrl - Left control
    RCtrl - Right control
    LAlt - Left alt
    RAlt - Right alt
    LSuper - Left super
    RSuper - Right super
    Tab - Tab
    Enter - Enter
    Backspace - Backspace
    Insert - Insert
    Del - Delete
    PgUp - Page up
    PgDown - Page down
    Home - Home
    End - End
    KP0 - Keypad 0
    KP1 - Keypad 1
    KP2 - Keypad 2
    KP3 - Keypad 3
    KP4 - Keypad 4
    KP5 - Keypad 5
    KP6 - Keypad 6
    KP7 - Keypad 7
    KP8 - Keypad 8
    KP9 - Keypad 9
    KPDiv - Keypad /
    KPMul - Keypad *
    KPSub - Keypad -
    KPAdd - Keypad +
    KPDecimal - Keypad .
    KPEqual - Keypad equal
    KPEnter - Keypad enter
    KPNumLock - Keypad num lock
    CapsLock - Caps lock
    ScrollLock - Scroll lock
    Pause - Pause
    Menu - Menu
    KeyA - Key A
    KeyB - Key B
    KeyC - Key C
    KeyD - Key D
    KeyE - Key E
    KeyF - Key F
    KeyG - Key G
    KeyH - Key H
    KeyI - Key I
    KeyJ - Key J
    KeyK - Key K
    KeyL - Key L
    KeyM - Key M
    KeyN - Key N
    KeyO - Key O
    KeyP - Key P
    KeyQ - Key Q
    KeyR - Key R
    KeyS - Key S
    KeyT - Key T
    KeyU - Key U
    KeyV - Key V
    KeyW - Key W
    KeyX - Key X
    KeyY - Key Y
    KeyZ - Key Z
    Key0 - Key 0
    Key1 - Key 1
    Key2 - Key 2
    Key3 - Key 3
    Key4 - Key 4
    Key5 - Key 5
    Key6 - Key 6
    Key7 - Key 7
    Key8 - Key 8
    Key9 - Key 9
    */
    enum code
    {
        LMB, RMB, MMB,
        Space, Esc, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
        F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21,
        F22, F23, F24, F25, Key0 = '0', Key1, Key2, Key3, Key4, Key5, Key6,
        Key7, Key8, Key9, KeyA = 'A', KeyB, KeyC, KeyD, KeyE, KeyF, KeyG,
        KeyH, KeyI, KeyJ, KeyK, KeyL, KeyM, KeyN, KeyO, KeyP, KeyQ, KeyR,
        KeyS, KeyT, KeyU, KeyV, KeyW,  KeyX, KeyY, KeyZ, KP0, KP1, KP2, KP3,
        KP4, KP5, KP6, KP7, KP8, KP9, KPDiv, KPMul, KPSub, KPAdd, Up, Down,
        Left, Right, LShift, RShift, LCtrl, RCtrl, LAlt, RAlt, LSuper, RSuper,
        Tab, Enter, Backspace, Insert, Del, PgUp, PgDown, Home, End, KPDecimal,
        KPEqual, KPEnter, KPNumLock, CapsLock, ScrollLock, Pause, Menu
    };

    // Cambiar A y 0 de orden.

    Input ();

    ~Input ();
    
    /*
    Function: poll
    Poll the state of input devices.
    */
    void poll ();

    /*
    Function: isDown
    Return true if the given key or mouse button is down, false otherwise.
    */
    bool isDown (Input::code c) const;

    /*
    Function: getMousePosition
    Return the mouse position.

    Parameters:

    x - Out parameter where the x coordinate is written.
    y - Out parameter where the y coordinate is written.
    */
    void getMousePosition (int& x, int& y) const;

    /*
    Function: setMousePosition
    Set the mouse position.
    */
    void setMousePosition (int x, int y);
};

} // namespace OGDT
