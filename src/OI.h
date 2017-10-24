#pragma once

#include <WPILib.h>

// ==========================================================================

class OI {
public:
	OI();

	double GetX() const;

private:
	static frc::XboxController& _GetController();
};

// ==========================================================================
