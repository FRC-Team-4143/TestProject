#pragma once

#include <WPILib.h>
#include "OI.h"
#include "Subsystems/Thing.h"

// ==========================================================================

class Robot : public frc::IterativeRobot {
public:
	static std::shared_ptr<OI> oi;
	static std::shared_ptr<Thing> thing;

	Robot();

	virtual void RobotInit() override;
	virtual void RobotPeriodic() override;
	virtual void DisabledInit() override;
	virtual void DisabledPeriodic() override;
	virtual void AutonomousInit() override;
	virtual void AutonomousPeriodic() override;
	virtual void TeleopInit() override;
	virtual void TeleopPeriodic() override;
	virtual void TestPeriodic() override;

private:
	std::unique_ptr<frc::Command> _autonomousCommand;
};

// ==========================================================================
