/*************
 * Imported from https://github.com/JushBJJ/Edit
 * ***********/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
static char Input[CHAR_MAX];
static char *EDITCommand;
static char *EDITArgument;
static char _FileContents[CHAR_MAX];
static char *LE;
bool exitYes=false;
bool FileOpened=false;
static char FileName[CHAR_MAX];
char *tempLineHolder[100];
int Chars;
FILE *__read;
FILE *_append;
/* Not Commands */
int WriteHashTag();
int _Load();
int Split();
int CheckCommand();
int _Error();
int _SetLastError();
char * _GetLastError();
int reprint();
/*Commands */
int _OpenFile();
int _EditFile();
int _AddLine();
int _RemoveLine();
int _New();
int _exitedit();

struct EDITCommands{
    const char *Call;
    int(*CommandCall)();
};
struct EDITCommands _EDITList[]={
    {"open",_OpenFile},{"edit",_EditFile},{"add",_AddLine},{"remove",_RemoveLine},{"new",_New},{"exit",_exitedit},
};
enum{AmountOfCommands=sizeof(_EDITList)/sizeof(_EDITList[0])};
int edit(){
    printf("Loading...\n");
    _SetLastError("");
    for(;;){
        if(exitYes==true){
            goto EDITEXIT;
        }
        _Load();
        fgets(Input,sizeof(Input),stdin);
        Split();
        CheckCommand();
    }
    getchar();
    EDITEXIT:
    for(x=0;x<100;x++){
        printf("\n");
    }
    for(x=0;x<100;x++){
        printf("\x1b[A");
    }
    exitYes=false;
    return 0;
}

int _exitedit(){
    exitYes=true;
}


int _New(){
    _SetLastError("File Name: ");
    reprint();
    fgets(Input,sizeof(Input),stdin);
    Input[strcspn(Input,"\r\n")]=0;
    sprintf(FileName,"%s",Input);
    FILE *f=fopen(FileName,"a");
    fclose(f);
    _SetLastError("Success!");
    return 0;
}

int _RemoveLine(){
    bool exists=false;
    if(FileOpened==false){
        _SetLastError("No file was opened yet!");
        return 0;
    }
    /*------------*/
    _SetLastError("File Line: ");
    reprint();
    int Line=0;
    char Input[CHAR_MAX];
    fgets(Input,sizeof(Input),stdin);
    Line=atoi(Input);
    int x=0;
    /*------------*/
    unsigned char TempFileName[10000];
    unsigned char Contents[10000];
    sprintf(TempFileName,"%s.temp",FileName);
    FILE *tempfile=fopen(TempFileName,"w");
    __read=fopen(FileName,"r");
    while(fgets(Contents,sizeof(Contents),__read)){
        if(x==Line){
            exists=true;
        }
        else{
            fprintf(tempfile,"%s",Contents);
        }
        x++;
    }
    fclose(__read);
    fclose(tempfile);
    if(exists==false){
        _SetLastError("Unable to find line given!");
        remove(TempFileName);
        return 0;
    }
    __read=fopen(TempFileName,"r");
    tempfile=fopen(FileName,"w");
    while(fgets(Contents,sizeof(Contents),__read)){
        fprintf(tempfile,"%s",Contents);
    }
    fclose(__read);
    fclose(tempfile);
    remove(TempFileName);
    _SetLastError("Success!");
    return 0;
}
int _AddLine(){
    bool exists=false;
    if(FileOpened==false){
        _SetLastError("No file was opened yet!");
        return 0;
    }
    _SetLastError("File Line: ");
    reprint();
    /*-------------------------*/
    char TempFileName[10000];
    char Input[10000];
    char Contents[10000];
    int Line=0;
    int start=0;
    sprintf(TempFileName,"%s_temp.temp",FileName);
    FILE *__readfile=fopen(FileName,"r");
    FILE *overwrite=fopen(TempFileName,"w");
    fgets(Input,sizeof(Input),stdin);
    if(Input[0]=='-'){
        printf("True\n");
        start=1;
        if(start==1){
            printf("Start is 1\n");
        }
        Line=999999999;
        if(Line=999999999){
            printf("Line is 999999999\n");
        }
    }
    else{
        Line=atoi(Input);
    }
    int x=0;
    if(start==1){
        printf("Start is 1\n");
    }
    while(fgets(Contents,sizeof(Contents),__readfile)){
        if(start==1&&exists==false){
            fprintf(overwrite," \n");
            exists=true;
        }
        fprintf(overwrite,"%s",Contents);
        if(x==Line){
            fprintf(overwrite,"\n");
            exists=true;
        }
        x++;
    }
    if(strcmp(Contents,"")==0){
        fprintf(overwrite,"\n");
        exists=true;
    }
    fclose(__readfile);
    fclose(overwrite);
    if(exists==false){
        _SetLastError("Invaild line!");
        remove(TempFileName);
        return 0;
    }
    skip:
    __readfile=fopen(TempFileName,"r");
    overwrite=fopen(FileName,"w");
    while(fgets(Contents,sizeof(Contents),__readfile)){
        fprintf(overwrite,"%s",Contents);
    }
    fclose(__readfile);
    fclose(overwrite);
    remove(TempFileName);
    return 0;
}

int _EditFile(){
    bool exists=false;
    if(FileOpened==false){
        _SetLastError("No file was opened yet!");
        return 0;
    }
    _SetLastError("File Line: ");
    reprint();
    /*-------------------------*/
    char Input[CHAR_MAX];
    int intinput=0;
    fgets(Input,sizeof(Input),stdin);
    intinput=atoi(Input);
    _SetLastError("File Contents: ");
    reprint();
    fgets(Input,sizeof(Input),stdin);
    printf("Contents: %s\tLine: %d\n",Input,intinput);
    /*-------------------------*/
    char FileContents[10000];
    char TempFileComtents[10000];
    char TempFileName[10000];
    int x=0;
    sprintf(TempFileName,"%s.temp",FileName);
    FILE *WriteToTempFile;
    FILE *WriteToFile;
    __read=fopen(FileName,"r");
    WriteToTempFile=fopen(TempFileName,"w");

    /* Write to temp file */
    while(fgets(FileContents,sizeof(FileContents),__read)){
        if(x==intinput){
            fprintf(WriteToTempFile,"%s",Input);
            exists=true;
        }
        else{
            fprintf(WriteToTempFile,"%s",FileContents);
        }
        x++;
    }
    fclose(__read);
    fclose(WriteToTempFile);
    if(exists==false){
        _SetLastError("Error: Invaild Line");
        remove(TempFileName);
        return 0;
    }
    /*Transfer the contents from the temp file into the actual file */
    WriteToFile=fopen(FileName,"w");
    __read=fopen(TempFileName,"r");
    while(fgets(FileContents,sizeof(FileContents),__read)){
        fprintf(WriteToFile,"%s",FileContents);
    }
    fclose(__read);
    fclose(WriteToFile);
    remove(TempFileName);
    _SetLastError("Success!");
    return 0;
}
int _OpenFile(char *FN){
    __read=fopen(FN,"r");
    if(__read){
        FileOpened=true;
        sprintf(FileName,"%s",FN);
        _SetLastError("\x1b[32mOpened file!");
    }
    else{
        _SetLastError("Unable to open file!");
    }
    fclose(__read);
    return 0;
}
int _SetLastError(char *Output){
    LE=Output;
    return 0;
}
char *_GetLastError(){
    return LE;
}
int _Error(char *Output, int ExitProgram){
    printf("\x1b[0m\x1b[1mERROR: \x1b[31m%s\n\x1b[0m",Output);
    if(ExitProgram==true){
        exit(0);
    }
    if(ExitProgram==false){
        _SetLastError(Output);
    }
    return 0;
}

int CheckCommand(){
    for(int x=0;x<AmountOfCommands;x++){
        if(Input[0]=='\0'||Input[0]==' '){
            goto a;
            break;
        }
        if(strcmp(EDITCommand,_EDITList[x].Call)==0){
            _EDITList[x].CommandCall(EDITArgument);
            return 0;
        }  
    }
    a:
    _SetLastError("Unknown Command!");
    return 0;
}

int Split(){
    Input[strcspn(Input,"\r\n")]=0;
    EDITCommand=strtok(Input," ");
    EDITArgument=strtok(NULL,";");
    return 0;
}
int WriteHashTag(){
printf("\n\n");
    for(int x=0;x<100;x++){
        printf("\x1b[37m\x1b[49m#");
    }
    return 0;
}
int _Load(){
    printf("\x1b[37m\x1b[49m");
    for(int x=0;x<96;x++){
        printf("\n ");
    }
    if(FileOpened==true){
        __read=fopen(FileName,"r");
        if(__read){
            printf("\n");
            int x=0;
            while(fgets(_FileContents,sizeof(_FileContents),__read)){
                printf("\x1b[44m[%d]  %s",x,_FileContents);
                x++;
            }
            fclose(__read);
        }
        else{
            printf("FileName : %s\n",FileName);
            _SetLastError("\x1b[1m\x1b[0mError: \x1b[31mUnable to open file for some reason. (Maybe the file has unsupported text memory error. Please try again.");
        }
    }
    WriteHashTag();
    printf("\n\x1b[37m\x1b[1mOutput: %s \x1b[0m\n",_GetLastError());
    WriteHashTag();
    printf("\x1b[1m\n> \x1b[34m");
    return 0;
}

int reprint(){
    printf("\x1b[37m\x1b[49m");
    for(int x=0;x<96;x++){
        printf("\n ");
    }
    if(FileOpened==true){
        __read=fopen(FileName,"r");
        if(__read){
            printf("\n");
            int x=0;
            while(fgets(_FileContents,sizeof(_FileContents),__read)){
		printf("\x1b[44m[%d]  %s",x,_FileContents);
                x++;
            }
            fclose(__read);
        }
        else{
            printf("FileName : %s\n",FileName);
            _SetLastError("\x1b[1m\x1b[0mError: \x1b[31mUnable to open file for some reason. (Maybe the file has unsupported text memory error. Please try again.");
        }
    }
    WriteHashTag();
    printf("\n\x1b[37m\x1b[1mOutput: %s \x1b[0m\n",_GetLastError());
    WriteHashTag();
    printf("\x1b[1m\n> \x1b[34m");
    return 0;
}
