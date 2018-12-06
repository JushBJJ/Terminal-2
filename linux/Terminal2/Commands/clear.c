#include "../include/sysincludes.h"
#include "../include/Variables.h"

int clear(){
    for(x=0;x<100;x++){
        printf("\n");
    }
    for(x=0;x<100;x++){
        printf("\x1b[A");
    }
    return 0;
}
