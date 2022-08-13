#include "Fight.hpp"
#include <iostream>


void Fight::processGameState()
{
	this->_fightCreature1->processState();
	this->_fightCreature2->processState();
	if (this->_fightCreature1->getState() != FightCreature::FightCreatureState::NONE)
	{
		switch (this->_fightCreature1->getState())
		{
			case FightCreature::FightCreatureState::LOSE:
				this->_fightCreature2->setState(FightCreature::FightCreatureState::WIN);
				break;

			case FightCreature::FightCreatureState::WIN:
				this->_fightCreature2->setState(FightCreature::FightCreatureState::LOSE);
				break;

			default:
				break;
		}
	}

	if (this->_fightCreature2->getState() != FightCreature::FightCreatureState::NONE)
	{
		switch (this->_fightCreature2->getState())
		{
			case FightCreature::FightCreatureState::LOSE:
				this->_fightCreature1->setState(FightCreature::FightCreatureState::WIN);
				break;

			case FightCreature::FightCreatureState::WIN:
				this->_fightCreature1->setState(FightCreature::FightCreatureState::LOSE);
				break;

			default:
				break;
		}
	}

	if (this->_fightCreature1->getState() != FightCreature::FightCreatureState::NONE ||
		this->_fightCreature2->getState() != FightCreature::FightCreatureState::NONE)
	{
		this->_gameState = GameState::IS_OVER_GAME;
	}
}

void Fight::changeFightCreatureMove()
{
	FightCreature* fightCreature = this->_move.getFightCreature();
	if (fightCreature == this->_fightCreature1)
	{
		this->_move.setFightCreature(this->_fightCreature2);
	}
	else
	{
		this->_move.setFightCreature(this->_fightCreature1);
	}
}

Fight::Fight(FightCreature* const lhs, FightCreature* const rhs)
	: _fightCreature1(lhs), _fightCreature2(rhs), _move(_fightCreature1)
{
}

void Fight::setGameState(const GameState& gameState)
{
	this->_gameState = gameState;
}

bool Fight::isEndedFighting() const
{
	return this->_gameState == GameState::IS_OVER_GAME;
}

void Fight::processMove()
{
	this->_move.execute();
	changeFightCreatureMove();
	this->processGameState();
}

void Fight::printInfo() const
{
	std::cout << "Creature1: ";
	this->_fightCreature1->printInfo();
	std::cout << "\n";

	std::cout << "Creature2: ";
	this->_fightCreature2->printInfo();
	std::cout << "\n";
}

void printResultFightCreature(FightCreature* fightCreature)
{
	FightCreature::FightCreatureState state = fightCreature->getState();
	fightCreature->printInfo();
	std::cout << "Status: ";
	switch (state)
	{
		case FightCreature::FightCreatureState::LOSE:
			std::cout << "Lose\n";
			break;

		case FightCreature::FightCreatureState::WIN:
			std::cout << "Win\n";
			break;

		default:
			break;
	}
}

void Fight::printResult() const
{
	printResultFightCreature(this->_fightCreature1);
	std::cout << '\n';
	printResultFightCreature(this->_fightCreature2);
}
