#ifndef SERVER_H
#define SERVER_H
#include <sfml/network.hpp>
#include <iostream>
class Server
{
    public:
        Server();
        sf::TcpSocket socket;
        sf::TcpSocket client;
        sf::TcpListener listener;

        void Loop();


        virtual ~Server();
    protected:
    private:
};

#endif // SERVER_H
