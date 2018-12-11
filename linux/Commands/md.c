#include "../include/sysincludes.h"
#include "../include/Variables.h"

int md(char *DirectoryName){
    char DN[10000];
    sprintf(DN,"%s",DirectoryName);
    if(mkdir(DN,ACCESSPERMS)==0){
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO MAKE DIRECTORY");
        return 1;
    }
    return 1;
}
