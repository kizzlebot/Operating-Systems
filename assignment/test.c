#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

int a2i(char *s);
int main(){
    char * words = (char *) malloc(sizeof(char)*20);
    printf("Enter: ");
    scanf("%s", words);
    int rtn = atoi(words);
    printf("%d",rtn);
}

