#include "raylib.h"
#include "board.h"

void getInput(Board& b, int& index);

int main() {
    InitWindow(350, 700, "Wordle");
    SetTargetFPS(60);

    Board b = Board();
    int index = 0;
    b.setAnswer("crane");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        getInput(b, index);
        b.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void getInput(Board& b, int& index)
{
    int c = GetCharPressed();
    if (c != 0 && index < 29)
    {
        b.updateTile(index, c);
        index++;
    }
    if (IsKeyPressed(KEY_BACKSPACE) && index > 0)
    {
        b.updateTile(index, ' ');
        index--;
    }
}