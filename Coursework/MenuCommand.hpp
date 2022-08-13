#pragma once

#include <string>
#include "Game.hpp"


class MenuCommand
{
public:
	virtual void execute() = 0;

	virtual std::string handle() const = 0;
};


class StartGameMenuCommand : public MenuCommand
{
private:
	Game _game;

public:
	StartGameMenuCommand(const Game& game);

	std::string handle() const;
	void execute();
};

class ExitMenuCommand : public MenuCommand
{
public:
	ExitMenuCommand() = default;

	std::string handle() const;
	void execute();
};