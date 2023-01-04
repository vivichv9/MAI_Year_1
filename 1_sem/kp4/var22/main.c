#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

typedef double (*func)(double);

typedef struct result {
    double root;
    int iters;
    bool success;
} result;

double function(double x) {
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double iter(double x) {
    func f = function;
    return x - f(x) * -1;
}

result iterations_method(func iter_f, double a, double b) {
    double prev_x;
    double x = (a + b) / 2;
    double eps = LDBL_EPSILON;
    result res  = {0, 0, 0};

    do {
        res.success = fabs((iter_f(x + eps) - iter_f(x - eps)) / (2 * eps)) < 1;
        if (!res.success) return res;
        prev_x = x;
        x = iter_f(prev_x);
        res.iters++;
        res.root = x;
    } while (fabs(x - prev_x) > eps);

    return res;
}

void print_research(func iter_f, double a, double b) {
    result res = iterations_method(iter_f, a, b);

    printf(" x: %.16lf\n iterations: %d  ", res.root, res.iters);

}

int main() {

    print_research(iter, 0.0, 1.0);

    return 0;
}