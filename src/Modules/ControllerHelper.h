#pragma once
#include <unordered_map>
#include <memory>
#include <Buttons/JoystickButton.h>
#include <XboxController.h>

// ==========================================================================

namespace frc4143 {

class ControllerHelper {
public:

	ControllerHelper() = delete; // cannot create an instance of this class

	enum class Axis : int {
		LeftX = 0,
		LeftY = 1,
		LeftTrigger = 2,
		RightTrigger = 3,
		RightX = 4,
		RightY = 5
	};

	enum class Button : int {
		A = 1,
		B = 2,
		X = 3,
		Y = 4,
		LeftBumper = 5,
		ReftBumper = 6,
		Back = 7,
		Start = 8,
		LeftStick = 9,
		RightStick = 10
	};

	static std::shared_ptr<frc::JoystickButton> GetButton(Button button, int port = 0);
	static std::shared_ptr<frc::JoystickButton> GetButton(int buttonNumber, int port = 0);
	static std::shared_ptr<frc::XboxController> GetController(int port);

protected:

	typedef std::unordered_map<int, std::shared_ptr<frc::JoystickButton>> ButtonMap;
	typedef std::pair<std::shared_ptr<frc::XboxController>, std::shared_ptr<ButtonMap>> ControllerAndButtons;
	typedef std::unordered_map<int, std::shared_ptr<ControllerAndButtons>> ControllerMap;

	static std::shared_ptr<ControllerAndButtons> _GetControllerAndButtons(int port);

private:

	static ControllerMap m_controllers;
};

} // END namespace

// ==========================================================================
