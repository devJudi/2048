#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>

extern sf::Font fontPixel;

class Resources
{
    public:
        Resources();
        virtual ~Resources();

        static void loadFonts();

    protected:

    private:
};

#endif // RESOURCES_H
