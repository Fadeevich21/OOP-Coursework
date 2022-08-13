#pragma once

#include "FightCreature.hpp"
#include "Move.hpp"


class Fight
{
public:
	enum class GameState
	{
		IS_OVER_GAME = 0,
		IS_NOT_OVER_GAME = 1,
	};

private:
	GameState _gameState = GameState::IS_NOT_OVER_GAME;
	FightCreature* _fightCreature1;
	FightCreature* _fightCreature2;
	Move _move;

public:
	Fight(FightCreature* const lhs, FightCreature* const rhs);

	bool isEndedFighting() const;

	void setGameState(const GameState& gameState);
	void processGameState();
	
	void changeFightCreatureMove();
	void processMove();

	void printInfo() const;
	void printResult() const;
};
