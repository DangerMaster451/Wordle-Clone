#include "raylib.h"
#include "board.h"
#include <cmath>

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

Line::Line()
{
    for (int i = 0; i < 6; i++)
    {
        tiles[i] = new Tile();
        tiles[i]->setStoredCharacter(' ');
        tiles[i]->setIndex(i);
    }
}

bool Line::isComplete()
{
    for (char c : getWord())
    {
        if (c == ' ') {
            return false;
        }
    }
    return true;
}

std::string Line::getWord()
{
    std::string s = "";
    for (Tile* t : tiles)
    {
        s += t->getStoredCharacter();
    }
    return s;
}

void Line::updateTile(int index, char val)
{
    tiles[index]->setStoredCharacter(val);
}

Tile* Line::getTile(int index)
{
    return tiles[index];
}

void Line::render(std::string answer)
{
    for (Tile* t : tiles)
    {
        t->render(answer);
    }
}

void Line::sumbit()
{
    for (Tile* t : tiles)
    {
        t->setSubmitted(true);
    }
}

Board::Board()
{
    for (int i = 0; i < 5; i++)
    {
        lines[i] = new Line();
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

bool Board::checkWin()
{
    return false;
}

void Board::render()
{
    for (int i = 0; i < 6; i++)
    {
        lines[i]->render(getAnswer());
    }
}

void Board::updateTile(int lineIndex, int cursorIndex, char val)
{
    lines[lineIndex]->updateTile(cursorIndex, val);
}

Line* Board::getLine(int index)
{
    return lines[index];
}

