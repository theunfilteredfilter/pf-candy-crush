#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// =====================================================================
//  SHARED NAMES - everyone uses these, do not rename
// =====================================================================

// ---- Game values (named constants, no magic numbers) ----
const int ROWS = 8, COLS = 8;
const float CELL = 70.f;                     // one cell is 70 x 70 pixels
const float BOARD_X = 20.f, BOARD_Y = 100.f; // top-left corner of the board
const int POINTS_PER_CANDY = 10;

// ---- Game states ----
const int MENU = 0, PLAYING = 1, GAME_OVER = 2;

// ---- Keys (saved in pressedKey) ----
const int NONE = 0, ESCAPE = 1, ENTER = 2, UP = 3, DOWN = 4;

// ---- Game data ----
int  board[ROWS][COLS];        // 0 = empty, 1..6 = candy colours
bool marked[ROWS][COLS];       // filled by findMatches
int  score = 0, movesLeft = 0, target = 0;
int  selRow = -1, selCol = -1; // -1 means nothing is selected
int  gameState = MENU;
bool playerWon = false;        // decides "YOU WIN" or "GAME OVER" text

// ---- Input saved by handleInput, used by updateGame ----
bool clicked = false;
int  clickX = 0, clickY = 0;
int  pressedKey = NONE;

// ---- Font for all text (Rayan) ----
sf::Font font;


// =====================================================================
//  UBAID - finding matches, clearing, falling, refilling
//  (written first because Saim's trySwap calls these)
// =====================================================================

// Clears marked[][], checks every group of 3 in rows and columns,
// marks them, and returns how many candies are marked
void printMarked()
{
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            cout<<marked[r][c]<<" ";
        }
        cout<<endl;
    }
}
int findMatches()
{
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            marked[r][c]=false;
        }
    }
    int count=0;

    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c+2<COLS;c++)
        {
           if(board[r][c]!=0 && board[r][c]==board[r][c+1] && board[r][c]==board[r][c+2])
           {
            marked[r][c]=true;
            marked[r][c+1]=true;
            marked[r][c+2]=true;
           }
        }
    }
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            if(marked[r][c])
            {
                count++;
            }
        }
    }
    return count;
}

// Sets every marked cell to 0 and adds POINTS_PER_CANDY for each one
// Returns how many candies were removed
int removeMatches()
{
    return 0;   // TODO (Ubaid)
}

// One column at a time, bottom-up, using writeRow, so candies fall into gaps
void dropCandies()
{
    // TODO (Ubaid)
}

// Every cell that is still 0 gets rand() % 6 + 1
void refill()
{
    // TODO (Ubaid)
}

// Repeats remove, drop, refill while findMatches() > 0 (chains)
void resolveMatches()
{
    // TODO (Ubaid)
}

// BONUS: tries every right and down swap, returns true if one makes a match
// and puts the two cells in r1, c1, r2, c2
bool findWorkingSwap(int& r1, int& c1, int& r2, int& c2)
{
    return false;   // TODO (Ubaid, bonus)
}


// =====================================================================
//  SAIM - board from file, selecting and swapping, saving
// =====================================================================

// Reads rows, cols, moves, target and the board from level.txt
// Returns false if the file is missing
bool loadLevel()
{
    ifstream fin("level.txt");
    if (!fin)               // file is missing or cannot be opened
    {
        return false;
    }

    // Line 1: rows and cols. We read them only to move past them,
    // the board size is fixed by ROWS and COLS
    int rows, cols;
    fin >> rows >> cols;

    // Line 2: number of moves and the target score
    fin >> movesLeft >> target;

    // The rest: the 8 x 8 board, read row by row, left to right.
    // >> skips spaces and newlines, so each read takes the next number
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            fin >> board[r][c];
        }
    }

    if (!fin)               // file was incomplete or had a non-number in it
    {
        return false;
    }
    return true;
}

// Nested loops: dark square for each cell, coloured circle on top,
// white ring on the selected candy
void drawBoard(sf::RenderWindow& window)
{
    // TODO (Saim)
}

// Turns a click in pixels into a row and column
// Returns false if the click is outside the board
bool cellFromClick(int x, int y, int& row, int& col)
{
    return false;   // TODO (Saim)
}

// Swaps two candies. If findMatches() is 0, swaps them back (no move used).
// Otherwise: movesLeft--, resolveMatches(), checkGameEnd()
void trySwap(int r1, int c1, int r2, int c2)
{
    // TODO (Saim)
}

// First click selects, second click on a neighbour calls trySwap,
// second click anywhere else on the board selects the new candy
void handleBoardClick()
{
    // TODO (Saim)
}

// Writes score, movesLeft, target and the board to savegame.txt
void saveGame()
{
    // TODO (Saim)
}

// Reads savegame.txt. Returns false if there is no saved game
bool loadSave()
{
    return false;   // TODO (Saim)
}

// Empties savegame.txt (open with ofstream and close straight away)
void clearSave()
{
    // TODO (Saim)
}


// =====================================================================
//  RAYAN - HUD, menu, game states, game over screen
// =====================================================================

// Loads a .ttf font file from the project folder into font
bool loadFont()
{
    return false;   // TODO (Rayan)
}

// Top 80-pixel strip: score, moves left, target
void drawHUD(sf::RenderWindow& window)
{
    // TODO (Rayan)
}

// If score >= target: player wins. Else if movesLeft == 0: game over.
// Sets gameState and playerWon, and calls clearSave()
void checkGameEnd()
{
    // TODO (Rayan)
}

// score = 0, nothing selected, calls loadLevel(), gameState = PLAYING
void startNewGame()
{
    // TODO (Rayan)
}

// New Game / Continue / Exit with the selected option highlighted,
// and the "No saved game" message when needed
void drawMenu(sf::RenderWindow& window)
{
    // TODO (Rayan)
}

// "YOU WIN" or "GAME OVER", the final score, and "Press Enter"
void drawGameOver(sf::RenderWindow& window)
{
    // TODO (Rayan)
}


// =====================================================================
//  GAME LOOP (Rayan adds switch (gameState) in these three)
// =====================================================================

// Step 1 of the loop: read what the player did
void handleInput(sf::RenderWindow& window)
{
    clicked = false;      // reset every frame
    pressedKey = NONE;
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
        // TODO (Rayan): read Escape, Enter, Up, Down into pressedKey
    }
}

// Step 2 of the loop: change the game
void updateGame()
{
    // TODO (Rayan): switch (gameState) { case MENU: ... case PLAYING: ... case GAME_OVER: ... }
}

// Step 3 of the loop: draw everything
void drawGame(sf::RenderWindow& window)
{
    window.clear(sf::Color(40, 20, 60));   // background colour
    drawBoard(window);
    drawHUD(window);
    window.display();
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode({600, 680}), "Candy Crush");
    window.setFramerateLimit(60);


   // loadLevel();     //test lines
   // cout<<"Matches:"<<findMatches()<<endl;//test line
    //printMarked();//test line
    

    while (window.isOpen())
    {
        handleInput(window);
        updateGame();
        drawGame(window);
    }
    return 0;
}
