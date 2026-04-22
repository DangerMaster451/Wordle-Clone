#include "raylib.h"
#include "board.h"
#include <cmath>

Board::Board()
{
    for (int i = 0; i < 30; i++)
    {
        updateTile(i, ' ');
    }
}

std::string Board::getAnswer()
{
    return this->answer;
}

void Board::setAnswer(std::string val)
{
    this->answer = val;
}

void Board::updateTile(int index, char value)
{
    tiles[index].setIndex(index);
    tiles[index].setStoredCharacter(value);
}

Tile& Board::getTile(int index)
{
    return tiles[index];
}

bool Board::checkWin()
{
    return false;
}

void Board::render()
{
    for (int i = 0; i < 30; i++)
    {
        tiles[i].render(getAnswer());
    }
}

int Tile::getIndex()
{
    return this->index;
}

char Tile::getStoredCharacter()
{
    return this->storedCharacter;
}

void Tile::setIndex(int val)
{
    this->index = val;
}

void Tile::setStoredCharacter(char val)
{
    this->storedCharacter = val;
}

bool Tile::getSubmitted()
{
    return this->submitted;
}

void Tile::setSubmitted(bool val)
{
    this->submitted = val;
}

void Tile::render(std::string answer)
{
    float x = getIndex()%5 * (50 + 100/6) + 100/6;
    float y = std::floor(getIndex()/5) * (50 + 100/6) + 100/6;
    DrawRectangle(x, y, 50, 50, getColor(answer));
    DrawText(TextFormat("%c", getStoredCharacter()), x+25/2, y+25/2, 32, BLACK);
}

Color Tile::getColor(std::string answer)
{
    if (getSubmitted() == false)
    {
        return GRAY;
    }
    if (getStoredCharacter() == answer[getIndex()%5]) {
        return GREEN;
    }
    if (answer.find(getStoredCharacter()) != std::string::npos)
    {
        return YELLOW;
    }
    return WHITE;
}