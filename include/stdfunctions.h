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

int ERROR(char *stream,char *Content){
    printf("\x1b[1ERROR: \x1b[31m%s\x1b[0m\n");
    return 0;
}

int _SetOutput(char *Output){
    LastOut=Output;
    return 0;
}