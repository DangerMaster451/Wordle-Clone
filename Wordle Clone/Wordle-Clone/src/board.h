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

class Line {
public: 
    Line();
    bool isComplete();
    std::string getWord();
    void updateTile(int index, char val);
    Tile* getTile(int index);
    void render(std::string answer);
    void sumbit();

private:
    Tile* tiles[5];
};

class Board {
public:
    Board();
    std::string getAnswer();
    void setAnswer(std::string val);
    bool checkWin();
    void render();
    void updateTile(int lineIndex, int cursorIndex, char val);
    Line* getLine(int index);

private:
    Line* lines[5];
    std::string answer;
};