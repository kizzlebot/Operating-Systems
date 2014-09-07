/**
 * This program demonstrates the use of the exec family of functions which
 * replaces the running process
 *     - Functions with p's
 *         - `execvp`
 *         - `execlp`
 *         - Accepts a program name (char *) and tries to run programs in $PATH
 *         - Those without the `p` must be given **full-path** as argument
 *     - Functions with v's
 *         - `execv`
 *         - `execvp`
 *         - `execve`
 *         - Argument to shell command is passed using a NULL terminated array of char *'s
 *     - Functions with l's
 *         - Arguments as varargs mechanism
 *
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    pid_t child_pid ;

    child_pid = fork();

    if ( child_pid != 0 ){
        printf("Daddy: %d\n", (int) getpid());
        printf("Kid: %d\n", (int) child_pid);
    }
    else{
        printf("\nKid: %d\n", (int) getpid());
        printf("Parent: %d\n", (int) getppid());
    }
}
