#include "addons/usbhostshield.h"
#include "storagemanager.h"
#include <XBOXRECV.h>

USB Usb;
XBOXRECV Xbox(&Usb);

bool USBHostShield::available() {
	return true;
}

void USBHostShield::setup() {
	Usb.Init();
}

void USBHostShield::process() {
	Usb.Task();
	if (Xbox.Xbox360Connected[0]) {
		Gamepad *gamepad = Storage::getInstance().GetGamepad();
		gamepad->state.dpad = 0;
		gamepad->state.buttons = 0;
		if (Xbox.getButtonPress(UP, 0)) {
			Xbox.setLedOn(LED1, 0);
			gamepad->state.dpad |= GAMEPAD_MASK_UP;
		}
		if (Xbox.getButtonPress(DOWN, 0)) {
			Xbox.setLedOn(LED4, 0);
			gamepad->state.dpad |= GAMEPAD_MASK_DOWN;
		}
		if (Xbox.getButtonPress(LEFT, 0)) {
			Xbox.setLedOn(LED3, 0);
			gamepad->state.dpad |= GAMEPAD_MASK_LEFT;
		}
		if (Xbox.getButtonPress(RIGHT, 0)) {
			Xbox.setLedOn(LED2, 0);
			gamepad->state.dpad |= GAMEPAD_MASK_RIGHT;
		}
		if (Xbox.getButtonPress(A, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_B1;
		}
		if (Xbox.getButtonPress(B, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_B2;
		}
		if (Xbox.getButtonPress(X, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_B3;
		}
		if (Xbox.getButtonPress(Y, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_B4;
		}
		if (Xbox.getButtonPress(LB, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_L1;
		}
		if (Xbox.getButtonPress(RB, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_R1;
		}
		if (Xbox.getButtonPress(LT, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_L2;
		}
		if (Xbox.getButtonPress(RT, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_R2;
		}
		if (Xbox.getButtonPress(BACK, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_S1;
		}
		if (Xbox.getButtonPress(START, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_S2;
		}
		if (Xbox.getButtonPress(L3, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_L3;
		}
		if (Xbox.getButtonPress(R3, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_R3;
		}
		if (Xbox.getButtonPress(XBOX, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_A1;
		}
		if (Xbox.getButtonPress(SYNC, 0)) {
			gamepad->state.buttons |= GAMEPAD_MASK_A2;
		}
	}
}

