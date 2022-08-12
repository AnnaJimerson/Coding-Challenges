#include <enet/enet.h>
#include <thread>
#include <string>
#include <iostream>
using namespace std;

ENetAddress address;
ENetHost* client = nullptr;

bool CreateClient()
{
    client = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    return client != nullptr;
}

void ClientChat(std::string name) {
    while (1) {
        std::string message;
        std::getline(std::cin, message);
        
        // Concat name to message
        message = name + ": " + message;

        // Make the message into a char*
        const char* messageSend = message.c_str();

        /* Create a reliable packet of size 7 containing "packet\0" */
        ENetPacket* packet = enet_packet_create(messageSend,
            strlen(messageSend) + 1,
            ENET_PACKET_FLAG_RELIABLE);

        enet_host_broadcast(client, 0, packet);
        //enet_peer_send(event.peer, 0, packet);

        /* One could just use enet_host_service() instead. */
        //enet_host_service();
        enet_host_flush(client);
    }
}

int main(int argc, char** argv)
{
    std::string name;
    std::cout << "Input your name: ";
    std::getline(std::cin, name);

    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        cout << "An error occurred while initializing ENet." << endl;
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);

        
    if (!CreateClient())
    {
        fprintf(stderr,
            "An error occurred while trying to create an ENet client host.\n");
        exit(EXIT_FAILURE);
    }

    ENetAddress address;
    ENetEvent event;
    ENetPeer* peer;
    /* Connect to some.server.net:1234. */
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;
    /* Initiate the connection, allocating the two channels 0 and 1. */
    peer = enet_host_connect(client, &address, 2, 0);
    if (peer == NULL)
    {
        fprintf(stderr,
            "No available peers for initiating an ENet connection.\n");
        exit(EXIT_FAILURE);
    }
    /* Wait up to 5 seconds for the connection attempt to succeed. */
    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        cout << "Connection to 127.0.0.1:1234 succeeded." << endl;
    }
    else
    {
        /* Either the 5 seconds are up or a disconnect event was */
        /* received. Reset the peer in the event the 5 seconds   */
        /* had run out without any significant event.            */
        enet_peer_reset(peer);
        cout << "Connection to 127.0.0.1:1234 failed." << endl;
    }

    // Send messages on another thread
    std::thread ChatThread(ClientChat, name);

    // Ping to server for any messages incoming
    while (1)
    {
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(client, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                cout << "-> " << (char*)event.packet->data << '\t' <<
                    "(Length "
                    << event.packet->dataLength << ")" << std::endl;
                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy(event.packet);
            }
        }
    }

    // Delete client
    if (client != nullptr){
        enet_host_destroy(client);
    }

    // Join threads
    ChatThread.join();

    return EXIT_SUCCESS;
}