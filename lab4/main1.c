#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>

#define DELIM " \t"
#define PROMPT "> "
#define N 2   

void add_space(char *word){
    int len = strlen(word);
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
    char *word = strtok(s, DELIM);
    
    if(word != NULL) {
        printf("\"");
        add_space(word);
        word = strtok(NULL, DELIM);
    }

    while (word != NULL) {
        printf(" ");
        add_space(word);
        word = strtok(NULL, DELIM);
    }
    printf("\"\n");
}

int main() {
    char *input = readline(PROMPT);
    while (input != NULL) {
        process(input);
        free(input);
        input = readline(PROMPT);
    }
    return 0;
}


