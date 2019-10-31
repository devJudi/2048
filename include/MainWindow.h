#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <Tile.h>

extern std::vector <int> usedTileFields;
extern long long int gameScore;
extern bool isGameStarted;

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name);
        void handleEvent(sf::Event event, Tile tiles[16], bool isEmpty[16]);
        void createNewTile(Tile tiles[16], bool isEmpty[16]);
        void changeTilePosition(int offset, int position, Tile tiles[16], bool isEmpty[16]);

        void setUpUsedVector(bool isReversed, bool isEmpty[16]);
        void moveTileUp(Tile tiles[16], bool isEmpty[16]);
        void moveTileDown(Tile tiles[16], bool isEmpty[16]);
        void moveTileLeft(Tile tiles[16], bool isEmpty[16]);
        void moveTileRight(Tile tiles[16], bool isEmpty[16]);

        virtual ~MainWindow();

    protected:

    private:
};

#endif // MAINWINDOW_H
