#include "include/sysincludes.h"
#include "include/Variables.h"
#include "include/Commands.h"
#include "include/stdfunctions.h"

int main(){
    HANDLE _OUTOPTION=GetStdHandle(STD_OUTPUT_HANDLE);
    static DWORD _Mode=0;
    GetConsoleMode(_OUTOPTION,&_Mode);
    _Mode|=ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(_OUTOPTION,_Mode);
    for(;;){
        if(getcwd(CurrentDirectory,MAXBUF)==NULL){
            PRINTERROR("UNABLE TO GET CURRENT DIRECTORY!");
        }
        printf("%s::  \x1b[34m",CurrentDirectory);
        fgets(Input,MAXBUF,stdin);
        printf("\x1b[0m");
        _NoNL(Input);
        ReturnResult=_CheckCommand(Input);
        if(ReturnResult==2){
            PRINTERROR("UNKNOWN COMMAND!");
        }
        ContainsCharacters=false;
    }
}