#include "raylib.h"
#include "board.h"

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

void Tile::render(std::string answer)
{
    DrawRectangle(getIndex()%5 * (50 + 100/6) + 100/6, getIndex()/5, 50, 50, getColor(answer));
}

Color Tile::getColor(std::string answer)
{
    if (getStoredCharacter() == getIndex()%5) {
        return GREEN;
    }
    else if (answer.find(getStoredCharacter()) != std::string::npos)
    {
        return YELLOW;
    }
    else
    {
        return GRAY;
    }
}