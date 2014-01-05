#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <vector>
#include <iostream>
#include <string>

class Player
{
    public:
        Player();
        std::vector<std::string> Cards;
        void            addCard(Card&);
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
