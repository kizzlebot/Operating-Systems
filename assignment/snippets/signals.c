#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

/*
 * Signals are asynchronous messages sent to a process
 *  - receiver handles message immediately
 *  - disposition
 *      - default if not specified
 *      - if signal handler supplied, will execute immediately and resume on return
 *          - SIGTERM and SIGKILL reserved for process kill
 *          - SIGUSR1 and SIGUSR2 are used for sending commands
 *
 *
 */

// No two processes can change this number at the same time
sig_atomic_t atomic = 0 ;

void handler(int sigal_number){
    ++atomic;
}
int main(){

    struct sigaction sa ;          // sigaction sets the signal disposition
    memset(&sa, 0, sizeof(sa));    // Set memory area sa with size of sa to 0
    sa.sa_handler = &handler;      // Give struct member address to function to execute
    sigaction(SIGUSR1, &sa, NULL); //

    int i = 0 ;
    int j = 0 ;
    while(1){
        scanf("%d",  &j);
        if ( j == 0 ) break;
    }

    return 0 ;
}
