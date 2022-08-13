#pragma once

#include "FightCreature.hpp"


class Move
{
private:
	FightCreature* _fightCreature;

public:
	Move(FightCreature* const fightCreature);

	void setFightCreature(FightCreature* const fightCreature);
	FightCreature* getFightCreature();

	void execute();
};

