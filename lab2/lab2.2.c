#include <stdio.h>
#include <math.h>

long double count(long double x);
long double abs1(long double x);

int main(){
    long double x;
    long double eps;
    printf("Enter numbers from the interval [-1;1] and eps: \n");
    if (!scanf("%Lf", &x) || !scanf("%Lf", &eps)) {
        printf("I'm waiting for numbers\n");
    }
    else {
        if(x > +1 || x < -1){
            printf("Numbers out of the interval\n");
            return 0;
        }
        int n = count(eps);
        long double sum = 1;
        long double f = 1; // (-1)^n
        long double c = 1; // (2n)!
        long double d = 1; // n!
        long double b = 1; //4^n
        long double a = 1; // x^n
        long double an = 1; //n-й член
        long double an_last; //n-1 член
        long double i = 1;
        do {
            an_last = an;
            f *= -1;
            d *= i;
            c = c * 2 * i * (2 * i - 1);
            b *= 4;
            a *=x;
            an = ((f * c) / ((1 - 2 * i) * d * d * b)) * a;
            sum += an;
            i++;
        } while (abs1(an_last - an) > eps);
        long double p = sqrt(x + 1);
        printf("sqrt(x+1) =  %.*Lf\n",n, sum);
        printf("If use math.h sqrt(x+1) = %.*Lf",n, p);
        }
    return 0;
}

long double count(long double x){
    int n;
    while(x < 1){
        n++;
        x *= 10;
    }
    return n;
}

long double abs1(long double x) {
    if (x < 0) {
        x = -1 * x;
    }
    return x;
}

