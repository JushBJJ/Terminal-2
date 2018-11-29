#include "sysincludes.h"
#include "Variables.h"
#include "stdfunctions.h"

/*****************************************    
*       Declaring Command functions
*
*       Type: int
*       Return: 0 on success 1 on fail
*
******************************************/

/*****************************************/

int pwd();


/*****************************************/

int pwd(){
    if(getcwd(CurrentDirectory,MAXBUF)==0){
        printf("Current Directory: %s\n",CurrentDirectory);
        return 0;
    }
    if(getcwd(CurrentDirectory,MAXBUF)==NULL){
        ERROR(CurrentDirectory,"UNABLE TO GET CURRENT DIRECTORY!");
        return 0;
    }
}
/*-----------------------------------*/
struct Commands{
    char    *Call;
    int     (*Command)();
};
struct Commands List[]={
    {"pwd",pwd},
};

enum{AmountOfComands=sizeof(List)/sizeof(List[0])};

int _CheckCommand(char *IN){
    for(int x=0;;x++){
        
    }
    for(int x=0;;x++){
        if(strcmp(IN,List[x].Call)==0){
            return List[x].Command();
            break;
        }
    }
}
