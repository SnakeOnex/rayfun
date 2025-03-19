#include "raylib.h"
#include <math.h>

int main(void) {
    InitWindow(800, 450, "Pendulum");
    SetTargetFPS(60);

    // init position
    float circleX = 400.0f;
    float circleY = 200.0f;
    float radius = 20.0f;
    float speedX = 2.0f;

    // pendulum init
    Vector2 pivot = {400.0f, 50.0f};
    float length = 200.0f;
    float angle = 0.5f;
    float angularVelocity = 0.0f;
    float gravity = 9.81f;
    float damping = 0.995f;

    while (!WindowShouldClose()) {
        // update circle
        circleX += speedX;

        if (circleX > 800 - radius || circleX < 0 + radius) {
            speedX *= -1;
        }

        // update pendulum
        float angularAcc = (-gravity / length) * sin(angle);
        angularVelocity += angularAcc;
        angularVelocity *= damping;
        angle += angularVelocity * (1.0f / 60.0f);

        float pendulumX = pivot.x + length * sin(angle);
        float pendulumY = pivot.y + length * cos(angle);


        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(circleX, circleY, radius, RED);

        DrawCircle(pendulumX, pendulumY, 10, BLUE);

        DrawText("Bouncing circle!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
