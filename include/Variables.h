#pragma once
#include "sysincludes.h"
/*****************************/
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
/*****************************/
/*Limits*/
#ifndef CHAR_MAX
    #define CHAR_MAX 127
    #define INT_MAX 2147483647
    #define MAXBUF CHAR_MAX
#endif

/* Booleans */
bool ContainsCharacters=false;

/* Strings */
static char CurrentDirectory[CHAR_MAX];
static char Input[CHAR_MAX];
static char *LastOut;
char *CommandCall;
char *Argument;
/* Temp */
extern char *Temp_Pointer;
extern char Temp_Array[CHAR_MAX];
int x=0;
int y=0;

/*Integers*/
int RequiredArgs=0;
int ReturnResult=0;
