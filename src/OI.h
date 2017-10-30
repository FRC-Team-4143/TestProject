#pragma once

#include <WPILib.h>

// ==========================================================================

class OI {
public:
	OI();

	double GetXAxis() const;

private:
	static frc::XboxController& _GetController();
};

// ==========================================================================
