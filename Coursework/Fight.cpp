#include "Fight.hpp"
#include <iostream>


void processGameStateTwoFightCreatures(FightCreature* const lhs, FightCreature* const rhs)
{
	switch (lhs->getState())
	{
		case FightCreature::FightCreatureState::LOSE:
			rhs->setState(FightCreature::FightCreatureState::WIN);
			break;

		case FightCreature::FightCreatureState::WIN:
			rhs->setState(FightCreature::FightCreatureState::LOSE);
			break;

		default:
			break;
	}
}

bool isGameOver(FightCreature* const lhs, FightCreature* const rhs)
{
	return (lhs ->getState() != FightCreature::FightCreatureState::NONE ||
			rhs->getState() != FightCreature::FightCreatureState::NONE);
}

void Fight::processGameState()
{
	this->_fightCreature1->processState();
	this->_fightCreature2->processState();

	processGameStateTwoFightCreatures(this->_fightCreature1, this->_fightCreature2);
	processGameStateTwoFightCreatures(this->_fightCreature2, this->_fightCreature1);

	if (isGameOver(this->_fightCreature2, this->_fightCreature1))
	{
		this->_gameState = GameState::IS_OVER_GAME;
	}
}


void Fight::changeFightCreatureMove()
{
	FightCreature* const fightCreature = this->_move.getFightCreature();
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
	this->_fightCreature1->printInfo();
	std::cout << "\n";

	this->_fightCreature2->printInfo();
	std::cout << "\n";
}


std::string getStringState(const FightCreature::FightCreatureState& state)
{
	std::string stringState;
	switch (state)
	{
		case FightCreature::FightCreatureState::LOSE:
			stringState = "Lose";
			break;

		case FightCreature::FightCreatureState::WIN:
			stringState = "Win";
			break;
	}

	return stringState;
}

void printResultFightCreature(FightCreature* fightCreature)
{
	const FightCreature::FightCreatureState state = fightCreature->getState();
	std::string stringState = getStringState(state);

	fightCreature->printInfo();
	std::cout << "Status: " << stringState << '\n';
}

void Fight::printResult() const
{
	printResultFightCreature(this->_fightCreature1);
	std::cout << '\n';

	printResultFightCreature(this->_fightCreature2);
	std::cout << '\n';
}
