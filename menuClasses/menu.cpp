//
// Created by Adam on 11/23/2021.
//

#include "menu.h"

void menu::initMenu() {

    InitWindow(screenWidth, screenHeight, "Vallene");
    SetConfigFlags(FLAG_MSAA_4X_HINT);

}
void menu::printMenu() {

    Texture2D Background = LoadTexture("Images/background.gif");
    Texture2D Logo = LoadTexture("Images/Vallene_Test_Logo.png");
    int frameCounter = 0;
    int state = 0;
    float alpha = 1.0f;
    SetTargetFPS(60);


    /**  Size to center Logo. + values go right and down, - values go left and up*/
    Vector2 backgroundLen = {static_cast<float>(GetScreenWidth()/2 - Background.width/2) - 350, static_cast<float>(GetScreenHeight()/2  - Background.height/2) - 340};
    Vector2 logoLen = {static_cast<float>(GetScreenWidth()/2 - Logo.width/2) + 330, static_cast<float>(GetScreenHeight()/2  - Logo.height/2) + 200};


    InitAudioDevice();
    TitleMusic = LoadMusicStream("Audio/Title.mp3");
    PlayMusicStream(TitleMusic);



    while(!WindowShouldClose()) {

        UpdateMusicStream(TitleMusic);

        if(state == 0) {
            frameCounter++;
            if(frameCounter == 120) {
                state = 1;
                frameCounter = 0;
            }
        }
        else if (state == 1) {
            frameCounter++;
            alpha -= 0.02f;
            if (alpha <= 0.0f) {
                frameCounter = 0;
                alpha = 0.0f;
                state = 2;
            }
        }
        else if (state == 2) {
            frameCounter++;
            alpha += 0.02f;
            if (alpha >= 1.0f) {
                frameCounter = 0;
                alpha = 1.0f;
                state = 3;
            }
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(TitleMusic);
            PlayMusicStream(TitleMusic);
        }

        /**  Testing time for when key is pressed.*/
        if(IsKeyPressed(KEY_A)) {
            Logo.width += 10;
        }

        /** All Drawing Functions Begin Here */
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if(state == 0) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        }
        else if (state == 1) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, alpha));
        }
        else if (state == 2) {
            DrawTextureEx(Background, backgroundLen, 0, 3.2, Fade(RAYWHITE, alpha));
            DrawTextureEx(Logo, logoLen, 0, 0.5, Fade(RAYWHITE, alpha));
        } else if (state == 3 ) {
            DrawTextureEx(Background, backgroundLen, 0, 3.2, WHITE);
            DrawTextureEx(Logo, logoLen, 0, 0.5, WHITE);
        }

        EndDrawing();

    }

    UnloadTexture(Background);       // Texture unloading
    UnloadTexture(Logo);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
}

void menu::LoadTextures(int state) {

}
