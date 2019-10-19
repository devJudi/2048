#include <iostream>
#include "MainWindow.h"

using namespace std;

int main()
{
    MainWindow window(600, 700, "2048:re");
    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event);

        window.clear();
        window.display();
    }
    return 0;
}
