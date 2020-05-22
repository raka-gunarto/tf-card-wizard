// TF Card Wizard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <thread>

//-- LE MAGICAL CONSTANTS

const int MagicPixelX = 818;
const int MagicPixelY = 968;

const int CardValues[][3] = { { 69, 69, 187 }, { 114, 8, 8 }, { 160, 141, 0 } };
//--

volatile bool KeyChange = false;
int CurrentVKCode = -1;

void TwistedFateWizard() {
    HDC _hdc = GetDC(NULL);
    while (true) {
        if (!KeyChange)
            continue;

        if (CurrentVKCode == 0x4B)
            break;

        KeyChange = false;

        int Card = -1;
        if (CurrentVKCode == 0x31)
            Card = 0;
        else if (CurrentVKCode == 0x32)
            Card = 1;
        else if (CurrentVKCode == 0x33)
            Card = 2;
        else
            continue;

        keybd_event(0x57,
            17,
            0,
            0);

        keybd_event(0x57,
            17,
            KEYEVENTF_KEYUP,
            0);
        
        while (true) {
            COLORREF _color = GetPixel(_hdc, 818, 968);
            int _red = GetRValue(_color);
            int _green = GetGValue(_color);
            int _blue = GetBValue(_color);

            if (_red == CardValues[Card][0] && _green == CardValues[Card][1] && _blue == CardValues[Card][2]) {
                keybd_event(0x57,
                    17,
                    0,
                    0);

                keybd_event(0x57,
                    17,
                    KEYEVENTF_KEYUP,
                    0);
                printf("hit!\n");
                break;
            }
        }
        KeyChange = false;
    }
    ReleaseDC(NULL, _hdc);
}

LRESULT __stdcall KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode < 0 || wParam != WM_KEYDOWN)
		return CallNextHookEx(0, nCode, wParam, lParam);

	int vkCode = ((PKBDLLHOOKSTRUCT)lParam)->vkCode;
    CurrentVKCode = vkCode;
    KeyChange = true;

	return CallNextHookEx(0, nCode, wParam, lParam);
}

int main(int argc, char** argv)
{
    HHOOK KeyboardHookHandle = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, 0, 0);

    std::thread first(TwistedFateWizard);

    MSG msg;
    while (!GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
     
    first.join();
    return 0;
}