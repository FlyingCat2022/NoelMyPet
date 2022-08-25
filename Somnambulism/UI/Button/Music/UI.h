//
//  UI.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/23.
//

#ifndef UI_h
#define UI_h

#include "../Button.h"
#include "Music.h"

bool music_ui_enable = true;
int music_ui_alpha = 0;


void MusicSetLeft(void){
    if(IsKeyDown(KEY_LEFT_SHIFT)||IsKeyDown(KEY_RIGHT_SHIFT))
        MusicPlayer.music.looping = !MusicPlayer.music.looping;
    else
        ++MusicPlayer.DBSet;
}

void MusicSetRight(void){
    if(MusicPlayer.state != mToSwitch)
        MusicPlayer.state = mToSwitch;
    else
        MusicPlayer.state = mSwitching;
}

UIButton MusicSet = {
    .func = {
        MusicSetLeft,
        MusicSetRight
    }
};

void UIButtonRun(UIButton a){
    if(inside_2d(GetMousePosition(), a.rect)){
        for(int i=0;i<7;++i)
            if(IsMouseButtonPressed(i))
                a.func[i]();
    }
    DrawTexture(a.tex,a.rect.x, a.rect.y,
                (Color){255,255,255,music_ui_alpha});
}


void DrawUITools(void){
    
    MusicSet.tex = Volume[MusicPlayer.DBSet%4];
    
    AllRect = NoelRect;
    AllRect = RectContain(AllRect, MusicSet.rect);
    
    
    
    
    if(music_ui_enable)
        music_ui_alpha += (music_ui_alpha<255)*4*TimeRate;
    else
        music_ui_alpha -= (music_ui_alpha>0)*4*TimeRate;
    music_ui_alpha = set_in(music_ui_alpha, 0, 255);
    
    if(music_ui_alpha){
        
        if(NoelSideLeft)
            //左右侧UI位置不同
            MusicSet.rect = (Rectangle){
                NoelRect.x+NoelRect.width,
                NoelRect.y + 8,
                24,
                24
            };
        else
            MusicSet.rect = (Rectangle){
                NoelRect.x-24,
                NoelRect.y + 8,
                24,
                24
            };
        
        //GameOpener.rect = (Rectangle){MusicSet.rect.x,MusicSet.rect.y+25,MusicSet.rect.width,MusicSet.rect.height};
            
        UIButtonRun(MusicSet);
        //UIButtonRun(GameOpener);
        
        //DrawTexture(GameOpener.tex, GameOpener.rect.x, GameOpener.rect.y,(Color){255,255,255,music_ui_alpha});

        
        if(MusicPlayer.music.looping)
            DrawTexture(locked, MusicSet.rect.x, MusicSet.rect.y,
                        (Color){255,255,255,set_in(music_ui_alpha - 2*abs(timer%200-100), 0, 200)});
    }
}

#endif /* UI_h */
