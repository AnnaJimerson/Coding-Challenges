#pragma once
#include "Character.h"
class Player :
    public Character
{
private:

public:
    Player(int in_health, int in_mana, std::vector<Item*> in_commands, std::vector<Item*> in_inventory);
};

