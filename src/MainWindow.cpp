#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name)
{
    this->create(sf::VideoMode(x, y), name);
}

void MainWindow::handleEvent(sf::Event event, unsigned int values[16], std::vector <Tile> &tiles, bool isEmpty[16])
{
    while(this->pollEvent(event))
    {
        if(event.type==sf::Event::Closed)
        {
            this->close();
        }
        if(event.type==sf::Event::KeyPressed)
        {
            if(event.key.code==sf::Keyboard::Escape)
            {
                this->close();
            }
            else if(event.key.code==sf::Keyboard::W)
            {
                int random = rand()%16;
                std::cout<<"Random: "<<random<<std::endl;

                if(isEmpty[random])
                {
                    tiles.push_back(Tile(136));
                    tiles[numberOfTiles].setPosition(22+(random%4)*140, 127+(random/4)*140);
                    tiles[numberOfTiles].value = random*random*10;
                    tiles[numberOfTiles].updateTile();

                    isEmpty[random]=false;

                    numberOfTiles++;
                    std::cout<<numberOfTiles<<std::endl;
                }
            }
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {

        }
    }
}

MainWindow::~MainWindow()
{
    //dtor
}
