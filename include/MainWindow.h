#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <Tile.h>

extern int whatIsInThisField[16];

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name);
        void handleEvent(sf::Event event, Tile tiles[16], bool isEmpty[16]);
        void createNewTile(Tile tiles[16], bool isEmpty[16]);
        void changeTilePosition(int offset, int position, Tile tiles[16], bool isEmpty[16]);

        virtual ~MainWindow();

    protected:

    private:
};

#endif // MAINWINDOW_H
