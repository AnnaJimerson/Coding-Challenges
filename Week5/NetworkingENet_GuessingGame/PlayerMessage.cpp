#include "PlayerMessage.h"

PlayerMessage::PlayerMessage(std::string name) :
	NetworkMessage(name, " ")
{
}

void PlayerMessage::SetGuess(int guess)
{
	m_guess = guess;
}
