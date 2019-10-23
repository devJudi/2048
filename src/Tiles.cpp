#include "Tiles.h"

Tiles::Tiles(unsigned int val, int pos)
{
    if(pos>=0&&pos<16) position = pos;
    else position = 99;

    value = val;
}

Tiles::~Tiles()
{
    //dtor
}

void Tiles::updateTile(sf::Text &text)
{
    Resources::loadFonts();
    text.setFont(fontPixel);
    text.setCharacterSize(50);
    text.setString(std::to_string(value));
    text.setPosition(sf::Vector2f(50+(position%4)*140, 175+(position/4)*140));
    text.setFillColor(sf::Color::Black);
}
