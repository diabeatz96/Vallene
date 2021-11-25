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

    Texture2D Background = LoadTexture("Images/background.gif");
    Texture2D Logo = LoadTexture("Images/Vallene_Test_Logo.png");
    /**  Size to center Logo. + values go right and down, - values go left and up*/
    Vector2 backgroundLen = {static_cast<float>(GetScreenWidth()/2 - Background.width/2) - 350, static_cast<float>(GetScreenHeight()/2  - Background.height/2) - 340};
    Vector2 logoLen = {static_cast<float>(GetScreenWidth()/2 - Logo.width/2) + 200, static_cast<float>(GetScreenHeight()/2  - Logo.height/2)};


    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(Background, backgroundLen, 0, 3.2, WHITE);
        DrawTextureEx(Logo, logoLen, 0, 0.5, WHITE);


        EndDrawing();

    }

    UnloadTexture(Logo);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
}

void menu::LoadTextures(int state) {

}
