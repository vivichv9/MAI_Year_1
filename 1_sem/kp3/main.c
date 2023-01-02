#include <stdio.h>
#include <float.h>
#include <math.h>

int fact(int n) {
    int res = 1;

    for (int i = 1; i <= n; i++)
        res *= i;

    return res;
}

double func(double x) {
    return exp(x * x);
}

double taylor(double x, int n) {
    double res = 0;
    for (int i = 0; i <= n; i++)
        res += (((double) (pow(x, 2*i))) / ((double) fact(i)));

    return res;
}

int main() {
    double sum = 0.0;
    double a = 0.0;
    double b = 1.0;

    int n;
    scanf("%d", &n);
    printf("Machine epsilon: %Lg\n", LDBL_EPSILON);

    printf("   x             sum                function         iteration \n");

    double currentX;
    double step = (b - a) / (double) n;

    for (int i = 1; i <= n; ++i) {
        currentX = a + step * (double) i;
        sum = taylor(currentX, i);

        printf(" %.3f    %.16f   %.16f        %d       \n", currentX, sum, func(currentX), i);

        if (fabsl(func(currentX) - sum) < LDBL_EPSILON) break;
    }

    return 0;
}