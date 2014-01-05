#ifndef GRID_H
#define GRID_H
#include <sfml/graphics.hpp>
#include <iostream>
#include "card.h"
#include "player.h"
#include "server.h"
#include "chat.h"

class Grid
{
    public:
        Grid(sf::RenderWindow&,std::vector<Card>,Server &_srv, Chat &_chat);
        virtual ~Grid();
            sf::RenderWindow &rWin;


            Chat          &chat;
            Server       &srv;
            Player plr;

            std::vector<Card> &rCards;
            std::vector<sf::IntRect> iRect;

            void Shoot(std::vector<int> &_ints);

            /// Store blabla
            int Current;
            void Allocator();



            std::vector<int> Friends(int,bool _alt);  ///get friendcards...
            void ResizeSprites(int);
            void Align();
            bool mouseIsOn();
            void CreateArrows();
            sf::Texture ArrowTexture;
            std::vector<sf::Sprite> sprArrow;
        bool isRunning;
        void GridLoop();
    protected:
    private:
};

#endif // GRID_H
