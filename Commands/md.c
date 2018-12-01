#include "../include/sysincludes.h"

int md(char *DirectoryName){
    if(mkdir(DirectoryName)==0){
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO MAKE DIRECTORY");
        return 1;
    }
    return 1;
}