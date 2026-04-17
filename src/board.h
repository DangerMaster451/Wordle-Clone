#pragma once
#include<string>

class Board {
public:
    Board() = default;
    void updateTile(int index, char value);
    bool checkWin();
    void render();

private:
    Tile tiles[30];
    std::string answer;
};

class Tile {
public:
    Tile() = default;
    int getIndex();
    char getStoredCharacter();
    void setIndex(int val);
    void setStoredCharacter(char val);
    void render(std::string answer);

private:
    int index;
    char storedCharacter;
};