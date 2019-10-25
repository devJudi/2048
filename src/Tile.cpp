#include "Tile.h"

Tile::Tile()
{
    this->setSize(sf::Vector2f(136, 136));
    this->setFillColor(sf::Color::Green);

    textValue.setCharacterSize(60);
    textValue.setFillColor(sf::Color::Black);
    textValue.setFont(fontPixel);
}

Tile::~Tile()
{
    //dtor
}

void Tile::updateTile()
{
    this->setFillColor(sf::Color(255-colorMod/(value%1000)*2, 255-(value%1000)*colorMod, value, 255-(value%1000)*colorMod*0.1));
    textValue.setString(std::to_string(value));

    if (value<10)
        textValue.setPosition(sf::Vector2f(this->getPosition().x+60, this->getPosition().y+25));
    else if(value<100)
         textValue.setPosition(sf::Vector2f(this->getPosition().x+55, this->getPosition().y+25));
    else if(value<1000)
         textValue.setPosition(sf::Vector2f(this->getPosition().x+40, this->getPosition().y+25));
    else if(value<10000)
         textValue.setPosition(sf::Vector2f(this->getPosition().x+35, this->getPosition().y+25));
}
