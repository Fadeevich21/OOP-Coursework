#include "Menu.hpp"
#include <iostream>
#include <Windows.h>


void Menu::addCommand(MenuCommand* const command)
{
	this->_commands.push_back(command);
}

void Menu::printCommands() const
{
	for (int i = 0; i < this->_commands.size(); i++)
	{
		std::cout << i << ") " << this->_commands[i]->handle() << ";\n";
	}
}

void Menu::action()
{
	int slot;
	do
	{
		std::cout << "Select command:\n";
		printCommands();
		std::cin >> slot;
		
		system("cls");
	}
	while (slot >= this->_commands.size());

	action(slot);
}

void Menu::action(const int slot)
{
	this->_commands[slot]->execute();
}
