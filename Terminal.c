#include "include/Variables.h"
#include "include/sysincludes.h"
#include "include/Commands.h"

int main(){
    for(;;){
        printf("%s::  ",CurrentDirectory);
        fgets(Input,MAXBUF,stdin);
        _NoNL(Input);
        _CheckCommand(Input);
    }
}