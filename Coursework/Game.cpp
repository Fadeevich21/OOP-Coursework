#include "Game.hpp"
#include "TypesFightCreature.hpp"
#include "CreatorFightCreature.hpp"
#include <Windows.h>


void Game::preTuning()
{
	PreTuningGame preTuningGame;
	this->_fight = preTuningGame.createFight();
}

Game::Game()
{
}

void Game::start()
{
	preTuning();
	while (!this->_fight->isEndedFighting())
	{
		this->_fight->printInfo();
		this->_fight->processMove();
		system("cls");
	}

	this->_fight->printResult();
}

FightCreature* PreTuningGame::createFightCreatureBot() const
{
	CreatorFightCreature* creator = new CreatorFightCreatureBot();

	return creator->execute();
}

void PreTuningGame::addCommandsFightCreatureBot(FightCreature* const fightCreature1,
												FightCreature* const fightCreature2) const
{
	const std::vector<FightCreatureCommand*> commands =
	{
		new FightCreatureCommandHit(fightCreature1, fightCreature2)
	};
	for (auto command : commands)
	{
		fightCreature1->addCommand(command);
	}
}

FightCreature* PreTuningGame::createFightCreaturePlayer() const
{
	CreatorFightCreature* creator = new CreatorFightCreaturePlayer();

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
	for (auto command : commands)
	{
		fightCreature1->addCommand(command);
	}
}

Fight* PreTuningGame::createFight()
{
	FightCreature* fightCreature1 = createFightCreaturePlayer();
	FightCreature* fightCreature2 = createFightCreatureBot();
	addCommandsFightCreaturePlayer(fightCreature1, fightCreature2);
	addCommandsFightCreatureBot(fightCreature2, fightCreature1);

	return new Fight(fightCreature1, fightCreature2);
}
