#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "TileField.h"
#include "Tile.h"
#include "Resources.h"

using namespace std;

std::vector <int> usedTileFields;

int whatIsInThisField[16];
int colorMod;

bool isGameStarted = false;

sf::Font fontPixel;

int main()
{
    srand(time(NULL));
    colorMod=rand()%40+20;

    for(int i = 0; i<16; i++)
    {
        whatIsInThisField[i]=99;
    }

    MainWindow window(600, 700, "2048:re");

    bool isEmpty[16];
    for(int i = 0; i<16; i++)
    {
        isEmpty[i] = true;
    }

    Tile tiles[16];
    Resources::loadFonts();

    TileField tileFields[16];
    for(int i = 0; i<16; i++)
    {
        tileFields[i].setPosition(20+(i%4)*140, 125+(i/4)*140);
        tiles[i].setPosition(22+(i%4)*140, 127+(i/4)*140);
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
        window.handleEvent(event, tiles, isEmpty);

        window.clear(sf::Color(255, 255, 220, 0));
        for(int i = 0; i<16; i++)
        {
            window.draw(tileFields[i]);
        }
        window.draw(scoreField);
        for(int i = 0; i<16; i++)
        {
            if(!isEmpty[i]&&tiles[i].value>0)
            {
                tiles[i].updateTile();

                window.draw(tiles[i]);
                window.draw(tiles[i].textValue);
            }

        }
        if(!isGameStarted)
        {
            sf::Text startText("Press 'C' to start.", fontPixel, 80);
            startText.setFillColor(sf::Color::Black);
            startText.setPosition(120, 0);
            window.draw(startText);
        }
        window.display();
    }
    return 0;
}
