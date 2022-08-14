#pragma once

#include <string>
#include "Game.hpp"


class MenuCommand
{
public:
	virtual std::string handle() const = 0;
	virtual void execute() = 0;
};


class MenuCommandStartGame : public MenuCommand
{
private:
	Game _game;

public:
	MenuCommandStartGame(const Game& game);

	std::string handle() const;
	void execute();
};

class MenuCommandExit : public MenuCommand
{
public:
	MenuCommandExit() = default;

	std::string handle() const;
	void execute();
};