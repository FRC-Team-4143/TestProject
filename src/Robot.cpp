#include "Robot.h"
#include "RobotMap.h"

// ==========================================================================

std::shared_ptr<OI> Robot::oi;
std::shared_ptr<Thing> Robot::thing;

// ==========================================================================

Robot::Robot()
:	_autonomousCommand() {
}

// ==========================================================================

void Robot::RobotInit() {
	// Initialize controllers and sensors.
	RobotMap::Initialize();

	// Initialize subsystems.

	// Initialize OI.
	oi.reset(new OI());
}

// ==========================================================================

void Robot::RobotPeriodic() {
}

// ==========================================================================

void Robot::DisabledInit() {
}

// ==========================================================================

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

// ==========================================================================

void Robot::AutonomousInit() {
	// TODO - Get autonomous command
	_autonomousCommand.reset(nullptr);

	if (_autonomousCommand) {
		_autonomousCommand->Start();
	}
}

// ==========================================================================

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

// ==========================================================================

void Robot::TeleopInit() {
	if (_autonomousCommand) {
		_autonomousCommand->Cancel();
	}
}

// ==========================================================================

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

// ==========================================================================

void Robot::TestPeriodic() {
	frc::LiveWindow::GetInstance()->Run();
}

// ==========================================================================

START_ROBOT_CLASS(Robot)
