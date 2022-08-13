#include "MenuCommand.hpp"


StartGameMenuCommand::StartGameMenuCommand(const Game& game)
	: _game(game)
{
}

void StartGameMenuCommand::execute()
{
	this->_game.start();
}

std::string StartGameMenuCommand::handle() const
{
	return "Start game";
}


#include <Windows.h>

std::string ExitMenuCommand::handle() const
{
	return "Exit";
}

void ExitMenuCommand::execute()
{
}
