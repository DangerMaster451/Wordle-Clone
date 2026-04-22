#pragma once
#include<string>

class Tile {
public:
    Tile() = default;
    int getIndex();
    char getStoredCharacter();
    void setIndex(int val);
    void setStoredCharacter(char val);
    bool getSubmitted();
    void setSubmitted(bool val);
    void render(std::string answer);
    Color getColor(std::string answer);

private:
    int index;
    char storedCharacter;
    bool submitted;
};

class Board {
public:
    Board();
    std::string getAnswer();
    void setAnswer(std::string val);
    void updateTile(int index, char value);
    Tile& getTile(int index);
    bool checkWin();
    void render();

private:
    Tile tiles[30];
    std::string answer;
};