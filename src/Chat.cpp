#include "Chat.h"

Chat::Chat(sf::RenderWindow &_win) :
    win(_win),
    isWriting(0)
{

area.setSize(sf::Vector2f(win.getSize().x / 3, win.getSize().y / 1.5));
area.setPosition(win.getSize().x - area.getSize().x, win.getSize().y - area.getSize().y);
area.setOutlineColor(sf::Color(100,100,100,255));
area.setOutlineThickness(4);
area.setFillColor(sf::Color(100,100,100,50));

font.loadFromFile("font.ttf");
focus.setFont(font);
focus.setPosition(15, win.getSize().y - 50);
focus.setColor(sf::Color::Red);
focus.setString("Press t to start writing chat messages...");

    //ctor
}

Chat::~Chat()
{
    //dtor
}


void Chat::Entered()
{
        send(focus.getString());
        focus.setString("Press t to start writing chat messages...");
        isWriting = 0;
        strFocus.clear();


}

void Chat::Escaped()
{
        focus.setString("Press t to start writing chat messages...");
        isWriting = 0;
        strFocus.clear();
}

void Chat::send(sf::String)
{

}

void Chat::Loop()
{
if (!isWriting){
if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
{
    isWriting = 1;
    focus.setString("");

}
}
if (isWriting)
{
            focus.setString(strFocus);
}








win.draw(area);
win.draw(focus);
}
