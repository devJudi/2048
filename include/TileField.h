#ifndef TILEFIELD_H
#define TILEFIELD_H

#include <iostream>
#include <SFML/Graphics.hpp>

class TileField     :public sf::RectangleShape
{
    public:
        TileField();
        virtual ~TileField();

        inline int getX() {return x;};
        inline void setX(int newX)
            {if(newX<=0) x=newX;
                else std::cout<<"Invalid field size."<<std::endl;};

        inline int getY() {return y;};
        inline void setY(int newY)
            {if(newY<=0) y=newY;
                else std::cout<<"Invalid field size."<<std::endl;};

    protected:

    private:
        int x;
        int y;
};

#endif // TILEFIELD_H
