#pragma once

#include "Menu.hpp"
#include "Game.hpp"


class MenuCreator
{
public:
	virtual Menu createMenu() = 0;
};

class MenuCreatorA : public MenuCreator
{
private:
	Game _game;

public:
	MenuCreatorA(const Game game);

	Menu createMenu();
};