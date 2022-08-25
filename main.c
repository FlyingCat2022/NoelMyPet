//
//  main.c
//  Somnambulism
//
//  Created on 2022/5/22.
//

#include "Header.h"

bool t;

sm st_mach = (sm){1,funcs[0]};
sm sm_music = (sm){1,funcs[0]};
void blink_ani(void);

int time_wait;
int ask_alpha = 0;

bool unshow_thoughts;
int emo_time = 0;
time_t timeset;
bool has_24=false,has_23=false,has_3=false;

int happyness,love;

char direct_game[11451];

int main(int argc,char *argv[]){
    
    SetPath(argv[0]);
    init_main();
    
    
    blink_ani1();
    loadData();
    blink_ani2();
    
    
        
    while (!WindowShouldClose()){
        
        sm_work(&st_mach, 1, -1);
        SetNoelSide();
        
        BeginDrawing();{
            ClearBackground((Color){0,0,0,0});
            DrawNoel();
            DrawUITools();
            UIDialog();
            
            
        }EndDrawing();
        
        MusicPlayerRun();

        if(inside_2d(GetMousePosition(), NoelRect))
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                st_mach.state = 2;
        if((inside_2d(GetMousePosition(), NoelRect) || inside_2d(GetMousePosition(), AllRect)) &&
           st_mach.state != 2)
            {music_ui_enable = true;st_mach.state = 3;UIDisapperDelay=timer+120;}
        else if(UIDisapperDelay < timer)
            music_ui_enable = false;

        
        if(DialogState == DialogAsk){
            
        }
        

        
        
        if(DialogState == DialogWaitToAsk ||
           DialogState == DialogWaitToSay ){
            if(time_wait == 0){
                if(DialogState == DialogWaitToAsk)DialogState = DialogAsk;
                if(DialogState == DialogWaitToSay){DialogState = DialogAsk;/*will_say = true;*/}
            }else time_wait -= 1;
        }
        
        MousePosBefore = MousePos;
        MousePos = GetMousePosition();
        
        time(&timeset);
        if(localtime(&timeset)->tm_hour == 3 && !has_3){ // && !will_show_say
            has_3 = true;has_24=false;has_23=false;
            dialog_now = night3[rand()%6];
            DialogState = DialogAsk;
            //will_say = true;
        }
        if(localtime(&timeset)->tm_hour == 0 && !has_3){
            has_3 = false;has_24=true;has_23=false;
            dialog_now = rand()%6;
            DialogState = DialogAsk;
            //will_say = true;
        }
        if(localtime(&timeset)->tm_hour == 23 && !has_3){
            has_3 = false;has_24=false;has_23=true;
            dialog_now = rand()%6;
            DialogState = DialogAsk;
            //will_say = true;
        }
        
        
    }

    CloseWindow();

    return 0;
}




//892112
//894166
//898759
//899760
//901065
//902260

