#include "OI.h"
#include "Commands/ThingRun.h"

constexpr uint32_t JOYSTICK_LX_AXIS = 0;
constexpr uint32_t JOYSTICK_LY_AXIS = 1;
constexpr uint32_t JOYSTICK_LTRIG_AXIS = 2;
constexpr uint32_t JOYSTICK_RTRIG_AXIS = 3;
constexpr uint32_t JOYSTICK_RX_AXIS = 4;
constexpr uint32_t JOYSTICK_RY_AXIS = 5;

constexpr uint32_t JOYSTICK_BUTTON_A = 1;
constexpr uint32_t JOYSTICK_BUTTON_B = 2;
constexpr uint32_t JOYSTICK_BUTTON_X = 3;
constexpr uint32_t JOYSTICK_BUTTON_Y = 4;
constexpr uint32_t JOYSTICK_BUTTON_LB = 5;
constexpr uint32_t JOYSTICK_BUTTON_RB = 6;
constexpr uint32_t JOYSTICK_BUTTON_BACK = 7;
constexpr uint32_t JOYSTICK_BUTTON_START = 8;
constexpr uint32_t JOYSTICK_BUTTON_LEFT = 9;
constexpr uint32_t JOYSTICK_BUTTON_RIGHT = 10;

constexpr double AXIS_DEAD_ZONE = 0.15;

// ==========================================================================

OI::OI() {
	auto cmdThingRun = new ThingRun();
	auto btnThingRun = new frc::JoystickButton(&_GetController(), JOYSTICK_BUTTON_X);
	btnThingRun->WhileHeld(cmdThingRun);
}

// ==========================================================================

double OI::GetXAxis() const {
	auto value = _GetController().GetX(frc::GenericHID::JoystickHand::kLeftHand);
	return (fabs(value) < AXIS_DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

frc::XboxController& OI::_GetController() {
	static std::unique_ptr<frc::XboxController> _controller;

	if (!_controller) {
		_controller = std::make_unique<frc::XboxController>(0);
	}
	return *_controller;
}

// ==========================================================================
