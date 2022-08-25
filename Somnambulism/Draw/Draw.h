//
//  Draw.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/3.
//

#ifndef Draw_h
#define Draw_h

#include "raylib.h"
#include "../Init/Texture.h"

int timer;

typedef enum{
    z_bg,
    z_entity,
    z_player,
    z_item,
    z_light,
    z_upper
}zorder;

typedef struct{
    Texture2D Texture2D;
    Vector2   Vector2;
    Color     Color;
} DrawArgs;

struct{
    int      len[z_upper+1];
    int      len_max[z_upper+1];
    DrawArgs*list[z_upper+1];
}DrawList;

const int len_max_default = 8;

void DrawZorder(zorder from,zorder to){
    for(zorder i = from;i <= to; ++i){
        for(int j = 0;j < DrawList.len[i]; ++j){
            DrawArgs t = DrawList.list[i][j];
            DrawTextureV(t.Texture2D, t.Vector2 , t.Color);
        }
    }
}

void NewDraw(zorder z,DrawArgs args){
    if(z > z_upper || z < 0) return;
    if(DrawList.len_max[z] > DrawList.len[z]){
        DrawList.list[z][DrawList.len[z]] = args;
        DrawList.len[z]+=1;
    }
    else{
        DrawArgs*t=malloc(sizeof(DrawArgs)*DrawList.len_max[z]*2);
        for(int i=0;i<DrawList.len_max[z];++i)t[i]=DrawList.list[z][i];
        free(DrawList.list[z]);
        DrawList.list[z]     = t;
        DrawList.len_max[z] *=1;
        DrawList.len[z]     +=1;
    }
}

void InitDraw(int* size_each,int len){
    for(zorder i=0;i<z_upper;++i){
        DrawList.len[i] = 0;
        if(i<len){
            DrawList.len_max[i] = size_each[i];
            DrawList.list[i]    = malloc(sizeof(DrawArgs)*size_each[i]);
        }
        else{
            DrawList.len_max[i] = len_max_default;
            DrawList.list[i]    = malloc(sizeof(DrawArgs)*len_max_default);
        }
    }
}

void ClearDraw(void){
    for(int i=0;i<z_upper+1;++i){
        for(int j=0;j<DrawList.len[i];++j)
            DrawList.list[i][j] = (DrawArgs){};
        DrawList.len[i] = 0;
    }
}

void CloseDraw(void){
    for(int i=0;i<z_upper+1;++i){
        free(DrawList.list[i]);
    }
}


Texture   TrashTex;
Image     TrashImage;
Rectangle NoelRect;


unsigned NoelAniPlaying;
bool     NoelFliped;

void DrawNoel(void){
    Rectangle r;
    if(!NoelFliped){
        r = FlameRect(NoelAni[0][NoelAniPlaying], NoelAniFrame[NoelAniPlaying], NoelAniSpeed[NoelAniPlaying]);
        DrawTextureRec(NoelAni[0][NoelAniPlaying],r ,GetRectPos(NoelRect) , WHITE);
    }
    else{
        r = FlameRect(NoelAni[1][NoelAniPlaying], NoelAniFrame[NoelAniPlaying], NoelAniSpeed[NoelAniPlaying]);
        DrawTextureRec(NoelAni[1][NoelAniPlaying],r ,GetRectPos(NoelRect) , WHITE);
    }
    NoelRect.width  = r.width;
    NoelRect.height = r.height;
}


#endif /* Draw_h */
