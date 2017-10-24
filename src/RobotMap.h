#pragma once

#include <WPILib.h>
#include <CANTalon.h>

// ==========================================================================

class RobotMap {
public:
	static void Initialize();

	static std::shared_ptr<CANTalon> motor;
};

// ==========================================================================
