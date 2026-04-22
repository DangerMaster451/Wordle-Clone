#include "raylib.h"
#include "board.h"

void getInput(Board& b, int& lineIndex, int& cursorIndex);
bool validateWord(std::string word);

int main() {
    InitWindow(350, 700, "Wordle");
    SetTargetFPS(60);

    Board b = Board();
    int cursorIndex = 0;
    int lineIndex = 0;
    b.setAnswer("crane");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        getInput(b, lineIndex, cursorIndex);
        b.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void getInput(Board& b, int& lineIndex, int& cursorIndex)
{
    int c = GetCharPressed();
    Line* currentLine = b.getLine(lineIndex);
    
    if (c != 0 && cursorIndex>=0 && cursorIndex<=5)
    {
        b.updateTile(lineIndex, cursorIndex, c);
        cursorIndex++;
    }
    if (IsKeyPressed(KEY_BACKSPACE) && cursorIndex >= 0)
    {
        if (cursorIndex != 0)
            cursorIndex--;
        b.updateTile(lineIndex, cursorIndex, ' ');
    }
    if (IsKeyPressed(KEY_ENTER) && currentLine->isComplete())
    {
        std::string s = currentLine->getWord();
        if (validateWord(s) == true)
        {
            currentLine->sumbit();
        }
    }
}

bool validateWord(std::string word)
{
    return true;
}