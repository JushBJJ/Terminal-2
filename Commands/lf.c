#include "../include/sysincludes.h"
#include "../include/stdfunctions.h"

int lf(){
    DIR *CurrDirectory=opendir(".");
    struct dirent *ep;
    if(CurrDirectory!=NULL){
        while(ep=readdir(CurrDirectory)){
            if(ep->d_type==DT_DIR){
                printf("\x1b[1m\x1b[42m");
            }
            printf("%s\x1b[0m\n",ep->d_name);
        }
        closedir(CurrDirectory);
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO OPEN DIRECTORY!");
        return 1;
    }
}