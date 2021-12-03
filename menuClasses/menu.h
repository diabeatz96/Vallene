//
// Created by Adam on 11/23/2021.
//

#ifndef VALLENE_MENU_H
#define VALLENE_MENU_H

#include<raylib.h>



class menu {

public:
    enum windows {BEGINFADE, ENDFADE, FADEINMENU, MAINMENU, BEGINTEXTFADE, TEXTBLOCK, ENDTEXT};

    void initMenu();
    void printMenu();
    void LoadTextures(int state);
    void stateManager(windows& State, int& framesref, float& alpha);

private:
    int state = 0;
    const float screenWidth = 1200;
    const float screenHeight = 750;
    Vector2 TextBox = {screenWidth/2, screenHeight/2};
    Music TitleMusic;
    /** Windows for BeginFade */
};


#endif //VALLENE_MENU_H
