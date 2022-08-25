//
//  inc.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/3.
//

#ifndef inc_h
#define inc_h

#include "raylib.h"

bool inside_2d(Vector2 p,Rectangle r){
    if(p.x >= r.x         && p.y >= r.y &&
       p.x <= r.x+r.width && p.y <= r.y+r.height)
        return true;
    return false;
}

void Pass_ivob(void){}

float minf(float a,float b){return a<b?a:b;}

bool EquV(Vector2 a,Vector2 b){return (a.x == b.x)&&(a.y == b.y);}
Rectangle RectContain(Rectangle a,Rectangle b){
    float x,y,h,w;
    x = minf(a.x, b.x);
    y = minf(a.y, b.y);
    w = minf(a.x+a.width,  b.x+b.width)  - x;
    h = minf(a.y+a.height, b.y+b.height) - y;
    return (Rectangle){x,y,w,h};
}

Vector2 GetRectPos(Rectangle r){return (Vector2){r.x,r.y};}

int set_in(int i, int l,int r){
    if(i<l)return l;
    if(i>r)return r;
    return i;
}

int Flame(int speed,int num){
    return timer/speed%num;
}

int FlameWidth(Texture t,int flame_num){
    return t.width/flame_num;
}

Rectangle FlameRect(Texture t,int flame_num,int speed){
    return (Rectangle){
        t.width*Flame(speed, flame_num),
        0,
        t.width/flame_num,
        t.height
    };
}

const unsigned FPS = 30;
float TimeRate = 1;

#endif /* inc_h */
