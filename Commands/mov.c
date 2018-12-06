#include "../include/sysincludes.h"
#include "../include/Variables.h"

int mov(char *fn, char *PATH){
    char FILEN[CHAR_MAX];
    char Contents[CHAR_MAX];
    char FILEPATH[CHAR_MAX];
    sprintf(FILEN,"%s.temp",FN);
    FILE *r=fopen(fn,"r");
    if(r){
        chdir(PATH)
        sprintf(FILEPATH,"%s/%s",PATH,FN);
        FILE *w=fopen(FILEN,"w");
        chdir(CurrentDirectory);
        while(fgets(Contents,BUFMAX,r)){
            fprintf(w,"%s",Contents);
        }
    }
}