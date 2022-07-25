#pragma once
class Item
{
private:
	int potency = 0;
	class Character* Owner;

public:
	Item();
	virtual void OnItemUsed();
};

