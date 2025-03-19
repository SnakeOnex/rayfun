#include "raylib.h"
#include <math.h>

int main(void) {
    InitWindow(800, 450, "Pendulum");
    SetTargetFPS(60);

    // initial condition
    Vector2 pos = {400.0f, 200.0f};
    Vector2 vel = {200.0f, -500.0f};
    float g = -9.81f;

    // math
    // acc(t) = -g
    // vel(t) = -gt + v0
    // pos(t) = -1/2 * g * t^2 + v0 * t + p0

    while (!WindowShouldClose()) {
        // update
        vel.x = vel.x - 0;
        vel.y = vel.y - g;

        pos.x += vel.x * (1.0f / 60.0f);
        pos.y += vel.y * (1.0f / 60.0f);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(pos.x, pos.y, 10, BLUE);

        DrawText("Bouncing circle!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
