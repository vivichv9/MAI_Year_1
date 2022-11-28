#include <stdio.h>
#include <assert.h>

int abs(int a){
    return a < 0 ? a*(-1) : a;
}

int func(int n){
    if (n != 0) {
        int a = 1, p = 10;
        n = abs(n);
        while (n > 0){
            a += p * (n % 10);
            p *= 10;
            n /= 10;
        }
        a += p;
        return a;
    } else{
        return 11;
    }
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
    assert(func(n) == 11);

    n = -101;
    assert(abs(n) == -11011);
}

int main(){
    int n = 0;
    scanf("%d", &n);
    if (n < 0) {
        printf("%d", func(n)*(-1));
    } else {
        printf("%d", func(n));
    }
}
