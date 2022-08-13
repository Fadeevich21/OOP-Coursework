#pragma once

#include "FightCreature.hpp"
#include <string>

class FightCreature;

class FightCreatureCommand
{
public:
	FightCreatureCommand() = default;

	virtual std::string handle() const = 0;
	virtual void execute() = 0;
};

class FightCreatureCommandHit : public FightCreatureCommand
{
private:
	FightCreature* _fightCreature1;
	FightCreature* _fightCreature2;

public:
	FightCreatureCommandHit(FightCreature* lhs, FightCreature* rhs);

	std::string handle() const;
	void execute();
};

class FightCreatureCommandSurrender : public FightCreatureCommand
{
private:
	FightCreature* _fightCreature;

public:
	FightCreatureCommandSurrender(FightCreature* fightCreature);

	std::string handle() const;
	void execute();
};