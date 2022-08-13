#include "Menu.hpp"
#include "MenuCreator.hpp"
#include "Game.hpp"
#include <ctime>

int main()
{
	srand(time(nullptr));

	MenuCreator* menuCreator = new MenuCreatorA(Game());
	Menu menu = menuCreator->createMenu();
	menu.action();

	return 0;
}