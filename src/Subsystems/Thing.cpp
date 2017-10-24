#include <CANTalon.h>
#include <Subsystems/Thing.h>
#include "RobotMap.h"

// ==========================================================================

Thing::Thing()
:	frc::Subsystem("Thing"),
	_motor()
{
	_motor = RobotMap::motor;
	_motor->SetControlMode(CANSpeedController::kPercentVbus);
}

// ==========================================================================

void Thing::InitDefaultCommand() {
}

// ==========================================================================

void Thing::Set(double value) {
	value = std::max(std::min(value, 1.0), -1.0);
	_motor->Set(value);
}

// ==========================================================================

void Thing::Stop() {
	Set(0);
}

// ==========================================================================
