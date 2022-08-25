//
//  ent.c
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/2.
//



#ifndef pl_ent_def_c
#define pl_ent_def_c

#include "Animation.h" 
#include "raylib.h"

int UIDisapperDelay = 30;

typedef struct{
    unsigned state;
    unsigned(**funcs)(void);
    void*data;
} sm;

unsigned(*funcs[2][256])(void);

void sm_work(sm*input,unsigned number,unsigned long long enabled){
    for(int i=0;i<number;++i)
        if(1<<i & enabled)
            input[i].state = input[i].funcs[input[i].state]();
}

unsigned walk(void){
    NoelAniPlaying = 0;
    printf("\n%f\n",GetWindowPosition().x);
    if(timer%30==0)
        SetWindowPosition(GetWindowPosition().x-8*NoelFliped, GetWindowPosition().y);
    if(rand()%1000>1 && GetWindowPosition().x>0)
        return 0;
    else
        if(rand()%1000>333)
            NoelFliped = !NoelFliped;
        return 1;
}

unsigned animation_time;

unsigned stand(void){
    NoelAniPlaying = 1;
    if(rand()%1000>997){
        animation_time = 200+rand()%200;
        return 5;
    }
    if(rand()%1000>998){
        animation_time = 100+rand()%100;
        return 4;
    }
    if(rand()%1000>998){
        animation_time = 100+rand()%100;
        return 6;
    }
    if(rand()%1000>1)
        return 1;
    if(GetWindowPosition().x<16 || rand()%1000>333)
        NoelFliped = - NoelFliped;
    return 0;
}

unsigned hover(void){
    NoelAniPlaying = 1;
    if(GetMouseX() > 36)
        NoelFliped = -1;
    if(GetMouseX() < 32)
        NoelFliped = 1;
    if(GetMouseX()>0 && GetMouseX()<64 &&
       GetMouseY()>0 && GetMouseY()<150)
        return 3;
    else
        return 1;
}

Vector2 MousePosBefore,MousePos;

unsigned click(void){
    UIDisapperDelay = 0;
    NoelAniPlaying = 2;
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if(MousePosBefore.x != GetMousePosition().x || 
           MousePosBefore.y != GetMousePosition().y)
            SetWindowPosition(GetWindowPosition().x - NoelRect.x + GetMouseX() - 30,GetWindowPosition().y - NoelRect.y + GetMouseY() - 80);
        return 2;
    }
    return 1;
}

unsigned sweep(void){
    NoelAniPlaying = 3;
    if(--animation_time)
        return 4;
    return 1;
}

unsigned blink(void){
    NoelAniPlaying = 10;
    if(--animation_time)
        return 5;
    return 1;
}

unsigned not_ani(void){
    NoelAniPlaying = 5;
    if(--animation_time)
        return 6;
    return 1;
}

unsigned(*funcs[2][256])(void) = {
    {
        walk,
        stand,
        click,
        hover,
        sweep,
        blink,
        not_ani
    }
};

#endif /* ent_def_h */
