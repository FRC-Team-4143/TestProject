#include <Commands/ThingRun.h>
#include "Robot.h"

// ==========================================================================

ThingRun::ThingRun() {
	//Requires(Robot::thing.get());
}

// ==========================================================================

void ThingRun::Initialize() {
}

// ==========================================================================

void ThingRun::Execute() {
	Robot::thing->Set(Robot::oi->GetX());
}

// ==========================================================================

bool ThingRun::IsFinished() {
	return false;
}

// ==========================================================================

void ThingRun::End() {
	Robot::thing->Stop();
}

// ==========================================================================

void ThingRun::Interrupted() {
	End();
}

// ==========================================================================