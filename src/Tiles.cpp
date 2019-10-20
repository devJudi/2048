#include "Tiles.h"

Tiles::Tiles(unsigned int val, int pos)
{
    this->setFont(fontPixel);
    this->setString(std::to_string(val));
    this->setCharacterSize(30);

    if(pos>=0&&pos<16) position = pos;
    else position = 99;

    value = val;
}

Tiles::~Tiles()
{
    //dtor
}
