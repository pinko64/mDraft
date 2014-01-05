#ifndef CARD_H
#define CARD_H
#include <string>
#include <sfml/graphics.hpp>
class Card
{
    public:
        Card(std::string);
            std::string Name;
            sf::Sprite  CardSprite;
            sf::Texture CardTexture;
            sf::RectangleShape Shape;
            void setFlag(bool);
            bool getFlag();

            bool isFlagged;
        virtual ~Card();
    protected:
    private:
};

#endif // CARD_H
