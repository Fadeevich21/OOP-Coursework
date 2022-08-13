#include "FightCreature.hpp"
#include <iostream>
#include "GeneratorDamage.hpp"


void FightCreature::action(const int slot)
{
	this->_commands[slot]->execute();
}

FightCreature::FightCreature(const Creature& creature)
	: _creature(creature)
{
}

void FightCreature::processState()
{
	if (this->_creature.getHealth().getValue() == 0)
	{
		setState(FightCreatureState::LOSE);
	}
}

void FightCreature::setState(const FightCreatureState& state)
{
	this->_state = state;
}

FightCreature::FightCreatureState FightCreature::getState() const
{
	return this->_state;
}

void FightCreature::addCommand(FightCreatureCommand* const command)
{
	this->_commands.push_back(command);
}

void FightCreature::printCommands() const
{
	for (size_t i = 0; i < this->_commands.size(); i++)
	{
		std::cout << i << ") " << this->_commands[i]->handle() << ";\n";
	}
}

Damage FightCreature::getDamage() const
{
	GeneratorDamage generator;
	Damage damage = generator.generate(this->_creature.getRangeDamage());

	return damage;
}

void FightCreature::haveDamage(const Damage& damage)
{
	this->_creature.changeNumberOfHealth(-damage.getValue());
}

void FightCreature::action()
{
	const int slot = getSlot();
	action(slot);
}

void FightCreature::printInfo() const
{
	std::cout << handle() << '\n' << this->_creature.getInfo() << '\n';
}
