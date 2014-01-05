#include <sfml/graphics.hpp>
#include <sfml/Network.hpp>
#include <iostream>
#include <string>
#include "cubereader.h"
#include "grid.h"
#include "card.h"
#include "server.h"
#include "client.h"
#include "chat.h"

class teststream : public sf::InputStream
{
public:
 teststream(std::string archive){};
 //teststream::~teststream(){};
 bool open(std::string filename){if (m_file)
                                    std::fclose(m_file);

                                    m_file = std::fopen(filename.c_str(), "rb");
                                    return m_file != NULL;

    };

sf::Int64 read(void* data, sf::Int64 size){
                                    if (m_file)
                                        return std::fread(data, 1, static_cast<std::size_t>(size), m_file);
                                    else
                                            return -1;
}
 sf::Int64 seek(sf::Int64 position) {
                                    if (m_file)
                                    {
                                        std::fseek(m_file, static_cast<std::size_t>(position), SEEK_SET);
                                        return tell();
                                    }
                                    else return -1;
 };
 sf::Int64 tell()   {

                    if (m_file) {return std::ftell(m_file);}
                    else return -1;

 };
 sf::Int64 getSize() {if (m_file)
                    {
                        sf::Int64 position = tell();
                        std::fseek(m_file, 0, SEEK_END);
                        sf::Int64 size = tell();
                        seek(position);
                        return size;
                    }
                    else {return -1;}

 };





private:
    std::FILE* m_file{};
};





int main()
{
std::vector<Card> vCards;
 sf::RenderWindow win(sf::VideoMode(1024,768), "M Drafter");
win.setFramerateLimit(120);

Server Srv;
Client Clt;
Chat   Cht(win);


 CubeReader creader;
 vCards=creader.read("plrcube.dec");
 Grid grid(win,vCards,Srv,Cht);

 ///sf::RenderWindow win(sf::VideoMode(1024,768), "M Drafter");
///win.setFramerateLimit(60);


/*
        sf::Http http("http://magiccards.info");
        sf::Http::Request request;
    request.setHttpVersion(1,1);
    request.setMethod(sf::Http::Request::Post);
    request.setField("query","moat");
//                request.setUri("");
                sf::Http::Response response = http.sendRequest(request);
                ///std::cout << response.getBody() << std::endl;

 std::ofstream file("test.http",std::ios::binary);
        file.write(response.getBody().c_str(),response.getBody().size());
        file.close();

*/


/*
///std::ofstream tes("img/gog.jpg",std::ios::binary);
///tes.close();

//    const std::string& bd = response.getBody();
    sf::Image ig;
    //ig.loadFromStream(s);

    //ig.loadFromMemory(bd);
    //std::ofstream
    std::ofstream file("test.jpg", std::ios::binary);
//    file.write(bd.c_str(),bd.size());
    file.close();

   sf::Texture txtr;
   txtr.loadFromFile("test.jpg");
//   txtr.loadFromMemory(&response.getBody(),response.getBody().size());
   sf::Sprite a1;

   a1.setTexture(txtr);
//    std::cout << response.getBody().size() << std::endl;


 while (win.isOpen())
    {
        sf::Event event;
                while (win.pollEvent(event))
                    {
                if (event.type == sf::Event::Closed)
                win.close();
                    }

    win.clear(sf::Color::Cyan);












win.draw(a1);
 win.display();
    }
*/
}
