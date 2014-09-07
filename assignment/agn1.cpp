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


/*
 * This program is a replacement for the default command shell.
 * It will:
 *      1. Print a prompt `#`
 *      2. Read a command at the prompt
 *      3. `quit` terminates the shell
 *      4. `run <programname> [args]` executes `<programname>` with arguments `[args]`
 *          - Uses fork and exec to spawn a new process
 *          - Parent process will wait until child process completes
 *          - Displays error if cannot complete the process
 *      5. `background <programname> [args]` starts program, prints pid, and returns to prompt
 *      6. `murder <PID>` immediately terminates process with given `<PID>`                          */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators


/*----------------------------------------------------------------------------------------
 *   Arguments:   (char *):  Shell command to execute
 *                (char **): Arguments to cmd command
 *
 *      Return:   (int)      Returns the child_pid of the spawned process
 * Description:   This function spawns a new process via `fork` which returns
 *                the child process's ID to he parent, while
 *                returning a process ID of 0 to the child process (child_pid).
 *                This value is used by the function to either return the child_pid
 *                or exec a cmd via execvp
 *----------------------------------------------------------------------------------------*/
int spawn( char * cmd, char ** arg_list );

int run(char ** args);
int background(char ** args);

sig_atomic_t atomic = 0 ;
sig_atomic_t ChildExitStatus = 0 ;

void handler(int sigal_number){
    int exitStatus = 0 ;
    wait(&exitStatus);
    fprintf(stdout, "Child Exit: %d\n", exitStatus);
    ChildExitStatus = exitStatus;
}

int main (int argc, char ** argv){
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char prompt[] = "==> " ;                    // shell prompt

    // Signals set up
    struct sigaction sa ;          // sigaction sets the signal disposition
    memset(&sa, 0, sizeof(sa));    // Set memory area sa with size of sa to 0
    sa.sa_handler = &handler;      // Give struct member address to function to execute
    sigaction(SIGCHLD, &sa, NULL); // Signal SIGCHLD to parent after exec handler when child process completes

    // while not EOF (from input stream) or 'quit'
    while (!feof(stdin)) {

        // Print a prompt and wait (fgets) until input
        fputs (prompt, stdout);                 // prompt > stdout
        if (fgets (buf, MAX_BUFFER, stdin )) {  // read from input until '\n' or max buffer size reached

            arg = args;                         // use arg to iterate through args so args pointer not lost

            /* -----------------------------------------------------------------------------------
             *    strtok:  From the Docs
             * -----------------------------------------------------------------------------------
             * On the first call to strtok() the string to be parsed should be specified in str.
             * In each subsequent call that should parse the same string, str must be NULL.      */

            // Tokenize buf at the separator and assign to arg.
            // Each call to strtok returns a word until none left; return NULL
            *arg++ = strtok(buf,SEPARATORS);
            while ((*arg++ = strtok(NULL,SEPARATORS)));

            // If anything was read other than newline/whitespace/tab
            if (args[0]) {

                /* check for internal/external commands [clear, quit, run, background] */
                if (strcmp(args[0], "clear") == 0 ) {                // "clear" command
                    system("clear");
                    continue;
                }
                else if ( strcmp(args[0],"quit") == 0 ) break;        // "quit"  command

                else if ( strcmp(args[0],"run") == 0 ){               // "run"   command
                    // if command was supplied
                    if ( args[1] )
                        run(args);
                    // else tell user we need cmd arg
                    else{
                        fputs("Requires command to run", stderr);
                        continue ;
                    }
                }
                else if ( strcmp(args[0],"background") == 0 ){               // "run"   command
                    // if command was supplied
                    if ( args[1] )
                        background(args);
                    // else tell user we need cmd arg
                    else{
                        fputs("Requires command to run", stderr);
                        continue ;
                    }
                }

                /* else pass command onto OS (or in this instance, print them out) */
                else{
                    arg = args;                                 // Move ptr back to front of array
                    while (*arg) fprintf(stdout,"%s ",*arg++);  // Print *arg until null
                }
                fputs ("\n", stdout);                           // print a newline and repeat
            }
        }
    }
    return 0;
}


int run(char ** args){
    int child_wait;
    int child_pid = spawn( *(args+1), args+1 );

    wait(&child_wait);
    if ( WIFEXITED (child_wait) )
        fprintf(stdout, "Child process exited: %d\n", WEXITSTATUS(child_wait));
    return 0 ;
}

int background(char ** args){
    int child_wait;
    int child_pid = spawn( *(args+1), args+1 );

    return 0 ;
}


pid_t spawn( char * cmd, char ** arg_list ){
    // Declare and initialize.
    pid_t child_pid = fork(); // Fork a process

    /* check who's who and react accordingly */
    if ( child_pid != 0 ) return child_pid ;
    else{
        execvp(cmd, arg_list);
        // if control reached here, there was an error.
        fprintf(stderr, "Error occurred using execvp\n");
        abort();
        return 0;
    }
}

