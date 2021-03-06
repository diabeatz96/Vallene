//
// Created by Adam on 11/23/2021.
//

#include "menu.h"

#define RAYGUI_IMPLEMENTATION
#include "extras/raygui.h"

void menu::initMenu() {

    InitWindow(screenWidth, screenHeight, "Vallene");
    /** Loading Absolute Path for Now until I can fix regular path.*/
    GuiLoadStyle("C:\\Users\\Adam\\CLionProjects\\HahaProject\\cmake-build-debug\\CMakeFiles\\HahaProject.dir\\styles\\candy\\candy.rgs");
    SetConfigFlags(FLAG_MSAA_4X_HINT);
}
void menu::printMenu() {

    Texture2D Background = LoadTexture("Images/newBG.png");
    Texture2D Logo = LoadTexture("Images/Vallene_Test_Logo.png");
    Rectangle Play;
    int frameCounter = 0;
    int state = 0;
    float alpha = 1.0f;
    SetTargetFPS(60);


    /**  Size to center Logo. + values go right and down, - values go left and up*/
    Vector2 backgroundLen = {static_cast<float>(GetScreenWidth()/2 - Background.width/2) - 350, static_cast<float>(GetScreenHeight()/2  - Background.height/2) - 340};
    Vector2 logoLen = {static_cast<float>(GetScreenWidth()/2 - Logo.width/2) + 160, static_cast<float>(GetScreenHeight()/2  - Logo.height/2) + 150};
    Rectangle Box = {100, 200};

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
            DrawTextureEx(Background, backgroundLen, 0, 0, Fade(RAYWHITE, alpha));
            DrawTextureEx(Logo, logoLen, 0, 0.2, Fade(RAYWHITE, alpha));

        } else if (state == 3 ) {
            DrawTextureEx(Background, backgroundLen, 0, 2, WHITE);
            DrawTextureEx(Logo, logoLen, 0, 0.2, WHITE);
            DrawText("Click Here", GetScreenWidth()/2 - 150, GetScreenHeight()/2 + 250, 40, WHITE);
            if(GuiButton(Rectangle{100, 100, 100 , 100}, "Hello!")) {
                state = 4;
            }
        } else if(state == 4) {
            ClearBackground(WHITE);
            if(GuiTextBox(Rectangle{100, 100, 100 , 100}, "Sauce", 18, false)) {
                state = 3;
            }
        }

        EndDrawing();

    }

    UnloadTexture(Background);       // Texture unloading
    UnloadTexture(Logo);       // Texture unloading

    CloseWindow();                // Close window and OpenGL context
}

void menu::LoadTextures(int state) {

}
