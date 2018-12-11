#pragma once
#include "Variables.h"
int _NoNL(char *stream){
    for(int x=0;stream[x]!=0;x++){
        if(stream[x]=='\n'||stream[x]=='\r'){
            stream[x]=0;
            break;
        }
    }
    return 0;
}

int PRINTERROR(char *Content){
    printf("\x1b[1mERROR: \x1b[31m%s\x1b[0m\n",Content);
    return 0;
}
