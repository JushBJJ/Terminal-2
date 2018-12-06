#include "../include/sysincludes.h"
#include "../include/Variables.h"
/* Echo File */
int echof(char *Filename){
    FILE *echoffile=fopen(Filename,"r");
    if(echoffile){
        printf("\x1b[1m\x1b[44m");
        while(fgets(_fc,MAXBUF,echoffile)){
            printf("%s",_fc);
        }
        printf("\x1b[0m");
        printf("\n");
        return 0;
    }
    else{
        PRINTERROR("UNABLE TO OPEN FILE!");
        return 1;
    }
}