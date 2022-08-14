#include "MenuCommand.hpp"


MenuCommandStartGame::MenuCommandStartGame(const Game& game)
	: _game(game)
{
}

void MenuCommandStartGame::execute()
{
	this->_game.start();
}

std::string MenuCommandStartGame::handle() const
{
	return "Start game";
}


#include <Windows.h>

std::string MenuCommandExit::handle() const
{
	return "Exit";
}

void MenuCommandExit::execute()
{
}
