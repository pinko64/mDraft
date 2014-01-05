#include "Server.h"

Server::Server()
{
    listener.setBlocking(0);
    if (listener.listen(55000) != sf::Socket::Done)
    {
        std::cout << "error connecting listener socket to 55000" << std::endl;
    };

    if (listener.accept(client) != sf::Socket::Done)
    {
     //std::cout << "some other error" << std::endl;
    }


    //ctor
}

Server::~Server()
{
    //dtor
}

void Server::Loop()
{
//listener.setBlocking(0);
  //  if (listener.listen(55000) != sf::Socket::Done)
    ////  std::cout << "error connecting listener socket to 55000" << std::endl;
    //};

    if (listener.accept(client) != sf::Socket::Done)
    {
     //std::cout << "some other error" << std::endl;
    }
    std::cout << client.getRemoteAddress() << std::endl;

    sf::Packet packet;
    client.receive(packet);
    std::string s;
    if (packet >> s)
    {
        std::cout << s << std::endl;
    }


}
