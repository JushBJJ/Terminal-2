#pragma once
#include "sysincludes.h"
#include "Variables.h"
#include "stdfunctions.h"

/*****************************************    
*       Command function info
*
*       Type: int
*       Return: 0 on success 1 on function failed 2 on unknown command 3 on blank input 
*
******************************************/
#include "../Commands/pwd.c"
#include "../Commands/cd.c"
#include "../Commands/lf.c"
/*-----------------------------------*/
struct Commands{
    char    *Call;
    int     (*Command)();
};
struct Commands List[]={
    {"pwd",pwd},{"cd",cd},{"lf",lf},
};
enum{AOC=sizeof(List)/sizeof(List[0])};

int _CheckCommand(char *_IN){
    y=0;
    x=0;
    if(_IN[0]=='\0'||_IN[0]==' '){
        return 3;
    }
    CommandCall=strtok(_IN," ");
    Argument=strtok(NULL," ");
    for(x=0;x<AOC;x++){
        if(strcmp(CommandCall,List[x].Call)==0){
            return List[x].Command(Argument);
        }
    }
    return 2;
}