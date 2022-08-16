#pragma once
#include "NetworkMessage.h"
class ServerMessage :
    public NetworkMessage
{
private:

public:
    ServerMessage(std::string name);
    std::string GetServerMessage() { return "~ " + GetName() + " IS THE WINNER!~"; }
};

