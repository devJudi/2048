#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "TileField.h"
#include "Tiles.h"
#include "Resources.h"

using namespace std;

int numberOfTiles = 0;

sf::Font fontPixel;

int main()
{
    MainWindow window(600, 700, "2048:re");

    unsigned int currentTilesValues[16] = {0};

    std::vector <Tiles> tiles;
    std::vector <sf::Text> tilesText;

    TileField tileFields[16];
    for(int i = 0; i<16; i++)
    {
        tileFields[i].setPosition(20+(i%4)*140, 125+(i/4)*140);
    }
    TileField scoreField;
    scoreField.setSize(sf::Vector2f(580, 100));
    scoreField.setPosition(10, 10);
    scoreField.setOutlineThickness(0);
    scoreField.setOutlineColor(sf::Color::Green);
    scoreField.setFillColor(sf::Color(255, 255, 180, 255));

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, currentTilesValues, tiles, tilesText);

        window.clear(sf::Color(255, 255, 220, 0));
        for(int i = 0; i<16; i++)
        {
            window.draw(tileFields[i]);
        }
        window.draw(scoreField);
        for(int i = numberOfTiles; i>0; i--)
        {
            tiles[numberOfTiles-1].updateTile(tilesText[numberOfTiles-1]);
            window.draw(tilesText[numberOfTiles-1]);
        }
        window.display();
    }
    return 0;
}
