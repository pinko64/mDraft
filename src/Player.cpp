#include "Player.h"

Player::Player()

{
    //ctor
}

Player::~Player()
{
    //dtor
}



void Player::addCard(Card &_Card)
{

    Cards.push_back(_Card.Name);
    std::cout << "pushed back : " << _Card.Name << std::endl;


}
