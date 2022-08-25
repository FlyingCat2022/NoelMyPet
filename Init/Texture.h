//
//  texture.c
//  Somnambulism
//
//  Created on 2022/7/5.
//

#ifndef loader_tex
#define loader_tex

#include "raylib.h"
#include "../Header.h"
#include "Path.h"


typedef struct{int x,y;} img_size;

Texture NoelSleeping[3];

//216;138
void SetNoelSleeping(void){
    Image img = LoadImage(TextFormat("%ssleeping.png",MainPath));
    NoelSleeping[0] = LoadTextureFromImage(ImageFromImage(img, (Rectangle){0,0,72,138}));
    NoelSleeping[1] = LoadTextureFromImage(ImageFromImage(img, (Rectangle){72,0,72,138}));
    NoelSleeping[2] = LoadTextureFromImage(ImageFromImage(img, (Rectangle){144,0,72,138}));
    UnloadImage(img);
}


const int NoelAniNum = 11;
Texture   NoelAni[2][NoelAniNum];
char      NoelAniName[NoelAniNum][256] = {
    "Noel_Walk.png",
    "Noel_Stand2.png",
    "click.png", //2
    "sweep2.png",
    "see_around.png",
    "noticed.png", //5
    "cute1.png",
    "cute2.png",
    "seek1.png",  //8
    "seek2.png",
    "Noel_Stand.png"
};
int NoelAniFrame[NoelAniNum] = {
    6,
    2,
    1,
    3,
    5,
    9,
    1,
    1,
    1,
    1,
    3
};
int NoelAniSpeed[NoelAniNum] = {
    30,
    20,
    114514,
    10,
    20,
    30,
    0,
    0,
    0,
    0,
    20
};

void SetNoelImage(void){
    for(int i=0;i<NoelAniNum;++i){
        Image t = LoadImage(TextFormat("%s%s",MainPath,NoelAniName[i]));
        NoelAni[0][i] = LoadTextureFromImage(t);
        ImageFlipHorizontal(&t);
        NoelAni[1][i] = LoadTextureFromImage(t);
        UnloadImage(t);
    }
    //324*164
}

Texture Volume[4],locked;

void SetUITexture(void){
    locked = LoadTexture(TextFormat("%ssound%clocked.png",MainPath,PathBreak));
    locked.width = 24;
    locked.height= 24;
    for(int i=0;i<4;++i){
        Volume[i] = LoadTexture(TextFormat("%ssound%c%d_sound.png",MainPath,PathBreak,i));
        Volume[i].width = 24;
        Volume[i].height = 24;
    }
    
}

Texture Talk[2],selection,selected;

void SetTalkTexture(void){
    Talk[0] = LoadTexture(TextFormat("%stalk-l.png",MainPath));
    Talk[1] = LoadTexture(TextFormat("%stalk-r.png",MainPath));
    
    Talk[0].width = Talk[1].width = 308; //1232,676
    Talk[0].height = Talk[1].height = 169;
    
    selection = LoadTexture(TextFormat("%sselection.png",MainPath));
    selected  = LoadTexture(TextFormat("%sselect.png",MainPath));
}

//11*11;7*8
Texture something[8],notice[6],emo[12];

void SetEmoTexture(void){
    Image sth = LoadImage(TextFormat("%stsi%cspeech_bubble_animation-11x11.png",MainPath,PathBreak));
    for(int i=0;i<8;++i){
        something[i] = LoadTextureFromImage(ImageFromImage(sth, (Rectangle){11*i,0,11,11}));
        something[i].width = something[i].height = 22;
    }
    UnloadImage(sth);
    
    sth = LoadImage(TextFormat("%stsi/exclamation-7x8.png",MainPath,PathBreak));
    for(int i=0;i<6;++i){
        notice[i] = LoadTextureFromImage(ImageFromImage(sth, (Rectangle){7*i,0,7,8}));
        notice[i].width = 14;something[i].height = 16;
    }
    UnloadImage(sth);
    
    sth = LoadImage(TextFormat("%stsi/tiny_speech_indicators-11x11.png",MainPath,PathBreak));
    for(int i=0;i<8;++i){
        emo[i] = LoadTextureFromImage(ImageFromImage(sth, (Rectangle){11*i,0,11,11}));
        emo[i].width = emo[i].height = 22;
    }
    UnloadImage(sth);
    
    emo[9] = LoadTexture(TextFormat("%stsi/tiny_chat_icon.png",MainPath,PathBreak));
    emo[9].width = 20; emo[9].height = 22;
}

Texture booting;

void SetBootingTexture(void){
    booting = LoadTexture(TextFormat("%sbooting.png",MainPath));
    booting.width = booting.height = 24;
}

#endif
