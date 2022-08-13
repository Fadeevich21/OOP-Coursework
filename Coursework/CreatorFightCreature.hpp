#pragma once

#include "FightCreature.hpp"
#include "Range.hpp"

class CreatorFightCreature
{
protected:
	static const Range _rangeHealth;
	static const Range _rangeDamage;

public:
	virtual FightCreature* execute() = 0;
};

class CreatorFightCreatureBot : public CreatorFightCreature
{
public:
	CreatorFightCreatureBot() = default;

	FightCreature* execute();
};

class CreatorFightCreaturePlayer : public CreatorFightCreature
{
public:
	CreatorFightCreaturePlayer() = default;

	FightCreature* execute();
};