#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name)
{
    this->create(sf::VideoMode(x, y), name);
}

void MainWindow::handleEvent(sf::Event event, unsigned int values[16],
                             std::vector <Tiles> &tiles, std::vector <sf::Text> &tilesText)
{
    srand(time(NULL));

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
                bool isEmpty[16];
                for(int i = 0; i<16; i++)
                {
                    if(values[i] == 0) isEmpty[i]=true;
                    else isEmpty[i] = false;
                }

                int random = rand()%16;
                if(isEmpty[random])
                {
                    tiles.push_back(Tiles(0, 0));
                    tiles[numberOfTiles].value = 2;
                    tiles[numberOfTiles].position = random;

                    tilesText.push_back(sf::Text("0", fontPixel));

                    isEmpty[random]=true;

                    numberOfTiles++;
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
