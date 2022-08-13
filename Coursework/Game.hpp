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
	Game();

	void start();
};


class PreTuningGame
{
private:
	FightCreature* createFightCreatureBot() const;
	void addCommandsFightCreatureBot(FightCreature* const fightCreature1, FightCreature* const fightCreature2) const;

	FightCreature* createFightCreaturePlayer() const;
	void addCommandsFightCreaturePlayer(FightCreature* const fightCreature1, FightCreature* const fightCreature2) const;

public:
	PreTuningGame() = default;

	Fight* createFight();
};