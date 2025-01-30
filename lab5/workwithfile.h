#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "struct.h"
#include <time.h>
#define RFACTOR (1.24733)

// ВВОД С КОНСОЛИ

void input(struct Auto *data, int num)
{
    char *a = NULL;
    char *number = NULL;
    char *name = NULL;
    for (int i = 0; i < num; i++)
    {
        printf("\n\n%d item", i);
        data[i].model = readline("\nmodel:\n ");
        data[i].full_name = readline("\nfullname:\n ");
        printf("\nkm: \n");
        scanf("%f", &data[i].distance);
    }
}

// ВЫВОД В КОНСОЛЬ

void output(struct Auto *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %s %s %f \n", data[i].model, data[i].full_name, data[i].distance);
    }
}

// ЗАПОЛНЕНИЕ СЛУЧАЙНЫМИ ДАННЫМИ

void randoml(struct Auto *data, int num)
{
    char *model = NULL;
    char *full_name = NULL;
    for (int i = 0; i < num; i++)
    {
        model = NULL;
        model = malloc(17);
        for (int j = 0; j < 16; j++)
        {
            model[j] = (char)(rand() % 26 + 'a');
        }
        model[17] = '\0';
        full_name = NULL;
        int range = rand() % 4 + 8;
        full_name = malloc(range + 1);
        for (int j = 0; j < (range); j++)
        {
            full_name[j] = (char)(rand() % 26 + 'a');
        }
        full_name[range] = '\0';
        float distance = rand() % 100000;
        distance = distance / 100;
        struct Auto example = {model, full_name, distance};
        data[i] = example;
    }
}

// ЧТЕНИЕ ИЗ ФАЙЛА

void fromF(struct Auto *data, int num)
{
    FILE *fil;
    fil = fopen("data.txt", "r");
    char model[100];
    char full_name[100];
    float distance = 0;
    for (int i = 0; i < num; i++)
    {
        fscanf(fil, "%s%s%f", &model, &full_name, &distance);
        char *fmodel = NULL;
        char *ffull_name = NULL;
        fmodel = malloc(strlen(model) + 1);
        ffull_name = malloc(strlen(full_name) + 1);
        memcpy(fmodel, model, strlen(model));
        memcpy(ffull_name, full_name, strlen(full_name));

        struct Auto example = {fmodel, ffull_name, distance};
        data[i] = example;
    }
}

// ЗАПИСЬ ДАННЫХ В ФАЙЛ

void toF(struct Auto *data, int n)
{
    FILE *fil;
    fil = fopen("todata.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fil, "%s\t\t%s\t\t%f\n", data[i].model, data[i].full_name, data[i].distance);
    }
    fclose(fil);
}

// ФУНКЦИЯ СРАВНЕНИЯ

int vs(struct Auto one, struct Auto two, int form_sort, int route)
{
    if (route == 1)
    {
        if (form_sort == 1)
        {
            return (strcmp(one.model, two.model));
        }
        else if (form_sort == 2)
        {
            return (strcmp(one.full_name, two.full_name));
        }
        else if (form_sort == 3)
        {
            if (one.distance > two.distance)
            {
                return (1);
            }
            else
            {
                return (-1);
            }
        }
    }

    if (route == -1)
    {
        if (form_sort == 1)
        {
            return (strcmp(one.model, two.model) * (-1));
        }
        else if (form_sort == 2)
        {
            return (strcmp(one.full_name, two.full_name) * (-1));
        }
        else if (form_sort == 3)
        {
            if (one.distance > two.distance)
            {
                return (-1);
            }
            else
            {
                return (1);
            }
        }
    }

    return 0;
}

// СОРТИРОВКА ШЕЛЛА

void sort_sh(struct Auto *data, int num, int form_sort, int route)
{
    for (int i = num / 1.5; i > 0; i /= 1.5)
    {
        for (int j = i; j < num; ++j)
        {
            for (int k = j - i; k >= 0 && vs(data[k], data[k + i], form_sort, route) > 0; k -= i)
            {
                struct Auto example = data[k];
                data[k] = data[k + i];
                data[k + i] = example;
            }
        }
    }
}

// СОРТИРОВКА РАСЧЕСКОЙ

void sort_comb(struct Auto *data, int num, int form_sort, int route)
{
    int gap = num;
    int swaps = 1;
    int i, j;

    while (gap > 1 || swaps)
    {
        gap = (int)(gap / RFACTOR);
        if (gap < 1)
            gap = 1;
        swaps = 0;
        for (i = 0; i < num - gap; ++i)
        {
            j = i + gap;
            if (vs(data[i], data[j], form_sort, route) > 0)
            {
                struct Auto example = data[i];
                data[i] = data[j];
                data[j] = example;
                swaps = 1;
            }
        }
    }
}

// ФУНКЦИИ СРАВНЕНИЯ ДЛЯ Qsort

int vs_11(struct Auto *a, struct Auto *b)
{
    return (strcmp(a->model, b->model));
}

int vs_21(struct Auto *a, struct Auto *b)
{
    return (strcmp(a->full_name, b->full_name));
}

int vs_31(struct Auto *a, struct Auto *b)
{
    return (a->distance - b->distance);
}

int vs_12(struct Auto *a, struct Auto *b)
{
    return (strcmp(a->model, b->model) * (-1));
}

int vs_22(struct Auto *a, struct Auto *b)
{
    return (strcmp(a->full_name, b->full_name) * (-1));
}

int vs_32(struct Auto *a, struct Auto *b)
{
    return (b->distance - a->distance);
}

// БЫСТРАЯ СОРТИРОВКА

void sort_q(struct Auto *data, int num, int form_sort, int route)
{
    if (route == 1)
    {
        if (form_sort == 1)
        {
            qsort(data, num, sizeof(struct Auto), vs_11);
        }
        else if (form_sort == 2)
        {
            qsort(data, num, sizeof(struct Auto), vs_21);
        }
        else if (form_sort == 3)
        {
            qsort(data, num, sizeof(struct Auto), vs_31);
        }
    }

    else if (route == -1)
    {
        if (form_sort == 1)
        {
            qsort(data, num, sizeof(struct Auto), vs_12);
        }
        else if (form_sort == 2)
        {
            qsort(data, num, sizeof(struct Auto), vs_22);
        }
        else if (form_sort == 3)
        {
            qsort(data, num, sizeof(struct Auto), vs_32);
        }
    }
}

// ТАЙМИРОВАНИЕ СОРТИРОВОК

void tm_sort(int type_sort, int form_sort)
{
    float tm_1;
    float tm_2;
    float tm;
    for (int num = 1000; num <= 10000; num += 1000)
    {
        struct Auto *data = malloc(num * sizeof(struct Auto));
        randoml(data, num);
        if (type_sort == 3)
        {
            tm_1 = clock();
            sort_comb(data, num, form_sort, 1);
        }
        else if (type_sort == 4)
        {
            tm_1 = clock();
            sort_sh(data, num, form_sort, 1);
        }
        else if (type_sort == 2)
        {
            tm_1 = clock();
            sort_q(data, num, form_sort, 1);
        }
        tm_2 = clock();
        tm = (tm_2 - tm_1) / CLOCKS_PER_SEC;
        printf("Lost time fot  %d elements = %f\n", num, tm);
        free(data);
    }
}
