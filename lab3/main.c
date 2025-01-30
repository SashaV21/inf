#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "library.h"


int main(){
    int work = 1;
    int option = 0;
    int num;
    int *data = NULL;
    int option_2 = 0;
    int flag = 0; 
    int *individual = NULL;
    int num_ind = 0;

    while(work == 1){
        
        if(option == 0){
            system("clear");
            printf("1.Ввести массив \n");
            printf("2.Вывести массив \n");
            printf("3.Вывести второй массив \n");
            printf("4.Обработка массива \n");
            printf("5.Завершить работу\n");
            printf("=> ");
            scanf("%d",&option);
            
        }
         
        else if(option == 1){
            system("clear");
            num = 0;
            printf("сколько элементов будет в массиве? \n=> ");
            scanf("%d",&num);
            data =  malloc(num * sizeof(int));
            input(data,num);
            option = 0;
        }

        else if(option == 2){
            system("clear");
            printf("Ваш массив:\n ");
            output(data,num);
            option = 0;
            char *a = readline("");
            free(a);
        }

        else if(option == 3){
            if(flag == 1){
                system("clear");
                output(individual,num_ind);
                printf("\nНажмите Enter, чтобы вернуться назад\n");
                printf("          -----          \n");
                printf("        Enter  |         \n");
                printf("     <---------          \n");
                char *a = readline("");
                free(a);
                option = 0;
            }

            else{
                system("clear");
                printf("Для начала перейдите в раздел обработки массива и выберите пункт 'Проверка на уникальность'\n");
                printf("Нажмите Enter, чтобы вернуться назад\n");
                printf("          -----          \n");
                printf("        Enter  |         \n");
                printf("     <---------          \n");
                char *a = readline("");
                free(a);
                option = 0;
            }
        }




        else if(option == 4 && option_2 == 0){
            system("clear");
            printf("1.Добавить элемент по индексу \n");
            printf("2.Удалить элемент по индексу \n");
            printf("3.Проверка на уникальность\n");
            printf("4.Вернуться назад\n");
            printf("=> ");
            scanf("%d",&option_2);   
        }   
   
        else if(option == 4 && option_2 == 4){
            option = 0;
            option_2 = 0;
        }   



        else if(option == 4 && option_2 == 1){
            int value;
            int index;
            system("clear");
            printf("Под каким индексом вставить элемент (всего элементтов %d)\n=> ", num);
            scanf("%d",&index); 
            printf("Значение нового элемента\n=> ");
            scanf("%d",&value); 
            num++;
            data = realloc(data,sizeof(int) * num);
            input_index(data,num,index-1,value);
            option = 0;
            option_2 = 0;
        }  

        else if(option == 4 && option_2 == 2){
            int index_del;
            system("clear");
            printf("Индекс удаляемого элемента (всего элементтов %d)\n=> ", num);
            scanf("%d",&index_del); 
            num--;
            del_index(data,num,index_del - 1);
            data = (int*) realloc(data,sizeof(int) * num);
            option = 0;
            option_2 = 0;
        }  

        else if(option == 4 && option_2 == 3){
            individual = (int*) malloc(sizeof(int));
            num_ind = individual_v(data,num,individual);
            if(num_ind == 0){
                system("clear");
                printf("\nНе было выявлено повторяющихся элементов, нажмите enter, чтобы вернуться назад\n");
                printf("          -----          \n");
                printf("        Enter  |         \n");
                printf("     <---------          \n");
                char *a = readline("");
                free(a);
            }

            else{
                system("clear");
                printf("\nДанные успешно сохранены, нажмите enter, чтобы вернуться назад\n");
                printf("          -----          \n");
                printf("        Enter  |         \n");
                printf("     <---------          \n");
                char *a = readline("");
                free(a);
                flag = 1;
                num = num - num_ind;
                data = (int*) realloc(data,sizeof(int) * num);
            }
            
            option = 0;
            option_2 = 0;

        }  


        else if(option == 5){
            work = 0;
        }









    }







return 0;



}
   
