// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Confidential and not for redistribution. See LICENSE.txt.
#define _USE_MATH_DEFINES

//#define WINVER 0x0500
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "User32.lib")

#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cstring>
#include <Windows.h>
#include <shellapi.h>


// The only file that needs to be included to use the Myo C++ SDK is myo.hpp.
#include <myo.hpp>

// Classes that inherit from myo::DeviceListener can be used to receive events from Myo devices. DeviceListener
// provides several virtual functions for handling different kinds of events. If you do not override an event, the
// default behavior is to do nothing.

float rollAdd = 0;
float pitchAdd = 0;
float yawAdd = 0;
bool navMode = false;
bool combatMode = false;
bool selectMode = false;
bool cameraMode = false;
void mouse_move(int dx, int dy);
INPUT ip;

//various keypresses to follow
void login() {

	ip.ki.wVk = 'S'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'I'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'L'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'M'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'A'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'R'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'I'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'L'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'L'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'I'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'O'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = 'N'; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.wVk = VK_RETURN; // virtual-key code for the key
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressF2() {

	ip.ki.wVk = 0x71; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressSpace() {

	ip.ki.wVk = VK_SPACE; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressTilde() {

	ip.ki.wVk = 0xC0; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressNum4() {

	ip.ki.wVk = 0x64; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressNum6() {

	ip.ki.wVk = 0x66; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressF() {

	ip.ki.wVk = 0x46; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressD() {

	ip.ki.wVk = 0x44; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressBackslash() {

	ip.ki.wVk = 0xBF; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressW() {

	ip.ki.wVk = 0x57; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressS() {

	ip.ki.wVk = 0x53; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressQ() {

	ip.ki.wVk = 0x51; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressF3() {

	ip.ki.wVk = 0x72; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressF4() {

	ip.ki.wVk = 0x73; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	Sleep(500);

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressUp() {

	ip.ki.wVk = 0x26; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressDown() {

	ip.ki.wVk = 0x28; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void keyPressApos() {

	ip.ki.wVk = 0xDE; // virtual-key code for the key
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
};

void LeftClick()
{
	INPUT input = { 0 };

	// left down 
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &input, sizeof(INPUT));

	// left up
	::ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;

	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &input, sizeof(INPUT));
};

class DataCollector : public myo::DeviceListener {
public:
    DataCollector()
    
    {
    }
    // onOrientationData() is called whenever the Myo device provides its current orientation, which is represented
    // as a unit quaternion.
	void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat)
	{
		// Calculate the normalized quaternion.
		float norm = sqrtf(quat.x() * quat.x() + quat.y() * quat.y() + quat.z() * quat.z() + quat.w() * quat.w());
		myo::Quaternion<float> normalized(quat.x() / norm, quat.y() / norm, quat.z() / norm, quat.w() / norm);
		// Calculate pitch and yaw from the normalized quaternion.
		float pitch = asinf(2.0f * (normalized.w() * normalized.y() - normalized.z() * normalized.x()));
		float yaw = atan2f(2.0f * (normalized.w() * normalized.z() + normalized.x() * normalized.y()),
			1.0f - 2.0f * (normalized.y() * normalized.y() + normalized.z() * normalized.z()));

		// Calculate the change in pitch and yaw since the last update.
		float deltaPitch = pitch - _previousPitch;
		float deltaYaw = yaw - _previousYaw;

		// Calculate the amount by which to move the cursor.
		// The value SENSITIVITY_X and SENSITIVITY_Y control how sensitive the cursor is
		//  to movements made by the Myo in the x- and y-directions, respectively.
		int dx = deltaYaw * SENSITIVITY_X;
		int dy = deltaPitch * SENSITIVITY_Y;


		if (cameraMode) {

			// Actually move the cursor.
			POINT cursorPos;
			bool result = GetCursorPos(&cursorPos);
			SetCursorPos(cursorPos.x - dx, cursorPos.y - dy);
		}

		// Store the new pitch and yaw values for next time.
		_previousPitch = pitch;
		_previousYaw = yaw;
	}

    // onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
    // making a fist, or not making a fist anymore.
    void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
    {
		// Set up a generic keyboard event.
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0; // hardware scan code for key
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		ip.ki.dwFlags = 0;

		//default controls
		INPUT input = { 0 };

		if (pose == myo::Pose::fist) {
			login(); //enter password, hit return
			myo->vibrate(myo::Myo::VibrationShort);

		}


    }

	private:
		static const int SENSITIVITY_X = 300; // x-axis (left/right) sensitivity
		static const int SENSITIVITY_Y = 300; // y-axis (up/down) sensitivity

		float _previousPitch;
		float _previousYaw;
};

int main(int argc, char** argv)
{
    // We catch any exceptions that might occur below -- see the catch statement for more details.
    try {

    // First, we create a Hub. The Hub provides access to one or more Myos.
    myo::Hub hub;

    std::cout << "Attempting to find a Myo..." << std::endl;

    // Next, we try to find a Myo (any Myo) that's nearby and connect to it. waitForAnyMyo() takes a timeout
    // value in milliseconds. In this case we will try to find a Myo for 10 seconds, and if that fails, the function
    // will return a null pointer.
    myo::Myo* myo = hub.waitForAnyMyo(10000);

    // If waitForAnyMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
    if (!myo) {
        throw std::runtime_error("Unable to find a Myo!");
    }

    // We've found a Myo, let's output its MAC address.
    std::cout << "Connected to " << myo->macAddressAsString() << "." << std::endl << std::endl;

    // Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
    DataCollector collector;

    // Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
    // Hub::run() to send events to all registered device listeners.
    hub.addListener(&collector);

	while (1) {
		// In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
		// In this case, we wish to update our display 20 times a second, so we run for 1000/20 milliseconds.
		hub.run(1000 / 20);
		// After processing events, we call the print() member function we defined above to print out the values we've
		// obtained from any events that have occurred.

	}

    // If a standard exception occurred, we print out its message and exit.
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Press enter to continue.";
        std::cin.ignore();
        return 1;
    }
}
