#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>


void input(int *data, int num){
    for(int i = 0; i < num;i++){
        printf("Введите %d элемент\n", i+1);
        scanf("%d",&data[i]);
    }

}

void output(int *data, int num){
    for(int i = 0; i < num;i++){
        printf("%d ", data[i]);
    }
}

void input_index(int *data, int num, int index, int value){    
    for(int i = num - 1; i > index; i--){
        data[i] = data[i-1];
    }
    data[index] = value;
}



void del_index(int *data, int num, int index){    
    for(int i = index; i < num; i++){
        data[i] = data[i+1];
    }
}




int individual_v(int *data,int num,int *individual){
    int num_ind = 0;
    for(int i = 0;i < num - 1;i++){
        for(int j = i+1;j < num;j++){
            if(data[i] == data[j] && data[i] != 2147483647){
                num_ind++;
                individual = (int*) realloc(individual,sizeof(int) * num_ind);
                individual[num_ind - 1] = data[i];
                data[j] = 2147483647;
                
            }
        }
    }
    for(int i = num-1; i >= 0; i--){
        if(data[i] == 2147483647){
            del_index(data,num,i);
        }
    }
    

    return num_ind;



}
