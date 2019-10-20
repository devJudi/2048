#include "Resources.h"

Resources::Resources()
{
    //ctor
}

Resources::~Resources()
{
    //dtor
}

void Resources::loadFonts()
{
    fontPixel.loadFromFile("fonts/pixelFont.ttf");
}
