#include <stdio.h>
#include <stdlib.h>

//структура двусв. списка

struct node {
    char value;
    struct node *next;
    struct node *prew; 
};

//запись симоволов в список

void input(struct node *head, char a){
    while(head->next != NULL){
        head = head->next;
    }
    head->next = malloc(sizeof(struct node));
    head->next->prew = head;
    head = head->next;
    head->next = NULL;
    head->value = a;
}

//вывод списка

void output(struct node *head){
    printf("->");
    while(head != NULL){
        printf("%c", head->value);
        head = head->next;
    }
}

//удаление полиндромов

void del(struct node *head){
    int flag = 0;
    struct node *node_1 = head;
    struct node *node_2 = head;
    while(node_2->next != NULL && node_2->next->value != ' '){
        node_2 = node_2->next;
    }

    if(node_1->prew != NULL){
        node_1 = node_1->prew;
        if(node_1->prew != NULL){
            node_1 = node_1->prew;
            flag = 1;
        }
    }

    if(node_2->next != NULL){
        node_2 = node_2->next;
        if(node_2->next != NULL && flag == 0){
            node_2 = node_2->next;
        }
    }

    if(node_1->prew == NULL){
        node_1->value = ' ';
    }

    if(node_2->next == NULL){
        node_1->next = NULL;
    }

    else{
        node_1->next = node_2;
        node_2->prew = node_1;
    }
    
}

//проверка на полиндром

int check(struct node *head){
    struct node *node_1 = head;
    struct node *node_2 = head;
    int amount = 1;
    while(node_2->next != NULL && node_2->next->value != ' '){
        node_2 = node_2->next;
        amount++;
    }

    for(int i = 0; i < amount; i++){
        if(node_1->value != node_2->value){
            return 0;
        }
        node_1 = node_1->next;
        node_2 = node_2->prew;
    }

    del(head);
}

//разбиение списка на слова

void find_word(struct node *head){
    while(head != NULL){
        if(head->prew == NULL || head->prew->value == ' '){
            check(head);
        }
        head = head->next;
    }
}

//Отичска памяти



void funct(struct node **head){
    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    else if (head == NULL){
        printf("No elements to delete\n");
    }
    else{
        struct node *tmp = *head;
        while(tmp->next->next != NULL)
            tmp = tmp->next;
        free(tmp->next);
        tmp->next = NULL;
    }
}

void del2(struct node **head){
    if (*head != NULL){
        while((*head)->next != NULL)
            funct(head);
        funct(head);
    }
}

int main(){
    
    //создание и заполение списка

    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    head->prew = NULL;
    printf("=>");
    char a = getchar();
    if((int)a != 10){
        head->value = a;
    }
    while(1){
        a = getchar();
            if((int)a != 10){
                input(head, a);
            }
            else{
                break;
            }
    }
    
    //работа с полиндромами
    
    find_word(head);
    
    //если есть флаг в виде пробела вначале списка, то удаляем его
    
    if(head->value == ' '){
        head=head->next;
    }
    
    //выводим результирующий список

    output(head);

    

    del2(&head);
}
