#pragma once
#include<string>

class Board {

};

class Tile {
private:
    int index;
    char storedCharacter;
public:
    int getIndex();
    char getStoredCharacter();
    void setIndex(int val);
    void setStoredCharacter(char val);

    void render(std::string answer);

};