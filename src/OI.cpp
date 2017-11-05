#include "OI.h"
#include "Commands/ThingRun.h"
#include "Modules/ControllerHelper.h"

using frc4143::ControllerHelper;

constexpr double AXIS_DEAD_ZONE = 0.15;

// ==========================================================================

OI::OI() {
	auto cmdThingRun = new ThingRun();
	auto btnThingRun = ControllerHelper::GetButton(ControllerHelper::Button::X);
	btnThingRun->WhileHeld(cmdThingRun);
}

// ==========================================================================

double OI::GetXAxis() const {
	auto value = _GetController()->GetX(frc::GenericHID::JoystickHand::kLeftHand);
	return (fabs(value) < AXIS_DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

double OI::GetYAxis() const {
	auto value = _GetController()->GetY(frc::GenericHID::JoystickHand::kLeftHand);
	return (fabs(value) < AXIS_DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

double OI::GetZAxis() const {
	auto value = _GetController()->GetX(frc::GenericHID::JoystickHand::kRightHand);
	return (fabs(value) < AXIS_DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

std::shared_ptr<frc::XboxController> OI::_GetController() {
	static std::shared_ptr<frc::XboxController> _controller;

	if (!_controller) {
		_controller = ControllerHelper::GetController(0);
	}

	return _controller;
}

// ==========================================================================
