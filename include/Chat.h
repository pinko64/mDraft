#ifndef CHAT_H
#define CHAT_H
#include <sfml/graphics.hpp>
#include <deque>

#include <iostream>


class Chat
{
    public:
        Chat(sf::RenderWindow &_win);
        sf::RenderWindow &win;



        bool isWriting;
        sf::Font           font;
        void Entered();
        void Escaped();
        void send(sf::String);

        std::deque<sf::String> vStr;
        sf::Text focus;
        std::wstring strFocus;
        sf::RectangleShape area;
        void Loop();

        virtual ~Chat();
    protected:
    private:
};

#endif // CHAT_H
