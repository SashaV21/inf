#include <stdio.h>

int plus(int n);
void chek(int n, int m);

int main(){
    int m, n, m1, n1;
    printf("Enter two numbers:\n");
    if (!scanf("%d", &m) || !scanf("%d", &n)) {
        printf("I'm waiting for numbers\n");
    }
    else {
        n = plus(n);
        m = plus(m);
        printf("Indentical numbers: ");
        chek(m, n);
    }
    return 0;
}


int plus(int n){
    if(n < 0) {
         n *= (-1);
    }
    return n;
}


void chek(int n, int m){
    for (int i =  0; i < 10;i++) {
            int n1 = n;
            int m1 = m;
            while (m1 >= 10) {
                if (m1 % 10 == i) {
                    break;
                } else {
                    m1 /= 10;
                }
            }
            while (n1 >= 10) {
                if (n1 % 10 == i) {
                    break;
                } else {
                    n1 /= 10;
                }
            }
            if (n1 % 10 == i && m1 % 10 == i) {
                printf("%d ", i);
		n1/=10;
		m1/=10;
            }
        }
}
