#include "MainWindow.h"

MainWindow::MainWindow(int x, int y, std::string name)
{
    this->create(sf::VideoMode(x, y), name);
}

void MainWindow::handleEvent(sf::Event event)
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
            else if(event.key.code==sf::Keyboard::A)
            {

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
