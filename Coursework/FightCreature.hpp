#pragma once

#include "Creature.hpp"
#include "FightCreatureCommand.hpp"
#include "Damage.hpp"
#include <vector>

class FightCreatureCommand;

class FightCreature
{
public:
	enum class FightCreatureState
	{
		NONE = 0,
		LOSE = 1,
		WIN = 2
	};

protected:
	FightCreatureState _state = FightCreatureState::NONE;
	Creature _creature;
	std::vector<FightCreatureCommand*> _commands;

private:
	void action(const int slot);

protected:
	virtual int getSlot() const = 0;
	virtual std::string handle() const = 0;

public:
	FightCreature(const Creature& creature);

	void processState();
	void setState(const FightCreatureState& state);
	FightCreatureState getState() const;

	void addCommand(FightCreatureCommand* const command);
	void printCommands() const;

	Damage getDamage() const;
	void haveDamage(const Damage& damage);

	void action();

	void printInfo() const;
};
