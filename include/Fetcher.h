#ifndef FETCHER_H
#define FETCHER_H
#include <sfml/network.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

class Fetcher
{
    public:

        Fetcher();
        void Fetch(std::string);


            long GetSize(std::string filename);
        sf::Http  http;
        sf::Http::Request request;
        virtual ~Fetcher();
    protected:
    private:
};

#endif // FETCHER_H
