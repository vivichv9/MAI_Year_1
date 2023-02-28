#include <stdio.h>
#include <math.h>
#include <float.h>

double func(double x) {
    double res;
    res = tan(x) - 1.0/3.0 * pow(tan(x), 3) + 1.0/5.0 * pow(tan(x), 5) - 1.0/3.0;
    return res;
}

void solution(double a, double b, double eps) {
    double x = 0;
    int count = 0;

    if (func(a) * func(b) < 0) {
        printf("The convergence condition is met");

        while ((b - a) > eps) {
            x = (a + b) / 2.0;
            count++;

            if (func(a) * func(x) < 0) {
                b = x;
            } else {
                a = x;
            }
        }

        printf("x = %f\n", x);
        printf("number of iterations = %d", count);

    } else {
        printf("The convergence condition is not met");
    }

}

int main() {
    double eps = LDBL_EPSILON;
    double a = 0.0;
    double b = 0.8;

    solution(a, b, eps);

    return 0;
}