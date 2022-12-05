#include <stdio.h>
#include <assert.h>
#include <math.h>

long abs(long a){
    return a < 0 ? a*(-1) : a;
}

long func(long n){
    if (n != 0) {
        long a = 1, p = 10;
        n = abs(n);
        while (n > 0){
            a += p * (n % 10);
            p *= 10;
            n /= 10;
        }
        a += p;
        return a;
    } else{
        return 101;
    }
}

int check(long a){
    int count = 0;
    while (a > 0){
        a /= 10;
        count += 1;
    }
    return count;
}

void abs_test(){
    int n = 100;
    assert(abs(n) == 100);

    n = 0;
    assert(abs(n) == 0);

    n = -100;
    assert(abs(n) == 100);
}

void func_test(){
    int n = 100;
    assert(func(n) == 11001);

    n = 0;
    assert(func(n) == 101);

    n = -101;
    assert(abs(n) == -11011);
}

int main(){
    long n = 0;
    scanf("%ld", &n);
    if (check(n) <= 8){
        if (n < 0) {
            printf("%ld", func(n)*(-1));
        } else {
            printf("%ld", func(n));
        }
    } else{
        printf("1%ld1", n);
    }
}
