//
//  SnakeGame.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/24.
//

#ifndef SnakeGame_h
#define SnakeGame_h

#include "stdlib.h"

struct {
    typedef enum{
        player,
        body,
        food,
        drug,
        empty
    } Map;

    enum {
        up,down,left,right
    } Way;
} snake[16][16]

int PlayerX,PlayerY;

void InitSnake(void){
    PlayerX = rand()%10+5;
    PlayerY = rand()%10+5;
    snake[PlayerX][PlayerY].Map = player;
    snake[PlayerX][PlayerY].Way = left;
}

void SnakeWalk(void){
    for(int i=0;i<16;++i)
        for(int j=0;i<16;++j){
            if(snake[i][j].Map == player){
                switch(snake[i][j].Way){
                    case up:
                        snake[i][j-1] = player;
                }
            }
        }
}

int tryTimes = 0;
void NewFood(void){
    if(tryTimes>1000000)
        printf("err");
    int x=rand()%14+1,y=rand()%14+1;
    if(snake[x][y].Map==empty)
        snake[x][y].Map = food;
    else{
        tryTimes+=1;
        NewFood();
    }
}


#endif /* SnakeGame_h */
