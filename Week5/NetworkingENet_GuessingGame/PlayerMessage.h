#pragma once
#include "NetworkMessage.h"

class PlayerMessage : public NetworkMessage
{
private:
	int m_guess = 0;


public:
	PlayerMessage(std::string name);
	int GetGuess() { return m_guess; }
	std::string GetGuessMessage() { return GetName() + ": " + std::to_string(m_guess); }

	void SetGuess(int guess);
};

