#include "Card.h"

Card::Card(std::string _name) :
    Name(_name),
    isFlagged(0)
{



    //ctor
}

Card::~Card()
{
    //dtor
}

void Card::setFlag(bool _b)
{
    isFlagged = _b;
}

bool Card::getFlag()
{
    return isFlagged;
}
