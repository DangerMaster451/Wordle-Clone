#include "raylib.h"
#include "board.h"

int main() {
    InitWindow(350, 700, "My Game");
    SetTargetFPS(60);

    Board b = Board();
    b.setAnswer("crane");
    b.updateTile(0, 'c');
    b.updateTile(1, 'r');
    b.updateTile(2, 'n');
    b.updateTile(3, 'j');
    b.updateTile(4, 'e');

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        b.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}