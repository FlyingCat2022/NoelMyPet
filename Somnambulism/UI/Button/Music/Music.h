//
//  Music.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/3.
//

#ifndef Music_h
#define Music_h

#include "raylib.h"
#include "inc.h"
#include "Draw.h"


bool tle=false;


char music_name[][256] = {
    "a.wav",
    "b.wav",
    "c.wav",
    "d.wav",
    "e.wav",
    "f.wav",
    "g.wav",
    "h.wav"
};
const int music_num = 9;

float db_set[] = {0,0.2,0.5,1};



struct{
    enum {
        mPause,
        mStop,
        mPlaying,
        mToSwitch,
        mSwitching,
        mToPlay,
        mToLoad
    }state;
    
    Music music;
    
    float len,played;
    float db;
    unsigned DBSet;
    int delay;
    
}MusicPlayer;

void MusicPlayerInit(void){
    InitAudioDevice();
    MusicPlayer.DBSet = 3;
    MusicPlayer.state = mToLoad;
}

void MusicPlayerRun(void){
    switch (MusicPlayer.state) {
        case mPause:
            break;
            
        case mStop:
            break;
            
        case mPlaying:
            
            SetMusicVolume(MusicPlayer.music, MusicPlayer.db=db_set[MusicPlayer.DBSet%4]);
            UpdateMusicStream(MusicPlayer.music);
            MusicPlayer.played = GetMusicTimePlayed(MusicPlayer.music);
            
            
            if(!IsMusicStreamPlaying(MusicPlayer.music))
                MusicPlayer.state = mToSwitch;
            break;
            
        case mToSwitch:
            
            set_in(MusicPlayer.db,0.01,1);
            SetMusicVolume(MusicPlayer.music, MusicPlayer.db-=0.005);
            UpdateMusicStream(MusicPlayer.music);
            
            if(MusicPlayer.db <= 0.005)
                MusicPlayer.state = mSwitching;
            break;
            
        case mSwitching:
            
            UnloadMusicStream(MusicPlayer.music);
            
            MusicPlayer.state = mToLoad;
            break;
            
        case mToLoad:
            
            MusicPlayer.music = LoadMusicStream(TextFormat("%sBGM%c%s",MainPath,PathBreak,music_name[rand()%music_num]));
            MusicPlayer.music.looping = false;
            PlayMusicStream(MusicPlayer.music);
            
            MusicPlayer.state = mPlaying;
            break;
        default:
            break;
    }
}


#endif /* Music_h */
