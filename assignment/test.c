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
    unsigned int result = a2i(words);
    printf("%d",result);
}

int a2i(char *s){
    int len = strlen(s);
    unsigned int sum = 0 ;
    int i = 0 ;
    char * t = s ;
    for ( i = len ; i > -1 ; i-- ){
        printf('%s',*s);
    }
    return sum ;
}
