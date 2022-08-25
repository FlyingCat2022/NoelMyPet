//
//  LoadingAnimation.h
//  Somnambulism
//
//  Created on 2022/8/5.
//

#ifndef LoadingAnimation_h
#define LoadingAnimation_h

#include "raylib.h"
#include "../UI/Button/Music/Header.h"
#include "../Draw/Header.h"


int sleeping_delay = 150 , blink_timer = 0;

void blink_ani1(void){
    sleeping_delay += rand()%100;
    while (!WindowShouldClose() && timer < sleeping_delay){
        UpdateTimer();
        BeginDrawing();{
            ClearBackground((Color){0,0,0,0});
            DrawTexture(NoelSleeping[timer/30%3], 0, 12+0, WHITE);
        }EndDrawing();
        
        //运行音乐：如果音乐结束，准备重新载入音乐
        MusicPlayerRun();
    }
}

void blink_ani2(void){
    while (!WindowShouldClose() && blink_timer < 138){
        UpdateTimer();
        Image shadow = ImageFromImage(LoadImageFromTexture(NoelSleeping[0]), (Rectangle){0,138-blink_timer,72,blink_timer});//72*138
        Texture t;
        ImageColorBrightness(&shadow, 255);
        BeginDrawing();{
            ClearBackground((Color){0,0,0,0});
            DrawTexture(NoelSleeping[0], 0, 12+0, WHITE);
            DrawTexture(t = LoadTextureFromImage(shadow), 0, 12+ 138-blink_timer, WHITE);
        }EndDrawing();
        UnloadImage(shadow);
        UnloadTexture(t);
        
        
        //运行音乐：如果音乐结束，准备重新载入音乐
        MusicPlayerRun();
        blink_timer+=8;
    }
    blink_timer = 164;
    while (!WindowShouldClose() && blink_timer > 0){
        UpdateTimer();
        Image shadow = ImageFromImage(LoadImageFromTexture(NoelSleeping[0]), (Rectangle){0,0,72,138});//72*138
        Texture t;
        ImageColorBrightness(&shadow, 255);
        BeginDrawing();{
            ClearBackground((Color){0,0,0,0});
            DrawTexture(NoelSleeping[0], 0, 12+0, WHITE);
            DrawTexture(t = LoadTextureFromImage(shadow), 0, 12+0, WHITE);
        }EndDrawing();
        UnloadImage(shadow);
        UnloadTexture(t);
        //运行音乐：如果音乐结束，准备重新载入音乐
        MusicPlayerRun();
        blink_timer-=8;
    }
    blink_timer = 164;
    
    while (!WindowShouldClose() && blink_timer > 0){
        UpdateTimer();
        Image shadow = ImageFromImage(LoadImageFromTexture(NoelAni[0][1]) , (Rectangle){0,164-blink_timer,60,blink_timer});//72*138
        Texture t;
        ImageColorBrightness(&shadow, 255);
        BeginDrawing();{
            ClearBackground((Color){0,0,0,0});
            DrawTextureRec(NoelAni[0][1], (Rectangle){0,0,60,164}, (Vector2){0,12}, WHITE);
            DrawTexture(t = LoadTextureFromImage(shadow), 0, 12+164-blink_timer, WHITE);
        }EndDrawing();
        UnloadImage(shadow);
        UnloadTexture(t);
        
        
        //运行音乐：如果音乐结束，准备重新载入音乐
        MusicPlayerRun();
        blink_timer-=8;
    }
}

#endif /* LoadingAnimation_h */
