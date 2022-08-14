#include "MenuCreator.hpp"
#include "MenuCommand.hpp"
#include <vector>


MenuCreatorA::MenuCreatorA(const Game& game)
	: _game(game)
{
}

Menu MenuCreatorA::execute() const
{
	Menu menu;
	const std::vector<MenuCommand*> commands =
	{
		new MenuCommandStartGame(this->_game),
		new MenuCommandExit()
	};

	for (const auto command : commands)
	{
		menu.addCommand(command);
	}

	return menu;
}
