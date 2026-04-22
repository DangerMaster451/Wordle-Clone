#include "raylib.h"
#include "board.h"

void getInput(Board& b, int& index);
std::string getCurrentWord(Board& b, int cursorIndex);
bool validateWord(std::string word);
void submitCurrentWord(Board& b, int cursorIndex);

int main() {
    InitWindow(350, 700, "Wordle");
    SetTargetFPS(60);

    Board b = Board();
    int cursorIndex = 0;
    b.setAnswer("crane");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        getInput(b, cursorIndex);
        b.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void getInput(Board& b, int& cursorIndex)
{
    int c = GetCharPressed();
    int l = cursorIndex%5;
    if (c != 0 && )
    {
        b.updateTile(cursorIndex, c);
        cursorIndex++;
    }
    if (IsKeyPressed(KEY_BACKSPACE) && cursorIndex >= 0)
    {
        if (cursorIndex != 0)
            cursorIndex--;
        b.updateTile(cursorIndex, ' ');
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        std::string s = getCurrentWord(b, cursorIndex);
        if (s != "" && validateWord(s) == true)
        {
            submitCurrentWord(b, cursorIndex);
        }
    }
}

std::string getCurrentWord(Board& board, int cursorIndex)
{
    if (cursorIndex%5 != 0)
    {
        return "";
    }
    char a = board.getTile(cursorIndex-5).getStoredCharacter();
    char b = board.getTile(cursorIndex-4).getStoredCharacter();
    char c = board.getTile(cursorIndex-3).getStoredCharacter();
    char d = board.getTile(cursorIndex-2).getStoredCharacter();
    char e = board.getTile(cursorIndex-1).getStoredCharacter();
    return {a, b, c, d, e};
}

bool validateWord(std::string word)
{
    return true;
}

void submitCurrentWord(Board& b, int cursorIndex)
{
    b.getTile(cursorIndex-5).setSubmitted(true);
    b.getTile(cursorIndex-4).setSubmitted(true);
    b.getTile(cursorIndex-3).setSubmitted(true);
    b.getTile(cursorIndex-2).setSubmitted(true);
    b.getTile(cursorIndex-1).setSubmitted(true);
}