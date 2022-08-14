#include "Menu.hpp"
#include "MenuCreator.hpp"
#include "Game.hpp"
#include <ctime>

int main()
{
	srand(time(nullptr));

	MenuCreator* menuCreator = new MenuCreatorA(Game());
	Menu menu = menuCreator->execute();
	menu.action();

	system("pause");
	
	return 0;
}