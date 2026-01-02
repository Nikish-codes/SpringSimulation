#include <stdio.h>
#include "raylib.h"
#include <math.h>

#define FPS 100
#define WIDTH 960
#define HEIGHT 680
#define THICKNESS 5
#define MASS_LENGTH 100
#define FLOOR_Y (HEIGHT*0.6)
#define SPRING_LEN 30
#define SPRING_THICKNESS 2
#define K 50
#define X_REST 350



float mass_x = 600;
float v = 30;
float a = 2;
float f = 0.5;

void drawSpring()
{
    Vector2 Line_start = {0, FLOOR_Y -MASS_LENGTH/2};
    Vector2 anchor = Line_start;
    Vector2 mass_pos = {mass_x, FLOOR_Y -MASS_LENGTH/2};
    
    // Calculate distance and angle between anchor and mass
    float dx = mass_pos.x - anchor.x;
    float dy = mass_pos.y - anchor.y;
    float distance = sqrt(dx*dx + dy*dy);
    float dir_x = dx / distance;  // Unit vector x component
    float dir_y = dy / distance;  // Unit vector y component
    
    float perp_x = -dir_y;  // Perpendicular x (rotate 90°)
    float perp_y = dir_x;   // Perpendicular y (rotate 90°)

    for(int i = 0; i<=SPRING_LEN; i++)
    {
        float progress = (float)i / SPRING_LEN; // 0 to 1

        Vector2 axis_pos = {
        anchor.x + dir_x * distance * progress,
        anchor.y + dir_y * distance * progress
        };
        float offset = (i % 2 == 0) ? 15.0f : -15.0f;  // 20 = spring width
        
        Vector2 Line_end = {
        axis_pos.x + perp_x * offset,
        axis_pos.y + perp_y * offset
        };
        DrawLineEx(Line_start, Line_end, SPRING_THICKNESS, WHITE);
        Line_start = Line_end;
    }
        DrawLineEx(Line_start, mass_pos, SPRING_THICKNESS, WHITE);
}

void drawFloor()
{
    Vector2 start = {0, HEIGHT*0.6};
    Vector2 end = {WIDTH, HEIGHT*0.6};
    DrawLineEx(start, end, THICKNESS, GRAY);
}

void drawMass()
{
    Rectangle rect = {mass_x, FLOOR_Y-MASS_LENGTH-THICKNESS/2, MASS_LENGTH, MASS_LENGTH};
    DrawRectangleRec(rect, GREEN);    
}

int main()

{

    InitWindow(WIDTH, HEIGHT, "ElasticCore: A Mass on Spring Simulation");

    SetTargetFPS(FPS);
    float dt;

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
            ClearBackground(BLACK);
            drawSpring();
            DrawFPS(10,10);
            dt = GetFrameTime();
            a = -K * (mass_x - X_REST)  - f*v;//Equation for the spring force + friction
            v += a * dt;
            mass_x += v * dt;
            drawMass();
            drawFloor(); 
            DrawText("Mass on Simulation", WIDTH/10, 80, 30, RED);
            
        EndDrawing();
    }

    CloseWindow();

    return 0;

}