#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "workwithfile.h"

int main()
{
    int user_choice;
    int prog_choice;
    int progflag = 0;
    while (progflag == 0)
    {
        system("clear");
        printf("0 - exit \n");
        printf("1 - programm one \n");
        printf("2 - programm two \n");
        printf("choose your hero: \n");
        scanf("%d", &prog_choice);
        switch (prog_choice)
        {
        case 0:
        {
            progflag = 1;
            break;
        }
        case 1:
        { // for prog 1
            int flag = 0;
            while (flag == 0)
            {
                system("clear");
                printf("1 - exit \n");
                printf("2 - qsort \n");
                printf("3 - comb sort \n");
                printf("4 - shell sort \n");
                printf("choose your hero: \n");
                scanf("%d", &user_choice);
                switch (user_choice)
                {
                case 1:
                {
                    flag = 1;
                    break;
                }
                case 2:
                {
                    system("clear");
                    printf("how much lines?\n");
                    int num;
                    scanf("%d", &num);
                    struct Auto *car = NULL;
                    car = malloc(sizeof(struct Auto) * num);
                    fromF(car, num);

                    system("clear");
                    printf("sorting criterion\n");
                    printf("1 - model \n");
                    printf("2 - full_name \n");
                    printf("3 - distance \n");
                    printf("choose your hero: \n");
                    int form_sort;
                    scanf("%d", &form_sort);

                    system("clear");
                    printf("sorting direction\n");
                    printf("1 - direct \n");
                    printf("-1 - reverse \n");
                    int route;
                    scanf("%d", &route);

                    sort_q(car, num, form_sort, route);
                    toF(car, num);
                    free(car);
                    break;
                }
                case 3:
                {
                    system("clear");
                    printf("how much lines?\n");
                    int num;
                    scanf("%d", &num);
                    struct Auto *car = NULL;
                    car = malloc(sizeof(struct Auto) * num);
                    fromF(car, num);

                    system("clear");
                    printf("sorting criterion\n");
                    printf("1 - model \n");
                    printf("2 - full_name \n");
                    printf("3 - distance \n");
                    printf("choose your hero: \n");
                    int form_sort;
                    scanf("%d", &form_sort);

                    system("clear");
                    printf("sorting direction\n");
                    printf("1 - direct \n");
                    printf("-1 - reverse \n");
                    int route;
                    scanf("%d", &route);

                    sort_comb(car, num, form_sort, route);
                    toF(car, num);
                    free(car);
                    break;
                }
                case 4:
                {
                    system("clear");
                    printf("how much lines?\n");
                    int num;
                    scanf("%d", &num);
                    struct Auto *car = NULL;
                    car = malloc(sizeof(struct Auto) * num);
                    fromF(car, num);

                    system("clear");
                    printf("sorting criterion\n");
                    printf("1 - model \n");
                    printf("2 - full_name \n");
                    printf("3 - distance \n");
                    printf("choose your hero: \n");
                    int form_sort;
                    scanf("%d", &form_sort);

                    system("clear");
                    printf("sorting direction\n");
                    printf("1 - direct \n");
                    printf("-1 - reverse \n");
                    int route;
                    scanf("%d", &route);

                    sort_sh(car, num, form_sort, route);
                    toF(car, num);
                    free(car);
                    break;
                }
                default:
                    break;
                }
            }
        }
        case 2:
        { // for prog 2
            int flag = 0;
            while (flag == 0)
            {

                printf("1 - exit \n");
                printf("2 - qsort \n");
                printf("3 - comb sort \n");
                printf("4 - shell sort \n");
                printf("choose your hero: \n");
                scanf("%d", &user_choice);

                if (user_choice == 0)
                {
                    flag = 1;
                }

                else if (user_choice == 2 || user_choice == 3 || user_choice == 4)
                {
                    int form_sort;
                    system("clear");
                    printf("sorting criterion\n");
                    printf("1 - model \n");
                    printf("2 - full_name \n");
                    printf("3 - distance \n");
                    printf("choose your hero: \n");
                    scanf("%d", &form_sort);
                    tm_sort(1, form_sort);
                }

                else
                {
                    system("clear");
                    printf("Error!\nNo such argument");
                    flag = 1;
                }
            }
        }
        }
        return 0;
    }
}
