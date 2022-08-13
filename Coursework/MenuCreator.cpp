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
		new StartGameMenuCommand(this->_game),
		new ExitMenuCommand()
	};

	for (const auto command : commands)
	{
		menu.addCommand(command);
	}

	return menu;
}
