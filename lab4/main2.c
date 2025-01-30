#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include "library.h"

#define DELIM " \t"
#define PROMPT "> "
#define N 2   

void add_space(char *word){
    int len = strlen2(word);
    int counter = -1;
    for(int i = 0;i < len; i++){
        counter++;
        if(counter == N){
            printf(" ");
            counter = 0;
        }
        printf("%c", word[i]);
    }
}

void process(const char *str) {
    char *s = strdup(str);    
    char *word = strtok2(s, DELIM);
    
    if(word != NULL) {
        printf("\"");
        add_space(word);
        word = strtok2(NULL, DELIM);
    }

    while (word != NULL) {
        printf(" ");
        add_space(word);
        word = strtok2(NULL, DELIM);
    }
    printf("\"\n");
}

int main() {
    char *input = readline2(PROMPT);
    while (input != NULL) {
        process(input);
        free(input);
        input = readline2(PROMPT);
    }
    return 0;
}


