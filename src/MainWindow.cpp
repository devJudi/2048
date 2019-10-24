#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name)
{
    this->create(sf::VideoMode(x, y), name);
}

void MainWindow::handleEvent(sf::Event event, std::vector <Tile> &tiles, bool isEmpty[16])
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
            else if(event.key.code==sf::Keyboard::W||event.key.code==sf::Keyboard::Up)
            {
                std::vector <int> usedTileFields;
                for(int i = 0; i<16; i++)
                {
                    if(!isEmpty[i])
                        usedTileFields.push_back(i);
                }
                int position = 0;

                for(unsigned int i = 0; i<usedTileFields.size(); i++)
                {
                    position = usedTileFields[i];
                    switch(position/4)
                    {
                    case 0:
                        break;

                    case 1:
                        if(isEmpty[position-4])
                        {
                            changeTilePosition(4, position, tiles, isEmpty);
                        }
                        break;

                    case 2:
                        if(isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-4])
                        {
                            changeTilePosition(4, position, tiles, isEmpty);
                        }
                        break;

                    case 3:
                        if(isEmpty[position-12]&&isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(12, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-4])
                        {
                            changeTilePosition(4, position, tiles, isEmpty);
                        }
                        break;
                    }
                }

                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::S||event.key.code==sf::Keyboard::Down)
            {
                std::vector <int> usedTileFields;
                for(int i = 0; i<16; i++)
                {
                    if(!isEmpty[i])
                        usedTileFields.push_back(i);
                }
                int position = 0;

                for(unsigned int i = 0; i<usedTileFields.size(); i++)
                {
                    position = usedTileFields[i];
                    switch(position/4)
                    {
                    case 0:
                        if(isEmpty[position+12]&&isEmpty[position+8]&&isEmpty[position+4])
                        {
                            changeTilePosition(-12, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+8]&&isEmpty[position+4])
                        {
                            changeTilePosition(-8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        break;

                    case 1:
                        if(isEmpty[position+8]&&isEmpty[position+4])
                        {
                            changeTilePosition(-8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        break;

                    case 2:
                        if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        break;

                    case 3:
                        break;
                    }
                }

                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::A||event.key.code==sf::Keyboard::Left)
            {
                std::vector <int> usedTileFields;
                for(int i = 0; i<16; i++)
                {
                    if(!isEmpty[i])
                        usedTileFields.push_back(i);
                }
                int position = 0;

                for(unsigned int i = 0; i<usedTileFields.size(); i++)
                {
                    position = usedTileFields[i];
                    switch(position%4)
                    {
                    case 0:
                        break;

                    case 1:
                        if(isEmpty[position-1])
                        {
                            changeTilePosition(1, position, tiles, isEmpty);
                        }
                        break;

                    case 2:
                        if(isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-1])
                        {
                            changeTilePosition(1, position, tiles, isEmpty);
                        }
                        break;

                    case 3:
                        if(isEmpty[position-3]&&isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(3, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-1])
                        {
                            changeTilePosition(1, position, tiles, isEmpty);
                        }
                        break;
                    }
                }

                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::D||event.key.code==sf::Keyboard::Right)
            {
                std::vector <int> usedTileFields;
                for(int i = 0; i<16; i++)
                {
                    if(!isEmpty[i])
                        usedTileFields.push_back(i);
                }
                int position = 0;

                for(unsigned int i = 0; i<usedTileFields.size(); i++)
                {
                    position = usedTileFields[i];
                    switch(position%4)
                    {
                    case 0:
                        if(isEmpty[position+3]&&isEmpty[position+2]&&isEmpty[position+1])
                        {
                            changeTilePosition(-3, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+2]&&isEmpty[position+1])
                        {
                            changeTilePosition(-2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        break;

                    case 1:
                        if(isEmpty[position+2]&&isEmpty[position+1])
                        {
                            changeTilePosition(-2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        break;

                    case 2:
                        if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        break;

                    case 3:
                        break;
                    }
                }
                createNewTile(tiles, isEmpty);
            }
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {

        }
    }
}

void MainWindow::createNewTile(std::vector <Tile> &tiles, bool isEmpty[16])
{
    std::vector <int> emptyTileFields;
    for(int i = 0; i<16; i++)
    {
        if(isEmpty[i])
            emptyTileFields.push_back(i);
    }

    if(!emptyTileFields.empty())
    {
        int random = rand()%emptyTileFields.size();

        if(isEmpty[emptyTileFields[random]])
        {
            tiles.push_back(Tile(136));
            tiles[numberOfTiles].setPosition(22+(emptyTileFields[random]%4)*140,
                                             127+(emptyTileFields[random]/4)*140);
            tiles[numberOfTiles].value = 2;
            tiles[numberOfTiles].updateTile();

            isEmpty[emptyTileFields[random]]=false;

            whatIsInThisField[emptyTileFields[random]] = numberOfTiles;

            numberOfTiles++;
        }
    }
}

void MainWindow::changeTilePosition(int offset, int position, std::vector <Tile> &tiles, bool isEmpty[16])
{
    std::cout<<"Tile no."<<position<<": Trying to switch to poll #"<<position-offset<<std::endl;
    tiles[whatIsInThisField[position]].setPosition(22+((position-offset)%4)*140,
            127+((position-offset)/4)*140);
    tiles[whatIsInThisField[position]].updateTile();

    whatIsInThisField[position-offset] = whatIsInThisField[position];
    whatIsInThisField[position] = 99;

    isEmpty[position-offset] = false;
    isEmpty[position] = true;
}

MainWindow::~MainWindow()
{
    //dtor
}
