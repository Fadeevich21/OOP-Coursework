#pragma once

#include "FightCreature.hpp"


class CreatorFightCreature
{
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