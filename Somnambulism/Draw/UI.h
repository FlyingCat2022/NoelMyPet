//
//  UI.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/20.
//

#ifndef UIDraw_h
#define UIDraw_h







UIButton GameOpener = {
    .func = {
        RunGame
    }
};

void SetFuncs(UIButton*a){
    for(int i=0;i<7;++i)
        if(a->func[i] == NULL)
            a->func[i] = Pass_ivob;
}

Rectangle AllRect;

void InitUI(void){
    SetFuncs(&MusicSet);
    SetFuncs(&GameOpener);
    
    GameOpener.tex = booting;
}



void DrawUIDialog(void){
    switch(DialogState){
        case DialogSay:
            
            break;
        case DialogAsk:
            
            break;
        case DialogWaitToSay:
            
            break;
        case DialogWaitToAsk:
            
            break;
        case DialogNULL:
            
            break;
    }
}

void DrawThoughts(enum emotion e){
    if(!((timer/15 - emo_time/15)/24%2))
        DrawTexture(something[timer/15%8], NoelRect.x + NoelRect.width/2, 0, WHITE);
    else
        DrawTexture(emo[e], NoelRect.x + NoelRect.width/2, 0, WHITE);
}
/*
 if(NoelSideLeft)
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
 */
void DrawWordsSay(void){
    DrawTexture(Talk[!NoelSideLeft], MusicSet.rect.x - (!NoelSideLeft)*284, MusicSet.rect.y,
        (Color){255,255,255,music_ui_alpha});
    display_text(d[dialog_now].words, 16, 0,
        (Rectangle){MusicSet.rect.x+51 - (!NoelSideLeft)*294, MusicSet.rect.y+51,225, 130},
        (Color){0,0,0,music_ui_alpha});
}

Vector2 SelectDrawPos = (Vector2){10,40};

void DrawWordsAsk(bool select){
    if(NoelSideLeft)
        SelectDrawPos = (Vector2){10,40};
    else
        SelectDrawPos = (Vector2){100,40};
    DrawTextureV(selection, (Vector2){SelectDrawPos.x,SelectDrawPos.y+20}, (Color){255,255,255,((ask_alpha+=6)>255?255:(ask_alpha))-(255-music_ui_alpha)});
    if(select)
        DrawTextureV(selected, (Vector2){SelectDrawPos.x+20,SelectDrawPos.y+35},
                     (Color){255,255,255,set_in((set_in(ask_alpha+=3,0,255))-4*abs(timer%60-30)-(255-music_ui_alpha),0,255)});
    else
        DrawTextureV(selected, (Vector2){SelectDrawPos.x+20,SelectDrawPos.y+35+16},
                     (Color){255,255,255,set_in((set_in(ask_alpha+=3,0,255))-4*abs(timer%60-30)-(255-music_ui_alpha),0,255)});
    DrawTextEx(chinese, d[dialog_now].ask[0],
               (Vector2){SelectDrawPos.x+128-MeasureTextEx(chinese, d[dialog_now].ask[0], 16,0).x/2,SelectDrawPos.y+35},
               16, 0, (Color){255,255,255,((ask_alpha+=3)>255?255:(ask_alpha+=3))-(255-music_ui_alpha)});
    //20->236
    DrawTextEx(chinese, d[dialog_now].ask[1],
               (Vector2){SelectDrawPos.x+128-MeasureTextEx(chinese, d[dialog_now].ask[1], 16,0).x/2,SelectDrawPos.y+35+16},
               16, 0, (Color){255,255,255,((ask_alpha+=3)>255?255:(ask_alpha+=3))-(255-music_ui_alpha)});
}

#endif /* UI_h */
