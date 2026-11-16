#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---- Game values (named constants, no magic numbers) ----
const int ROWS = 8, COLS = 8;
const float CELL = 70.f;                    // one cell is 70 x 70 pixels
const float BOARD_X = 20.f, BOARD_Y = 100.f; // top-left corner of the board

// ---- Game data ----
int board[ROWS][COLS];
int score = 0, movesLeft = 0, target = 0;

// ---- Input saved by handleInput, used by updateGame ----
bool clicked = false;
int clickX = 0, clickY = 0;

// Step 1 of the loop: read what the player did
void handleInput(sf::RenderWindow& window)
{
    clicked = false;   // reset every frame
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
        else if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouse->button == sf::Mouse::Button::Left)
            {
                clickX = mouse->position.x;
                clickY = mouse->position.y;
                clicked = true;
            }
        }
    }
}

// Step 2 of the loop: change the game (your logic goes here later)
void updateGame()
{
}

// Step 3 of the loop: draw everything
void drawGame(sf::RenderWindow& window)
{
    window.clear(sf::Color(40, 20, 60));   // background colour
    // drawBoard(window);   <- you will write this next
    window.display();
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode({600, 680}), "Candy Crush");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        handleInput(window);
        updateGame();
        drawGame(window);
    }
    return 0;
}