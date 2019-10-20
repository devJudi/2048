#ifndef TILES_H
#define TILES_H

#include <SFML/Graphics.hpp>
#include <Resources.h>
#include <string>

extern sf::Font fontPixel;

class Tiles : public sf::Text
{
    public:
        Tiles(unsigned int val, int pos);
        virtual ~Tiles();

        unsigned int value;
        int position;

    protected:

    private:
};

#endif // TILES_H
