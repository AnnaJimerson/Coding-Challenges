#pragma once
#include <string>

class NetworkMessage
{
private:
	std::string m_name;
	std::string m_message;
public:
	NetworkMessage(std::string name, std::string message);
	std::string GetName() { return m_name; }
	std::string GetSentMessage() { return m_name + ": " + m_message; }
};

