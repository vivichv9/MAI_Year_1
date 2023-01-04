#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

typedef double (*func)(double);

typedef struct result {
    double answ;
    int iters;
    bool check;
} result;

double function(double x) {
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double iter(double x) {
    func f = function;
    return x - f(x) * -1;
}

result iterationsMethod(func iterF, double a, double b) {
    double prevX;
    double x = (a + b) / 2;
    double eps = LDBL_EPSILON;
    result res  = {0, 0, 0};

    do {
        res.check = fabs((iterF(x + eps) - iterF(x - eps)) / (2 * eps)) < 1;
        if (!res.check) return res;
        prevX = x;
        x = iterF(prevX);
        res.iters++;
        res.answ = x;
    } while (fabs(x - prevX) > eps);

    return res;
}

void printResearch(func iter_f, double a, double b) {
    result res = iterationsMethod(iter_f, a, b);

    printf(" x =  %.16lf\n number of iterations = %d  ", res.answ, res.iters);

}

int main() {

    printResearch(iter, 0.0, 1.0);

    return 0;
}