#include "../include/sysincludes.h"
#include "../include/Variables.h"
#include "../include/stdfunctions.h"

int help(){
    printf("Commands:\n"
            "cd      [Changes Directory]\n"
            "lf      [Prints out the list of files and sub directories]\n"
            "echof   [Prints out contents of a file]\n"
            "edit    [Edit a file]\n"
            "    +------ open (Opens a file)\n"
            "    +------ edit (Edit a file)\n"
            "    +------ add (Add a new line starting from the line chosen)\n"
            "    +------ remove (removes a line including its contents)\n"
            "    +------ new (Make a new file)\n"
            "    +------ exit (exit the editor)\n"
            "rf      [Removes a file]\n"
            "md      [Makes a directory]\n"
            "rd      [Removes a directory]\n"
            "clear   [Clears the screen]\n"
            "exit    [Exits the terminal]\n"
            "help    [Shows this text])\n");
    return 0;
}

/*Commands:
pwd     [Prints out the current working directory]
cd      [Changes Directory]
lf      [Prints out the list of files and sub directories]
echof   [Prints out contents of a file]
edit    [Edit a file]
    +------ open (Opens a file)
    +------ edit (Edit a file)
    +------ add (Add a new line starting from the line chosen)
    +------ remove (removes a line including its contents)
    +------ new (Make a new file)
    +------ exit (exit the editor)
rf      [Removes a file]
md      [Makes a directory]
rd      [Removes a directory]
clear   [Clears the screen]
exit    [Exits the terminal]
help    [Shows this text]*/