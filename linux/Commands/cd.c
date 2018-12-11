#include "../include/Variables.h"
#include "../include/sysincludes.h"

int cd(char *_DIRECTORY){
    ReturnResult=chdir(_DIRECTORY);
    if(ReturnResult==0){
        return 0;
    }
    else{
        PRINTERROR("INVAILD DIRECTORY!");
        return 1;
    }
}