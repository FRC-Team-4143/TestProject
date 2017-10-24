#include "OI.h"
#include <WPILib.h>

constexpr double AXIS_DEAD_ZONE = 0.15;

// ==========================================================================

OI::OI() {
}

// ==========================================================================

double OI::GetX() const {
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
