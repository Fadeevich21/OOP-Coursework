#pragma once

#include "FightCreature.hpp"
#include "Fight.hpp"


class Game
{
private:
	Fight* _fight = nullptr;

private:
	void preTuning();

public:
	Game() = default;

	void start();
};


class PreTuningGame
{
public:
	PreTuningGame() = default;

	Fight* createFight() const;
};