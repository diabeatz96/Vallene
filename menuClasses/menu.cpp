//
// Created by Adam on 11/23/2021.
//

#include "menu.h"
#include <iostream>

#define RAYGUI_IMPLEMENTATION
#include "extras/raygui.h"

void menu::initMenu() {

    InitWindow(screenWidth, screenHeight, "Vallene");
    /** Loading Absolute Path for Now until I can fix regular path.*/
    GuiLoadStyle("C:\\Users\\Adam\\CLionProjects\\HahaProject\\cmake-build-debug\\CMakeFiles\\HahaProject.dir\\styles\\cyber\\cyber.rgs");
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
    player isaiah;


    /**  Size to center Logo. + values go right and down, - values go left and up*/
    Vector2 backgroundLen = {static_cast<float>(GetScreenWidth() / 2 - Background.width / 2) - 350,
                             static_cast<float>(GetScreenHeight() / 2 - Background.height / 2) - 340};
    Vector2 logoLen = {static_cast<float>(GetScreenWidth() / 2 - Logo.width / 2) + 160,
                       static_cast<float>(GetScreenHeight() / 2 - Logo.height / 2) + 150};
    Rectangle topButton = {static_cast<float>(GetScreenWidth() / 2) - 50,
                           static_cast<float>(GetScreenHeight() / 2) - 100, 100, 50};
    Rectangle middleButton = {static_cast<float>(GetScreenWidth() / 2) - 50, static_cast<float>(GetScreenHeight() / 2),
                              100, 50};
    Rectangle bottomButton = {static_cast<float>(GetScreenWidth() / 2) - 50,
                              static_cast<float>(GetScreenHeight() / 2) + 100, 100, 50};

    windows windowStates;
    windowStates = BEGINFADE;

    InitAudioDevice();
    TitleMusic = LoadMusicStream("Audio/Title.mp3");
    PlayMusicStream(TitleMusic);
    initalizeTextChapter1(isaiah);


    while (!WindowShouldClose()) {

        UpdateMusicStream(TitleMusic);

        stateManager(windowStates, frameCounter, alpha);


        /**  Testing time for when key is pressed.*/
        if (IsKeyPressed(KEY_A)) {
            Logo.width += 10;
        }

        /** All Drawing Functions Begin Here */
        BeginDrawing();

        if(windowStates < 3) {
            ClearBackground(RAYWHITE);
        }
        else {
            ClearBackground(BLACK);
        }


        if (windowStates == BEGINFADE) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        } else if (windowStates == ENDFADE) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, alpha));
        } else if (windowStates == FADEINMENU) {
            DrawTextureEx(Background, backgroundLen, 0, 2, Fade(RAYWHITE, alpha));
            //DrawTextureEx(Logo, logoLen, 0, 0.2, Fade(RAYWHITE, alpha));

        } else if (windowStates == MAINMENU) {
            DrawTextureEx(Background, backgroundLen, 0, 2, WHITE);
            //DrawTextureEx(Logo, logoLen, 0, 0.2, WHITE);

            if (GuiButton(middleButton, "Load Game")) {
                //LoadFileText();
            }

            if (GuiButton(topButton, "Start Game")) {
                windowStates = BEGINTEXTFADE;
            }

            if (GuiButton(bottomButton, "Exit")) {
                UnloadTexture(Background);       // Texture unloading
                UnloadTexture(Logo);       // Texture unloading
                CloseWindow();
            }
        } else if (windowStates == BEGINTEXTFADE) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, alpha));
        } else if (windowStates == TEXTBLOCK) {
            DrawTextureEx(Background, backgroundLen, 0, 2, Fade(BLACK, alpha));
        } else if (windowStates == ENDTEXT) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
            selectTextRoom(isaiah);
        }

        EndDrawing();
    }

        UnloadTexture(Background);       // Texture unloading
        UnloadTexture(Logo);       // Texture unloading

        CloseWindow();                // Close window and OpenGL context

}



void menu::LoadTextures(int state) {

}

void menu::stateManager(menu::windows& windowStates, int& frameCounter, float& alpha) {

    if (windowStates == BEGINFADE) {
        frameCounter++;
        if (frameCounter == 120) {
            windowStates = ENDFADE;
            frameCounter = 0;
        }
    } else if (windowStates == ENDFADE) {
        frameCounter++;
        alpha -= 0.02f;
        if (alpha <= 0.0f) {
            frameCounter = 0;
            alpha = 0.0f;
            windowStates = FADEINMENU;
        }
    } else if (windowStates == FADEINMENU) {
        frameCounter++;
        alpha += 0.02f;
        if (alpha >= 1.0f) {
            frameCounter = 0;
            alpha = 0.f;
            windowStates = MAINMENU;
        }
    } else if (windowStates == BEGINTEXTFADE) {
        frameCounter++;
        alpha += 0.01f;
        if (alpha >= 1.0f) {
            frameCounter = 0;
            alpha = 0.0f;
            windowStates = TEXTBLOCK;
        }
    } else if (windowStates == TEXTBLOCK) {
        frameCounter++;
        alpha -= 0.01f;
        if (alpha <= 0.0f) {
            frameCounter = 0;
            alpha = 0.0f;
            windowStates = ENDTEXT;
        }
    } else if (windowStates == ENDTEXT) {

    }
}


void menu::selectTextRoom(player &isaiah) {

    Rectangle bottomRight = {static_cast<float>(GetScreenWidth() / 2) + 300,
                              static_cast<float>(GetScreenHeight() / 2) + 240, 100, 50};

    Rectangle bottomLeft = {static_cast<float>(GetScreenWidth() / 2) - 240,
                             static_cast<float>(GetScreenHeight() / 2) + 240, 100, 50};

    isaiah.getCurrentRoom().getMyText();

    DrawText(isaiah.currentRoom.getMyText(), GUI_TEXT_ALIGN_CENTER, GUI_TEXT_ALIGN_CENTER, 20, WHITE);

    if (GuiButton(bottomRight, "Next Page")) {
        isaiah.setCurrentRoom(isaiah.currentRoom.ConnectedRooms.front());
    }

    if (GuiButton(bottomLeft, "Prev Page")) {
        isaiah.setCurrentRoom(isaiah.currentRoom.ConnectedRooms.front());
    }
        /*
    textRoom TEST_BOX1;
    textRoom Test_BOX2;
    textRoom Test_Box3;
    std::list<textRoom> testBox1 = {Test_Box3, Test_BOX2};
    Rectangle bottomButton = {static_cast<float>(GetScreenWidth() / 2) - 50,
                              static_cast<float>(GetScreenHeight() / 2) + 100, 100, 50};
    int testFont = 0;

    TEST_BOX1.setConnectedRooms(testBox1);
    TEST_BOX1.setMyText1("\t\t\tIt is the year 3360 on the planet of Vallene. \n This small planet in ancient times used to be a barren wasteland with people fighting in endless sand dunes, \n until “Dawn” appeared. Dawn, a flying castle which appeared 5,000 years ago, shifted the weather, and created seasons. \n Since then, Dawn has been controlled by a Royal family since the beginning, led by the chosen sovereign, who is given the title of “Maestro”, and the “Four Heroes of the Seasons”. \n Our story begins when the most recent sovereign has died. An Empress loved by her people, as well as her eldest son Isaiah. ");
    TEST_BOX1.setRoomName("First Title");
    Test_Box3.setMyText1("This is test text!");

    if (GuiButton(bottomButton, "Next")) {
        testFont = 80;
    }

    DrawText(Test_Box3.getMyText(), GUI_TEXT_ALIGN_CENTER, 0, testFont, WHITE);

    DrawText(TEST_BOX1.getMyText(), GUI_TEXT_ALIGN_CENTER, GUI_TEXT_ALIGN_CENTER, 20, WHITE);
    //GuiTextBox(Rectangle{GUI_TEXT_ALIGN_CENTER, GUI_TEXT_ALIGN_CENTER, static_cast<float>(GetScreenWidth() * 0.7), static_cast<float>(GetScreenHeight() * 0.7)}, TEST_BOX1.getMyText(), 50, true);
    */
}

void menu::initalizeTextChapter1(player &isaiah) {
    /** Introduce intro to character**/
    textRoom intro;
    textRoom page1;
    textRoom page2;
    textRoom page3;
    textRoom page4;
    textRoom page5;
    textRoom page6;
    page1.setMyText1("Isaiah looks down at his cloak in silence for a few seconds. I have a few minutes to spare before I have to be exposed to the public. \n His bedroom was one of the few places he could hide from the officious upper nobles of Dawn, \n especially since it was deep within the abandoned wing of the castle. Decrepit furniture and crates were already here when the room became his. \n Many picture frames and artworks are spread in an unorganized fashion across the walls, covered in dust that may have even come from the time Dawn was created. \n The only things that were his own is the bed, a wardrobe of clothes, a bookshelf and a small desk for work. \n There is also a large vanity, personally decorated by his late mother, which was thrown in here shortly after her passing. I miss her, he thinks. To take this dreary day off his mind, \n he looks around to find a distraction. ");
    intro.setRoomName("Introduction");
    intro.setMyText1("\t\t\tIt is the year 3360 on the planet of Vallene. \n This small planet in ancient times used to be a barren wasteland with people fighting in endless sand dunes, \n until “Dawn” appeared. Dawn, a flying castle which appeared 5,000 years ago, shifted the weather, and created seasons. \n Since then, Dawn has been controlled by a Royal family since the beginning, led by the chosen sovereign, who is given the title of “Maestro”, and the “Four Heroes of the Seasons”. \n Our story begins when the most recent sovereign has died. An Empress loved by her people, as well as her eldest son Isaiah. ");
    std::list<textRoom> page1Connect = {intro};
    std::list<textRoom> introConnect = {page1};
    intro.setConnectedRooms(introConnect);
    page1.setConnectedRooms(page1Connect);
    isaiah.setCurrentRoom(intro);
}


