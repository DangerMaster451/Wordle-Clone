#include "raylib.h"
#include "board.h"

int main() {
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("It Works!", 300, 280, 30, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}