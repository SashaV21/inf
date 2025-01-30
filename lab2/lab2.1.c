#include <stdio.h>
#include <math.h>

int main(){
    long double x;
    long long n;
    printf("Enter numbers from the interval [-1;1] and n: \n");
    if (!scanf("%Lf", &x) || !scanf("%lld", &n)) {
        printf("I'm waiting for numbers\n");
    }
    else {
        if(x > +1 || x < -1){
            printf("Numbers out of the interval");
            return 0;
        }
        long double sum = 1;
        long double f = 1; // (-1)^n
        long double c = 1; // (2n)!
        long double d = 1; // n!
        long double b = 1; //4^n
        long double a = 1; // x^n
        for(long long i = 1; i <= n; i++){
            f *= -1;
            d *= i; 
            c = c * 2 * i * (2 * i - 1);
            b *= 4;
            a *= x;                        
            sum += ((f * c) / ((1 - 2 * i) * d * d * b)) * a;  
        }
        long double p = sqrt(x + 1);
        printf("sqrt(x+1) =  %.16Lf\n", sum);
        printf("If use math.h sqrt(x+1) = %.16Lf", p);        
        }
    return 0;
}
