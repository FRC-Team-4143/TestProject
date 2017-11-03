#include "ControllerHelper.h"

using frc4143::ControllerHelper;

// ==========================================================================

std::shared_ptr<frc::JoystickButton> ControllerHelper::GetButton(ControllerHelper::Button button, int port) {
	auto buttonNumber = static_cast<int>(button);
	return GetButton(port, buttonNumber);
}

// ==========================================================================

std::shared_ptr<frc::JoystickButton> ControllerHelper::GetButton(int buttonNumber, int port) {
	auto cab = _GetControllerAndButtons(port);
	auto buttons = cab->second;
	auto i = buttons->find(buttonNumber);
	if (i != buttons->end()) {
		return (*i).second;
	}

	auto c = cab->first;
	auto b = std::make_shared<frc::JoystickButton>(c.get(), buttonNumber);
	std::pair<int, std::shared_ptr<frc::JoystickButton>> p(buttonNumber, b);
	buttons->insert(p);
	return b;
}

// ==========================================================================

std::shared_ptr<frc::XboxController> ControllerHelper::GetController(int port) {
	return _GetControllerAndButtons(port)->first;
}

// ==========================================================================

std::shared_ptr<ControllerHelper::ControllerAndButtons> ControllerHelper::_GetControllerAndButtons(int port) {
	auto i = m_controllers.find(port);
	if (i != m_controllers.end()) {
		return (*i).second;
	}

	auto c = std::make_shared<frc::XboxController>(port);
	auto cab = std::make_shared<ControllerAndButtons>(c, std::make_shared<ButtonMap>());
	std::pair<int, std::shared_ptr<ControllerAndButtons>> p(port, cab);
	m_controllers.insert(p);
	return cab;
}

// ==========================================================================

ControllerHelper::ControllerMap ControllerHelper::m_controllers;

// ==========================================================================
