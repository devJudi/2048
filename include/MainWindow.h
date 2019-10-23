#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <Tiles.h>

extern int numberOfTiles;

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name);
        void handleEvent(sf::Event event, unsigned int values[16], std::vector <Tiles> &tiles, std::vector <sf::Text> &tilesText);
        virtual ~MainWindow();

    protected:

    private:
};

#endif // MAINWINDOW_H
