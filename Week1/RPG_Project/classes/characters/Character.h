#pragma once
#include <vector>
#include "../inventory/Item.h"

class Character
{
private:
	int maxHealth = 90;
	int maxMana = 90;

	int health = maxHealth;
	int mana = maxMana;

	std::vector<Item*> commands;
	std::vector<Item*> inventory;

public:
	//Constructor
	Character(int in_health, int in_mana, std::vector<Item*> in_commands, std::vector<Item*> in_inventory);

	// Get Functions
	int getHealth() { return health; }
	int getMana() { return mana; }
	std::vector<Item*>& getCommands () { return commands; }
	std::vector<Item*>& getInventory() { return inventory; }
	
	//Set Functions
	void setHealth(int in_health);
	void setMana(int in_mana);
};

