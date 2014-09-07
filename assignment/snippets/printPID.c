/**
 * This program demonstrates how `unistd.h` can be used to print the PID of this
 * program during execution, as well as that of its parent
 *
 * PID
 *  - 16 bit numbers
 *  - Sequentially assigned
 *  - Every process has a parent process except `init`
 *
 */
#include <stdio.h>
#include <unistd.h>


int main(){
    printf("I am a process with PID: %d\n", (int) getpid());
    printf("I am parent process with PID: %d\n", (int) getppid());
}
