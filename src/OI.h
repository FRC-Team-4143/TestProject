#pragma once
#include <memory>
#include <WPILib.h>

// ==========================================================================

class OI {
public:

	OI();

	double GetXAxis() const;
	double GetYAxis() const;
	double GetZAxis() const;

private:

	static std::shared_ptr<frc::XboxController> _GetController();
};

// ==========================================================================
