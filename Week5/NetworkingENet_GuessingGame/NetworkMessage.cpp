#include "NetworkMessage.h"

NetworkMessage::NetworkMessage(std::string name, std::string message) :
	m_name(name),
	m_message(message)
{
}

void NetworkMessage::SetName(std::string name)
{
	m_name = name;
}
