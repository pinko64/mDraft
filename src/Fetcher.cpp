#include "Fetcher.h"

Fetcher::Fetcher() :
    http("http://mtgimage.com")
{

    request.setHttpVersion(1,1);
    request.setMethod(sf::Http::Request::Get);

}

Fetcher::~Fetcher()
{
    //dtor
}


long Fetcher::GetSize(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}


void Fetcher::Fetch(std::string _name)
{



                request.setUri("/card/"+_name+".jpg");
                ///std::cout << GetSize("img/"+_name+".jpg") << std::endl;
                ///std::cout << "testname : " << _name << std::endl;
                std::ifstream exists("img/"+_name+".jpg");
                ///std::ifstream exists2("img/"+_name+".jpg");
                if (!exists.good() || GetSize("img/"+_name+".jpg") == 0)
                {
                sf::Http::Response response = http.sendRequest(request);
                if  (response.getStatus() != 200)
                    std::cout << response.getStatus() << "     "   << _name << ".jpg" << std::endl;

        std::ofstream file("img/"+_name+".jpg",std::ios::binary);
        file.write(response.getBody().c_str(),response.getBody().size());
        file.close();
        //std::cout << "should be closed" << std::endl;

                }}
/*
    const std::string& bd = response.getBody();
    sf::Image ig;
    //ig.loadFromStream(s);

    //ig.loadFromMemory(bd);
    //std::ofstream
    std::ofstream file("test.jpg", std::ios::binary);
    file.write(bd.c_str(),bd.size());
    file.close();

   sf::Texture txtr;
   txtr.loadFromFile("test.jpg");
   txtr.loadFromMemory(&response.getBody(),response.getBody().size());
   sf::Sprite a1;

   a1.setTexture(txtr);
    std::cout << response.getBody().size() << std::endl;
    */
