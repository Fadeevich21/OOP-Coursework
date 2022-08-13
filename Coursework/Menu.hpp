#pragma once

#include <vector>
#include "MenuCommand.hpp"


class Menu
{
private:
	std::vector<MenuCommand*> _commands;

private:
	void action(const int slot);

public:
	Menu() = default;

	void addCommand(MenuCommand* const command);
	void printCommands() const;

	void action();
};