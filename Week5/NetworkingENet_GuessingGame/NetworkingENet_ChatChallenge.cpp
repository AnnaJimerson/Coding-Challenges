#include <enet/enet.h>
#include <iostream>
#include <thread>
#include <string>
#include "PlayerMessage.h"

using namespace std;

ENetAddress address;
ENetHost* server = nullptr;

bool CreateServer()
{
    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */
    address.host = ENET_HOST_ANY;
    /* Bind the server to port 1234. */
    address.port = 1234;
    server = enet_host_create(&address /* the address to bind the server host to */,
        32      /* allow up to 32 clients and/or outgoing connections */,
        2      /* allow up to 2 channels to be used, 0 and 1 */,
        0      /* assume any amount of incoming bandwidth */,
        0      /* assume any amount of outgoing bandwidth */);

    return server != nullptr;
}

// For broadcasting the winning player to each client
void ServerWinnerMessage(PlayerMessage* winner) {
    if (!winner) {
        std::cout << "WINNER IS NULL!" << std::endl;
        return;
    }

    // Concat name to message
    std::string message = "~ " + winner->GetName() + " is the WINNER!";

    // Make the message into a char*
    const char* messageSend = message.c_str();

    /* Create a reliable packet of size 7 containing "packet\0" */
    ENetPacket* packet = enet_packet_create(messageSend,
        strlen(messageSend) + 1,
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(server, 0, packet);
    //enet_peer_send(event.peer, 0, packet);

    /* One could just use enet_host_service() instead. */
    //enet_host_service();
    enet_host_flush(server);
}

int main(int argc, char** argv)
{
    // Have a random number for players to guess
    srand(time(nullptr));
    int answerNumber = rand() % 10 + 1;

    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        cout << "An error occurred while initializing ENet." << endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

    if (!CreateServer())
    {
        fprintf(stderr,
            "An error occurred while trying to create an ENet server host.\n");
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Server creation successful!" << std::endl;
    }

    // Ping to recieve messages
    while (1)
    {
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(server, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "A new player connected from "
                    << event.peer->address.host
                    << ":" << event.peer->address.port
                    << endl;
                /* Store any relevant client information here. */
                event.peer->data = (void*)("Client information");

                break;
            case ENET_EVENT_TYPE_RECEIVE:
            {
                //NetworkMessage* IncomingPacket = (NetworkMessage*)event.packet->data;

                // Cast packet to player message
                PlayerMessage* PlayerPacket = (PlayerMessage*)event.packet->data;
                
                // Print message from packet
                cout << "-> " << PlayerPacket->GetGuessMessage() << std::endl;

                // If their answer is correct
                if (PlayerPacket->GetGuess() == answerNumber) {
                    ServerWinnerMessage(PlayerPacket);
                }
            }

                //<< "was received from " << (char*)event.peer->data
                //<< " on channel " << event.channelID << endl;
            /* Clean up the packet now that we're done using it. */
                enet_packet_destroy(event.packet);

                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << (char*)event.peer->data << "disconnected." << endl;
                /* Reset the peer's client information. */
                event.peer->data = NULL;
            }
        }
    }

    if (server != nullptr)
    {
        enet_host_destroy(server);
    }


    return EXIT_SUCCESS;
}