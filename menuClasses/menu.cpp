//
// Created by Adam on 11/23/2021.
//

#include "menu.h"

void menu::initMenu() {
    InitWindow(screenWidth, screenHeight, "Vallene");

    SetTargetFPS(60);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
}
void menu::printMenu() {

    Texture2D Logo = LoadTexture("Images/test.png");
    /**  Size to center Logo. + values go right and down, - values go left and up*/
    Vector2 logoLen = {static_cast<float>(GetScreenWidth()/2 - Logo.width/2) - 100, static_cast<float>(GetScreenHeight()/2  - Logo.height/2) + 200};
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(Logo, logoLen, 0, 1, WHITE);

        EndDrawing();

    }

    UnloadTexture(Logo);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
}

void menu::LoadTextures(int state) {

}
