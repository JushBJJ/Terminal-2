#include "sysincludes.h"

/*Limits*/
#ifndef CHAR_MAX
    #define CHAR_MAX 127
    #define INT_MAX 2147483647
    #define MAXBUF CHAR_MAX
#endif

/* Booleans */
#define bool _Bool
#define true 1
#define false 0

/* Strings */
static char CurrentDirectory[CHAR_MAX];
static char Input[CHAR_MAX];
static char *LastOut;
static char CommandCall[CHAR_MAX];
static char Argument[];

/* Temp */
extern char *Temp_Pointer;
extern char Temp_Array[CHAR_MAX];

/*Integers*/
int RequiredArgs=0;