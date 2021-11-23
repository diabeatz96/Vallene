/*******************************************************************************************
*
*   raylib [shapes] example - easings box anim
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "/playerClass/player.h"

#define RAYGUI_IMPLEMENTATION
#include "extras/raygui.h"

int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - easings box anim");

    // Box variables to be animated with easings
    Rectangle rec = {GetScreenWidth() / 2.0f, -100, 100, 100};
    float rotation = 0.0f;
    float alpha = 1.0f;
    float startAngle = 0.f;
    int state = 0;
    int framesCounter = 0;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------

        ClearBackground(RAYWHITE);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
        DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));

        startAngle = GuiSliderBar((Rectangle){ 600, 40, 120, 20}, "StartAngle", nullptr, startAngle, 0, 720);



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

}