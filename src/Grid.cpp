#include "Grid.h"

Grid::Grid(sf::RenderWindow& _rWin,std::vector<Card> _rCards, Server &_srv,  Chat &_chat) :
    rWin(_rWin),
    rCards(_rCards),
    srv(_srv),
    chat(_chat),
    isRunning(1),
    Current(0)
{

    ArrowTexture.loadFromFile("arrow.gif");

    sf::Sprite spArr;
    for (int i = 0; i < 6; i++){
    spArr.setTexture(ArrowTexture);
    sprArrow.push_back(spArr);}
    //sprArrow.setTexture(ArrowTexture);

    GridLoop();

    //ctor
}



bool mouseIsOn()
{




}

void Grid::Shoot(std::vector<int> &_ints)
{
std::cout << "cards size = " << rCards.size() << std::endl;
std::cout << _ints[0] << _ints[1] <<  _ints[2]  << std::endl;


///std::swap(rCards[0],rCards[Current]);

for (int i = 0; i < 3; i++)
{

    //std::cout << "Erasing: " << rCards[_ints[i]].Name << std::endl;
   ///) rCards.erase(rCards.begin() +_ints[i]);
    std::swap(rCards[_ints[i]],rCards[Current]);
    plr.addCard(rCards[Current]);
    Current++;


}


ResizeSprites(15);

}



Grid::~Grid()
{
    //dtor
}

void Grid::ResizeSprites(int _px){
for (int i = 0; i < 9; i++)
{
    /*
    rCards[i].CardTexture.loadFromFile("img/" + rCards[i].Name + ".jpg");
    rCards[i].CardSprite.setTexture(rCards[i].CardTexture);
    rCards[i].CardSprite.setScale(rCards[i].CardSprite.getScale().x,25);
    rCards[i].CardSprite.setPosition(25,25);
    std::cout << rCards[i].Name << std::endl;*/
    rCards[i].CardTexture.loadFromFile("img/" + rCards[i].Name + ".jpg");
    rCards[i].CardTexture.setSmooth(1);
    rCards[i].Shape.setTexture(&rCards[i].CardTexture);

    rCards[i].Shape.setSize(sf::Vector2f(150,200));
// 300 400
    //rCards[i].CardSprite.setTexture(rCards[i].CardTexture);
}

Align();
}

void Grid::Align()
{
iRect.clear();
int Off = 0;
int Y = 0;
int X = 0;
for (int i = 0; i < 9; i++)
{
    rCards[i].Shape.setPosition(sf::Vector2f(X*rCards[i].Shape.getSize().x ,   Y ));
    sf::IntRect Rect = sf::IntRect(rCards[i].Shape.getPosition().x,   rCards[i].Shape.getPosition().y,   rCards[i].Shape.getSize().x,    rCards[i].Shape.getSize().y);
    X++;
    if (i == 2)
        {
            Y += rCards[i].Shape.getSize().y;
            X = 0;
        }
         if (i == 5)
        {
            Y += rCards[i].Shape.getSize().y;
            X = 0;
        }
///    std::cout << rCards[i].Shape.getPosition().x << "    "  << rCards[i].Shape.getPosition().y <<  std::endl;
    //sf::IntRect Rect = sf::IntRect(rCards[i].Shape.getPosition().x,   rCards[i].Shape.getPosition().x,   rCards[i].Shape.getSize().x,    rCards[i].Shape.getSize().y);

        iRect.push_back(Rect);
        Current++;
       /// std::cout << Rect.left << "   " << Rect.top << "   " << Rect.width << "   " << Rect.height << std::endl;

    //rCards[i].Shape.setPosition(sf::Vector2f(0,15));

}
//CreateArrows();
}

std::vector<int> Grid::Friends(int _int, bool _alt)
{
if (!_alt){
if (_int == 0 || _int == 1 || _int == 2)
    {
        std::vector<int> ints;
        ints.push_back(0);ints.push_back(1);ints.push_back(2);
        return ints;




    }
if (_int == 3 || _int == 4 || _int == 5)
    {
        std::vector<int> ints;
        ints.push_back(3);ints.push_back(4);ints.push_back(5);
        return ints;
    }
if (_int == 6 || _int == 7 || _int == 8)
{
        std::vector<int>  ints;
        ints.push_back(6);ints.push_back(7);ints.push_back(8);
        return ints;
}
}



else if (_alt){
if (_int == 0 || _int == 3 || _int == 6)
    {
        std::vector<int> ints;
        ints.push_back(0);ints.push_back(3);ints.push_back(6);
        return ints;

    }
if (_int == 1 || _int == 4 || _int == 7)
    {
        std::vector<int> ints;
        ints.push_back(1);ints.push_back(4);ints.push_back(7);
        return ints;
    }
if (_int == 2 || _int == 5 || _int == 8)
{
        std::vector<int>  ints;
        ints.push_back(2);ints.push_back(5);ints.push_back(8);
        return ints;
}
}}






void Grid::CreateArrows()
{
int Off = 50;
int Y = rCards[0].Shape.getSize().y / 2;

int X = 0;
    for (int i = 0; i < sprArrow.size(); i++)
    {
        if (i < 3)
                {
                    sprArrow[i].rotate(90);
                    sprArrow[i].setPosition(sf::Vector2f(  rCards[i].Shape.getPosition().x + rCards[i].Shape.getSize().x / 2,
                                               rCards[i].Shape.getPosition().y - 30 ));
                }
        else
            {

                sprArrow[i].setPosition(sf::Vector2f(  15,
                                                       Y ));
                Y += (rCards[0].Shape.getSize().y  );

        }
    }
}



void Grid::GridLoop(){
ResizeSprites(25);
while (isRunning)
{
sf::Texture r1; r1.loadFromFile("img/" + rCards[3].Name + ".jpg");
sf::RectangleShape rr;rr.setTexture(&rCards[3].CardTexture);
//rr.setSize(sf::Vector2f(59,50));
//rr.setFillColor(sf::Color::Red);


sf::Event event;
                while (rWin.pollEvent(event))
                    {
                if (event.type == sf::Event::Closed)
                {rWin.close();isRunning=0;}


        if (event.type == sf::Event::TextEntered && chat.isWriting)
        {
            if (event.text.unicode < 128)
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                chat.strFocus.push_back(static_cast<wchar_t>(event.text.unicode));
                    else
                        if (chat.strFocus.size() > 0)
                        chat.strFocus.erase(chat.strFocus.size() - 1,1);

        ;
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && chat.isWriting)
    {
        chat.Escaped();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && chat.isWriting)
    {
        chat.Escaped();
    }




rWin.clear(sf::Color::Black);
for (int i = 0; i < 9; i++)
{
    ///rWin.draw(rCards[i].CardSprite);
    rWin.draw(rCards[i].Shape);
}


for (int i = 0; i < iRect.size(); i++)
{


    if (iRect[i].contains(sf::Mouse::getPosition(rWin)) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && !chat.isWriting)
    {
        std::vector<int> Ints;
            Ints = Friends(i,0);

        for (int j = 0; j < Ints.size(); j++)
        {
            rCards[Ints[j]].Shape.setFillColor(sf::Color::Red);

        }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {Shoot(Ints);break;}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                for (int ii = 0; ii < Ints.size(); ii++)
                {
                std::cout << rCards[Ints.at(ii)].Name << std::endl;
                }
             }
        i = Ints.back() + 1;

    }

rCards[i].Shape.setFillColor(sf::Color(255,255,255,255));
}

for (int i = 0; i < iRect.size(); i++){
        if (iRect[i].contains(sf::Mouse::getPosition(rWin)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && !chat.isWriting)
    {
        std::vector<int> Ints;
            Ints = Friends(i,1);

        for (int j = 0; j < Ints.size(); j++)
        {
            rCards[Ints[j]].Shape.setFillColor(sf::Color::Red);

        }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                Shoot(Ints);

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                for (int ii = 0; ii < Ints.size(); ii++)
                {
                std::cout << rCards[Ints.at(ii)].Name << std::endl;
                }
             }


        i = Ints.back() + 1;


    }

//rCards[i].Shape.setFillColor(sf::Color(255,255,255,255));
}





if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{

}


 if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
 {
    for (auto i : plr.Cards)
        std::cout << i << std::endl;
 }



rWin.draw(rr);




srv.Loop();
chat.Loop();

rWin.display();
}}}
