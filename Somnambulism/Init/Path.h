//
//  Path.h
//  Somnambulism
//
//  Created by 洪润孜 on 2022/8/18.
//

#ifndef Path_h
#define Path_h

#include "stdio.h"
#include "string.h"

char MainPath[4096];

void SetPath(const char* p){
    int len = (int)(strlen(p));
    for(int i=0;i<len;--i)
        if(p[i] != '\\' && p[i] != '/'){
            MainPath[i] = p[i];
            break;
        }
}

void RunGame(void){
    
}

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
const char PathBreak = '\\';
#else
const char PathBreak = '/';
#endif



#endif /* Path_h */
