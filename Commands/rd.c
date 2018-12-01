#include "../include/sysincludes.h"

int rd(char *DirectoryName){
    if(rmdir(DirectoryName)==0){
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO REMOVE DIRECTORY!");
        return 1;
    }
    return 1;
}