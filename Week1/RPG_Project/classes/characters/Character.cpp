#include "Character.h"

Character::Character(int in_health, int in_mana, std::vector<Item*> in_commands, std::vector<Item*> in_inventory)
{
	health    = in_health;
	mana	  = in_mana;
	commands  = in_commands;
	inventory = in_inventory;
}

void Character::setHealth(int in_health)
{
}

void Character::setMana(int in_mana)
{
}