#pragma once

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <CANTalon.h>

// ==========================================================================

class Thing : public frc::Subsystem {
public:
	Thing();

	// Subsystem methods
	virtual void InitDefaultCommand() override;

	void Set(double value); // -1.0 to 1.0
	void Stop();

protected:

private:
	std::shared_ptr<CANTalon> _motor;
};

// ==========================================================================
