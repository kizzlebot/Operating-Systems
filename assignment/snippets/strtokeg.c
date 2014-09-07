/********************************************************************
   Version: 1.0
   Date:    September 2014
   Author:  James J. Choi
            College of Engineering and Computer-Science
            University of Central Florida
            jchoi2012@knights.ucf.edu

   Copyright (c) James J Choi, 2014. All rights reserved.

   This code can be used for any purpose, but no warranty,
   explicit or implicit, is provided.
 *******************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators


/*
 * This program :w
 *
 *
 */

/*
 * Prototypes
 */
int spawn( char * cmd, char ** arg_list );


int main (int argc, char ** argv){
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = "==> " ;                    // shell prompt
    int child_pid ;
    // while not EOF (from input stream) or 'quit'
    while (!feof(stdin)) {

        // Print a prompt and wait (fgets) until input
        fputs (prompt, stdout);                            // prompt > stdout
        if (fgets (buf, MAX_BUFFER, stdin )) {             // read a line into buf

            // Upon receiving an input, tokenize at the whitespaces, tabs, or newlines and read into buf
            arg = args;                                 // use arg as array so initial point not lost
            *arg++ = strtok(buf,SEPARATORS);            // tokenize first line of input at SEPARATORS and fill buf
            while ((*arg++ = strtok(NULL,SEPARATORS))); // While NULL; strtok tokenizes a NULL value until use enters something
            // If anything was read other than newline/whitespace/tab
            if (args[0]) {                              // if there's anything there

                /* check for internal/external command */
                if (!strcmp(args[0], "clear")) {        // "clear" command
                    system("clear");
                    continue;
                }

                if (!strcmp(args[0],"quit"))            // "quit" command
                    break;                              // break out of 'while' loop

                // If user entered 'run' cmd
                if (!strcmp(args[0],"run")){
                    // If user specified shell cmd
                    if ( args[1] ) {
                        child_pid = spawn(args[1], args+2);     // vp - Shell cmd + NULL terminated array argument
                        printf("%d", child_pid);
                    }
                }

                /* else pass command onto OS (or in this instance, print them out) */
                // arg = args;                                 // Move ptr back to front of array
                // while (*arg) fprintf(stdout,"%s ",*arg++);  // Print *arg until null
                fputs ("\n", stdout);                       // print a newline and repeat
            }
        }
    }
    return 0;
}





int spawn( char * cmd, char ** arg_list ){
    // Declare
    pid_t child_pid ;

    // Fork it
    child_pid = fork();
    // check who's who and react accordingly
    if ( child_pid != 0 ){
        return child_pid ;
    }else{
        execvp(cmd, arg_list);
        fprintf("stderr", "Error occurred using execvp");
        abort();
    }
}

