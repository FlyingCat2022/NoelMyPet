//
//  Header.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/7/5.
//

#ifndef Header_h
#define Header_h

#define PHYSAC_IMPLEMENTATION
#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

int timer;
void UpdateTimer(void){
    timer = GetTime()*120;
}

#include "ToolBox/inc.h"
#include "UI/Header.h"
#include "Init/Header.h"

#include "Draw/Header.h"

#include "inc.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// C O D E P I E C E S
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void init_main(void){
    
    InitDraw(0, 0);

    srand((unsigned)time(0));
    
    const int screenWidth = 600;
    const int screenHeight = 300;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_TOPMOST | FLAG_VSYNC_HINT | FLAG_WINDOW_UNDECORATED);
    
    InitWindow(screenWidth, screenHeight, "Noel");
    SetTargetFPS(120);
    SetNoelSleeping();
    
    MusicPlayerInit();
    InitDialog();
    
    music_ui_alpha = 0;
    music_ui_enable = false;
    timer = 0;
}

void loadData(void){
    SetNoelImage();
    SetUITexture();
    SetEmoTexture();
    SetTalkTexture();
    SetBootingTexture();
    
    InitUI();
}

#endif /* Header_h */
