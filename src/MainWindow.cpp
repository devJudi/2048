#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name)
{
    this->create(sf::VideoMode(x, y), name);
}

void MainWindow::handleEvent(sf::Event event, Tile tiles[16], bool isEmpty[16])
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
            else if(event.key.code==sf::Keyboard::C)
            {
                createNewTile(tiles, isEmpty);
                isGameStarted = true;
            }
            else if(event.key.code==sf::Keyboard::W||event.key.code==sf::Keyboard::Up)
            {
                moveTileUp(tiles, isEmpty);
                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::S||event.key.code==sf::Keyboard::Down)
            {
                moveTileDown(tiles, isEmpty);
                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::A||event.key.code==sf::Keyboard::Left)
            {
                moveTileLeft(tiles, isEmpty);
                createNewTile(tiles, isEmpty);
            }
            else if(event.key.code==sf::Keyboard::D||event.key.code==sf::Keyboard::Right)
            {
                moveTileRight(tiles, isEmpty);
                createNewTile(tiles, isEmpty);
            }
        }
        if(event.type==sf::Event::MouseButtonPressed)
        {

        }
    }
}

void MainWindow::createNewTile(Tile tiles[16], bool isEmpty[16])
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
            tiles[emptyTileFields[random]].value = 2;
            isEmpty[emptyTileFields[random]]=false;
        }
    }
}

void MainWindow::changeTilePosition(int offset, int position, Tile tiles[16], bool isEmpty[16])
{
    std::cout<<"Tile no."<<position<<": Trying to switch to poll #"<<position-offset<<std::endl;

    tiles[position-offset].value = tiles[position].value;
    tiles[position].value = 0;

    isEmpty[position-offset] = false;
    isEmpty[position] = true;
}

void MainWindow::setUpUsedVector(bool isReversed, bool isEmpty[16])
{
    if(!isReversed)
    {
        for(int i = 0; i<16; i++)
        {
            if(!isEmpty[i])
                usedTileFields.push_back(i);
        }
    }
    else
    {
        for(int i = 15; i>=0; i--)
        {
            if(!isEmpty[i])
                usedTileFields.push_back(i);
        }
    }
}

void MainWindow::moveTileUp(Tile tiles[16], bool isEmpty[16])
{
    setUpUsedVector(false, isEmpty);
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
                        else if(tiles[position-4].value==tiles[position].value)
                        {
                            tiles[position-4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;

                    case 2:
                        if(isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-4]&&
                                tiles[position-8].value==tiles[position].value)
                        {
                            tiles[position-8].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position-4])
                        {
                            changeTilePosition(4, position, tiles, isEmpty);
                        }
                        else if(tiles[position-4].value==tiles[position].value)
                        {
                            tiles[position-4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;

                    case 3:
                        if(isEmpty[position-12]&&isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(12, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-8]&&isEmpty[position-4]&&
                                tiles[position-12].value==tiles[position].value)
                        {
                            tiles[position-12].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position-8]&&isEmpty[position-4])
                        {
                            changeTilePosition(8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-4]&&
                                tiles[position-8].value==tiles[position].value)
                        {
                            tiles[position-8].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position-4])
                        {
                            changeTilePosition(4, position, tiles, isEmpty);
                        }
                        else if(tiles[position-4].value==tiles[position].value)
                        {
                            tiles[position-4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;
                    }
                }
                usedTileFields.clear();

}

void MainWindow::moveTileDown(Tile tiles[16], bool isEmpty[16])
{
    setUpUsedVector(true, isEmpty);
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
                        else if(isEmpty[position+8]&&isEmpty[position+4]&&
                                tiles[position+12].value==tiles[position].value)
                        {
                            tiles[position+12].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position+8]&&isEmpty[position+4])
                        {
                            changeTilePosition(-8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+4]&&
                                tiles[position+8].value==tiles[position].value)
                        {
                            tiles[position+8].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        else if(tiles[position+4].value==tiles[position].value)
                        {
                            tiles[position+4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;

                    case 1:
                        if(isEmpty[position+8]&&isEmpty[position+4])
                        {
                            changeTilePosition(-8, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+4]&&
                                tiles[position+8].value==tiles[position].value)
                        {
                            tiles[position+8].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }

                        else if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        else if(tiles[position+4].value==tiles[position].value)
                        {
                            tiles[position+4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;

                    case 2:
                        if(isEmpty[position+4])
                        {
                            changeTilePosition(-4, position, tiles, isEmpty);
                        }
                        else if(tiles[position+4].value==tiles[position].value)
                        {
                            tiles[position+4].value*=2;
                            tiles[position].value=0;
                            isEmpty[position]=true;
                        }
                        break;

                    case 3:
                        break;
                    }
                }
                usedTileFields.clear();

}

void MainWindow::moveTileLeft(Tile tiles[16], bool isEmpty[16])
{
    setUpUsedVector(false, isEmpty);
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
                        else if(tiles[position-1].value==tiles[position].value)
                        {
                            tiles[position-1].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }
                        break;

                    case 2:
                        if(isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-1]&&
                                tiles[position-2].value==tiles[position].value)
                        {
                            tiles[position-2].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position-1])
                        {
                            changeTilePosition(1, position, tiles, isEmpty);
                        }
                        else if(tiles[position-1].value==tiles[position].value)
                        {
                            tiles[position-1].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }
                        break;

                    case 3:
                        if(isEmpty[position-3]&&isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(3, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-2]&&isEmpty[position-1]&&
                                tiles[position-3].value==tiles[position].value)
                        {
                            tiles[position-3].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position-2]&&isEmpty[position-1])
                        {
                            changeTilePosition(2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position-1]&&
                                tiles[position-2].value==tiles[position].value)
                        {
                            tiles[position-2].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position-1])
                        {
                            changeTilePosition(1, position, tiles, isEmpty);
                        }
                        else if(tiles[position-1].value==tiles[position].value)
                        {
                            tiles[position-1].value*=2;
                            tiles[position].value = 0;
                            isEmpty[position] = true;
                        }
                        break;
                    }
                }
                usedTileFields.clear();

}

void MainWindow::moveTileRight(Tile tiles[16], bool isEmpty[16])
{
    setUpUsedVector(true, isEmpty);
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
                        else if(isEmpty[position+2]&&isEmpty[position+1]&&
                                tiles[position+3].value==tiles[position].value)
                        {
                            tiles[position+3].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position+2]&&isEmpty[position+1])
                        {
                            changeTilePosition(-2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+1]&&
                                tiles[position+2].value==tiles[position].value)
                        {
                            tiles[position+2].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        else if(tiles[position+1].value==tiles[position].value)
                        {
                            tiles[position+1].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }
                        break;

                    case 1:
                        if(isEmpty[position+2]&&isEmpty[position+1])
                        {
                            changeTilePosition(-2, position, tiles, isEmpty);
                        }
                        else if(isEmpty[position+1]&&
                                tiles[position+2].value==tiles[position].value)
                        {
                            tiles[position+2].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }

                        else if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        else if(tiles[position+1].value==tiles[position].value)
                        {
                            tiles[position+1].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }
                        break;

                    case 2:
                        if(isEmpty[position+1])
                        {
                            changeTilePosition(-1, position, tiles, isEmpty);
                        }
                        else if(tiles[position+1].value==tiles[position].value)
                        {
                            tiles[position+1].value*=2;
                            tiles[position].value=0;
                            isEmpty[position] = true;
                        }
                        break;

                    case 3:
                        break;
                    }
                }
            usedTileFields.clear();
}


MainWindow::~MainWindow()
{
    //dtor
}
