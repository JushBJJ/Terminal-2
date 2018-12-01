#include "../include/sysincludes.h"

int rf(char *FileName){
    FILE *f=fopen(FileName,"r");
    if(f){
        fclose(f);
    }
    else{
        PRINTERROR("UNABLE TO FIND FILE!");
        return 1;
    }
    if(remove(FileName)==0){
        return 0;
    }
    else{
        PRINTERROR("UNEXPECTED ERROR!");
        return 1;
    }
    
}