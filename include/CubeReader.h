#ifndef CUBEREADER_H
#define CUBEREADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "fetcher.h"
#include "card.h"

class CubeReader
{
    public:
        CubeReader();
        Fetcher           fetcher;
        std::vector<Card> read(std::string filename);
        std::string       cubename;
        std::vector<Card> vCard;



        virtual ~CubeReader();
    protected:
    private:
};

#endif // CUBEREADER_H
