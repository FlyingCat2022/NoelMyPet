//
//  Dialog.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/14.
//

#ifndef Dialog_h
#define Dialog_h

#include "dialog_text.h"
#include "string.h"
#include "../../Init/Path.h"

void display_text(char*text,int size,int spacing,Rectangle r,Color c);

enum{
    up,
    down
}selectedOne;
int ask_alpha;int emo_time;
int happyness;int love;


void InitDialog(void){
    char text[262144];text[0]='\0';
    for(int i=0;i<dialog_num;++i){
        strcat(text, d[dialog_num].words);
        strcat(text, d[dialog_num].ask[0]);
        strcat(text, d[dialog_num].ask[1]);
    }
    chinese = LoadFontEx(TextFormat("%sSourceHanSans-Normal.otf",MainPath), 64, codepoints=LoadCodepoints(text,&cp_count), cp_count);

}

const int    words_num;
const char** WordToDisplay;

void InitFont(void){
    char text[262144];text[0]='\0';
    for(int i=0;i<words_num;++i){
        strcat(text, WordToDisplay[i]);
    }
    chinese = LoadFontEx(TextFormat("%sSourceHanSans-Normal.otf",MainPath), 64, codepoints=LoadCodepoints(text,&cp_count), cp_count);

}

void DrawThoughts(enum emotion e);
void DrawWordsSay(void);
void DrawWordsAsk(bool select);
bool isSelected(void){return IsKeyPressed(KEY_Z) || IsKeyPressed(KEY_X);}


int time_wait;
Vector2 MousePosBefore;

void SetSelection(void){
if(EquV(MousePosBefore, GetMousePosition())){
    if(GetMouseY() > MusicSet.rect.y+54) selectedOne = down;
    if(GetMouseY() < MusicSet.rect.y+50) selectedOne = up;
}else{
    if(IsKeyDown(KEY_UP))   selectedOne = up;
    if(IsKeyDown(KEY_DOWN)) selectedOne = down;
}}

void UIDialog(void){
    Dialog dialog = d[dialog_now];
    switch(DialogState){
        case DialogSay:
            DrawWordsSay();
            if(isSelected()){
                if(d[dialog_now].ask[0][0]!='\0'){
                    DialogState = DialogWaitToAsk;
                    time_wait = d[dialog_now].ask_delay;
                    ask_alpha = 0;
                }
                else{
                    DialogState = DialogNULL;
                    happyness += d[dialog_now].happy_wait;
                    love      += d[dialog_now].love_wait;
                }
            }
            break;
            
        case DialogAsk:
            DrawWordsSay();
            DrawWordsAsk(selectedOne);
            
            SetSelection();
            
            if(ask_alpha>200 && isSelected() ){
                time_wait = d[dialog_now].re_delay[selectedOne];
                if(d[dialog_now].func[selectedOne])    d[dialog_now].func[selectedOne]();
                if(~d[dialog_now].result[selectedOne]) {dialog_now = d[dialog_now].result[selectedOne];DialogState=DialogWaitToSay;time_wait=d[dialog_now].re_delay[selectedOne];}
                else DialogState=DialogNULL;
                
                ask_alpha = 0;
            }
            break;
            
        case DialogWaitToSay:
            if(DialogDelayConter < timer)
                if(timer - DialogDelayConter > dialog.wait_max){
                    DialogState = DialogNULL;
                    love     += dialog.love_wait;
                    happyness+= dialog.happy_wait;
                }
            
            DrawThoughts(dialog.emo_d);
            if(inside_2d(GetMousePosition(), NoelRect)){
                if(((timer/15 - emo_time/15)/24%2)||
                   timer/15%8 == 0){ //如果动画演出结束
                    DialogState = DialogSay;
                }
            }
            break;
            
        case DialogWaitToAsk:
            DrawWordsSay();
            
            if(DialogDelayConter < timer)
                DialogState = DialogAsk;
            break;
            
        case DialogNULL:
            
            break;
    }
    
    
    
    
    
    
    
    
    /*if(dialog_state == dialog_say){

    }
    else if(!will_say){
        will_show_say = false;
    }else if(!tle){
        has_word = true;
        will_show_say = true;
        words = d[dialog_now].emo_d;
    }else{
        will_say = false;
        will_show_say = false;
    }
    
    if(dialog_state == dialog_ask){
        
    }
    if(has_word){
        if(!emo_time)
            emo_time = timer;
        if(timer/15%8 == 0)
            if(music_ui_alpha)
                has_word = false;
        
        
        if(timer - emo_time > d[dialog_now].wait_max){
            has_word   = false;
            tle        = true;
            happyness += d[dialog_now].happy_wait;
            love      += d[dialog_now].love_wait;
        }
    }
    else if(!will_show_say)
        emo_time = 0;
    */
}


void display_text(char*text,int size,int spacing,Rectangle r,Color c){
    int len,*cp = LoadCodepoints(text, &len);
    int start=0,line=0;
    int line_len_now = 0;
    
    for(int i=0;i<len;++i){
        int waste;
        if(cp[i] == GetCodepoint("\n", &waste)){
            DrawTextCodepoints(chinese, &cp[start], i-start, (Vector2){r.x, r.y+(line)*size}, size, spacing, c);
            start = i+1;
            line_len_now = 0;
            line+=1;
        }
        else{
            int index = GetGlyphIndex(chinese, cp[i]);
            line_len_now += (chinese.recs[index].width + chinese.glyphs[index].offsetX)*size*1.0/chinese.baseSize;
            if(line_len_now > r.width){
                DrawTextCodepoints(chinese, &cp[start], i-start-1, (Vector2){r.x, r.y+(line)*size}, size, spacing, c);
                start = i;
                line_len_now = 0;
                line+=1;
            }
        }
    }
    if(line_len_now != 0)
        DrawTextCodepoints(chinese, &cp[start], len, (Vector2){r.x, r.y+(line)*size}, size, spacing, c);
}

#endif /* Dialog_h */
