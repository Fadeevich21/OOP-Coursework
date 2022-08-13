#include "MenuCreator.hpp"
#include "MenuCommand.hpp"
#include <vector>


MenuCreatorA::MenuCreatorA(const Game game)
    : _game(game)
{
}

Menu MenuCreatorA::createMenu()
{
    Menu menu;
    std::vector<MenuCommand*> commands{new StartGameMenuCommand(this->_game), new ExitMenuCommand()};
    for (size_t i = 0; i < commands.size(); i++)
    {
        menu.addCommand(commands[i]);
    }

    return menu;
}
