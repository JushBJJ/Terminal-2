#include "../include/stdfunctions.h"
int pwd(){
    if(getcwd(CurrentDirectory,MAXBUF)!=NULL){
        printf("\x1b[1mCurrent Directory: \x1b[0m%s\n",CurrentDirectory);
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO GET CURRENT DIRECTORY!");
        return 1;
    }
    return 1;
}