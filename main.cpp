#include <iostream>
#include <vector>
#include "MainWindow.h"
#include "TileField.h"
#include "Tile.h"
#include "Resources.h"

using namespace std;

std::vector <int> usedTileFields;

int colorMod;
long long int gameScore = 0;
long long int bestGameScore = 0;

bool isGameStarted = false;

sf::Font fontPixel;

int main()
{
    srand(time(NULL));
    colorMod=(rand()%10+1);

    Resources::loadFonts();

    bool isEmpty[16];
    for(int i = 0; i<16; i++)
    {
        isEmpty[i] = true;
    }

    Tile tiles[16];
    TileField tileFields[16];
    for(int i = 0; i<16; i++)
    {
        tileFields[i].setPosition(20+(i%4)*140, 125+(i/4)*140);
        tiles[i].setPosition(22+(i%4)*140, 127+(i/4)*140);
    }
    TileField scoreField;
    scoreField.setSize(sf::Vector2f(580, 100));
    scoreField.setPosition(10, 10);
    scoreField.setOutlineThickness(0);
    scoreField.setOutlineColor(sf::Color::Green);
    scoreField.setFillColor(sf::Color(255, 255, 180, 255));

    MainWindow window(600, 700, "2048:re");

    while(window.isOpen())
    {
        sf::Event event;
        window.handleEvent(event, tiles, isEmpty);

        window.clear(sf::Color(255, 255, 220, 0));
        for(int i = 0; i<16; i++)
        {
            window.draw(tileFields[i]);
        }
        window.draw(scoreField);
        for(int i = 0; i<16; i++)
        {
            if(!isEmpty[i]&&tiles[i].value>0)
            {
                tiles[i].updateTile();

                window.draw(tiles[i]);
                window.draw(tiles[i].textValue);
            }

        }
        if(!isGameStarted)
        {
            sf::Text startText("Press 'C' to start.", fontPixel, 80);
            startText.setFillColor(sf::Color::Black);
            startText.setPosition(120, 5);
            window.draw(startText);
        }
        else
        {
            sf::Text scoreText("Score: ", fontPixel, 60);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setPosition(25, 20);
            window.draw(scoreText);

            sf::Text currentScoreText(std::to_string(gameScore), fontPixel, 60);
            currentScoreText.setFillColor(sf::Color::Black);
            currentScoreText.setPosition(130, 22);
            window.draw(currentScoreText);

            sf::Text bestScoreText("Best score: ", fontPixel, 60);
            bestScoreText.setFillColor(sf::Color::Black);
            bestScoreText.setPosition(280, 20);
            window.draw(bestScoreText);

            sf::Text currentBestScoreText(std::to_string(bestGameScore), fontPixel, 60);
            if(bestGameScore==0) currentBestScoreText.setString("-");
            currentBestScoreText.setFillColor(sf::Color::Black);
            currentBestScoreText.setPosition(470, 22);
            window.draw(currentBestScoreText);
        }

        if(window.gameOver)
        {
            sf::RectangleShape gameOverScreen(sf::Vector2f(600, 300));
            gameOverScreen.setFillColor(sf::Color(255, 0, 50, 150));
            gameOverScreen.setPosition(0, 200);
            window.draw(gameOverScreen);

            sf::Text gameOvertText("GAME OVER", fontPixel, 140);
            gameOvertText.setFillColor(sf::Color::Black);
            gameOvertText.setPosition(120, 220);
            window.draw(gameOvertText);

            sf::Text resetGameText("| press 'C' to reset the game |", fontPixel, 50);
            resetGameText.setFillColor(sf::Color::Black);
            resetGameText.setPosition(110, 380);
            window.draw(resetGameText);
        }
        window.display();

    }
    return 0;
}
