#pragma once

#include <Commands/Command.h>

// ==========================================================================

class ThingRun : public frc::Command {
public:
	ThingRun();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

// ==========================================================================
