//
//  WindowChange.h
//  Somnambulism
//
//  Created on 2022/8/20.
//

#ifndef WindowChange_h
#define WindowChange_h

#include "raylib.h"

bool NoelSideLeft = true;
Rectangle AllRect;
Rectangle NoelRect;

void SetNoelSide(void){
    if(NoelSideLeft){
        if(AllRect.x+AllRect.width+GetWindowPosition().x > GetScreenWidth()*2){
            NoelSideLeft = false;
            NoelRect.x = 456;
            SetWindowPosition(GetWindowPosition().x-456, GetWindowPosition().y);
        }
    }
    else{
        if(GetWindowPosition().x < -10){
            NoelSideLeft = true;
            NoelRect.x = 0;
            SetWindowPosition(GetWindowPosition().x+456, GetWindowPosition().y);
        }
    }
}

#endif /* WindowChange_h */
