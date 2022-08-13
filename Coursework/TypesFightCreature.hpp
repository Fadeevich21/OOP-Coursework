#pragma once

#include "FightCreature.hpp"


class FightCreatureBot : public FightCreature
{
protected:
	int getSlot() const;

public:
	FightCreatureBot(const Creature& creature);
};

class FightCreaturePlayer : public FightCreature
{
protected:
	int getSlot() const;

public:
	FightCreaturePlayer(const Creature& creature);
};
