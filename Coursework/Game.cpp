#include "Game.hpp"
#include "TypesFightCreature.hpp"
#include "CreatorFightCreature.hpp"
#include <Windows.h>
#include <iostream>


void Game::preTuning()
{
	const PreTuningGame preTuningGame;
	this->_fight = preTuningGame.createFight();
}

void Game::start()
{
	preTuning();
	while (!this->_fight->isEndedFighting())
	{
		this->_fight->printInfo();
		std::cout << '\n';
		this->_fight->processMove();
		system("cls");
	}

	this->_fight->printResult();
}


FightCreature* PreTuningGame::createFightCreatureBot() const
{
	CreatorFightCreature* const creator = new CreatorFightCreatureBot();

	return creator->execute();
}

void PreTuningGame::addCommandsFightCreatureBot(FightCreature* const fightCreature1,
												FightCreature* const fightCreature2) const
{
	const std::vector<FightCreatureCommand*> commands =
	{
		new FightCreatureCommandHit(fightCreature1, fightCreature2)
	};
	for (const auto command : commands)
	{
		fightCreature1->addCommand(command);
	}
}


FightCreature* PreTuningGame::createFightCreaturePlayer() const
{
	CreatorFightCreature* const creator = new CreatorFightCreaturePlayer();

	return creator->execute();
}

void PreTuningGame::addCommandsFightCreaturePlayer(FightCreature* const fightCreature1,
												   FightCreature* const fightCreature2) const
{
	const std::vector<FightCreatureCommand*> commands =
	{
		new FightCreatureCommandHit(fightCreature1, fightCreature2),
		new FightCreatureCommandSurrender(fightCreature1)
	};
	for (const auto command : commands)
	{
		fightCreature1->addCommand(command);
	}
}


Fight* PreTuningGame::createFight() const
{
	FightCreature* const fightCreature1 = createFightCreaturePlayer();
	FightCreature* const fightCreature2 = createFightCreatureBot();
	addCommandsFightCreaturePlayer(fightCreature1, fightCreature2);
	addCommandsFightCreatureBot(fightCreature2, fightCreature1);

	return new Fight(fightCreature1, fightCreature2);
}
