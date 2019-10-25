#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

extern sf::Font fontPixel;

class Tile : public sf::RectangleShape
{
    public:
        Tile();
        virtual ~Tile();
        void updateTile();


        sf::Text textValue;
        int value;

    protected:

    private:
};

#endif // TILE_H
