#include <stdio.h>
#include <math.h>


long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int x = 2;                 
    int n = 100;              
    double p = 0.02;          
    double q = 1 - p;         

    double m = n * p;        

    
    double P = (exp(-m) * pow(m, x)) / factorial(x);

    printf("The Probability is %lf\n", P);

    return 0;
}
