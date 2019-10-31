#include "TileField.h"

TileField::TileField()
{
    customizeTileField();
}

void TileField::customizeTileField()
{
    this->setSize(sf::Vector2f(140, 140));
    this->setFillColor(sf::Color::White);
    this->setPosition(0, 0);
    this->setOutlineThickness(-1);
    this->setOutlineColor(sf::Color::Black);
}

TileField::~TileField()
{
    //dtor
}
